#include "World.h"

#include <pspkernel.h>
#include <pspthreadman.h>

#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>
#include "../../Version.hpp"

#include "ChunkMesh.h"

using namespace Shadow;
using namespace Shadow::Utils;

Minecraft::Client::World* Minecraft::Client::g_World = new Minecraft::Client::World();

Minecraft::Client::World::World()
{
	timeData = new TickTime();
	timeData->time = 0;
	timeData->worldAge = 0;
	
}

Minecraft::Client::World::~World()
{
}

void Minecraft::Client::World::Init()
{
	sun = new Rendering::Sun();
	moon = new Rendering::Moon();
	sky = new Rendering::Sky();
	stars = new Rendering::Stars();
	clouds = new Rendering::Clouds();
	rmg = new Audio::RandomMusicGenerator();
	rmg->Init();

	tickUpdateThread = sceKernelCreateThread("TickUpdateThread", tickUpdate, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(tickUpdateThread, 0, 0);

	chunkMan = new Terrain::ChunkManager();
	chunkManagerThread = sceKernelCreateThread("ChunkManagementThread", chunkManagement, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(chunkManagerThread, 0, 0);
	lastLevel = lighting(0);

}

void Minecraft::Client::World::Cleanup()
{
	
	sceKernelTerminateDeleteThread(tickUpdateThread);
	rmg->Cleanup();
	delete rmg;
	delete sun;
	delete moon;
	delete sky;
	delete stars;
	delete clouds;
}

void Minecraft::Client::World::Update(float dt)
{
	fps = 1.0f / dt;
	rmg->FixedUpdate();


	while(!eventBus.empty()){
		Event* v = eventBus.front();
		
		switch(v->type){
			case EVENT_TYPE_BREAK:{

				BlockBreakEvent* b = (BlockBreakEvent*) v;
				mc::Vector3i pos = mc::Vector3i(b->breakPositionAbsolute.x, b->breakPositionAbsolute.y, b->breakPositionAbsolute.z);



				//Calculate chunk position & relative position
				mc::Vector3i chunkPos = mc::Vector3i(pos.x/16, pos.y/16, pos.z/16);
				mc::Vector3i relPos = mc::Vector3i(pos.x%16, pos.y%16, pos.z%16);

				Terrain::Chunk* ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z);
				ch->blocks[relPos.x][relPos.y][relPos.z] = {0, 0}; //Air

			

				ch->updateMesh(chunkMan);

				if(relPos.x == 0){
					ch = chunkMan->getChunk(chunkPos.x - 1, chunkPos.y, chunkPos.z);
					ch->updateMesh(chunkMan);
				}
				if(relPos.x == 15){
					ch = chunkMan->getChunk(chunkPos.x + 1, chunkPos.y, chunkPos.z);
					ch->updateMesh(chunkMan);
				}

				if(relPos.y == 0){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y - 1, chunkPos.z);
					ch->updateMesh(chunkMan);
				}
				if(relPos.y == 15){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y + 1, chunkPos.z);
					ch->updateMesh(chunkMan);
				}

				if(relPos.z == 0){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z - 1);
					ch->updateMesh(chunkMan);
				}
				if(relPos.z == 15){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z + 1);
					ch->updateMesh(chunkMan);
				}


				break;
			}

			case EVENT_TYPE_PLACE:{
				BlockPlaceEvent* b = (BlockPlaceEvent*) v;
				mc::Vector3i pos = mc::Vector3i(b->placePositionAbsolute.x, b->placePositionAbsolute.y, b->placePositionAbsolute.z);

				//Calculate chunk position & relative position
				mc::Vector3i chunkPos = mc::Vector3i(pos.x/16, pos.y/16, pos.z/16);
				mc::Vector3i relPos = mc::Vector3i(pos.x%16, pos.y%16, pos.z%16);

				Terrain::Chunk* ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z);

				if(ch->blocks[relPos.x][relPos.y][relPos.z].ID == 0){
					ch->blocks[relPos.x][relPos.y][relPos.z] = b->blk;
				}



				ch->updateMesh(chunkMan);

				if(relPos.x == 0){
					ch = chunkMan->getChunk(chunkPos.x - 1, chunkPos.y, chunkPos.z);
					ch->updateMesh(chunkMan);
				}
				if(relPos.x == 15){
					ch = chunkMan->getChunk(chunkPos.x + 1, chunkPos.y, chunkPos.z);
					ch->updateMesh(chunkMan);
				}

				if(relPos.y == 0){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y - 1, chunkPos.z);
					ch->updateMesh(chunkMan);
				}
				if(relPos.y == 15){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y + 1, chunkPos.z);
					ch->updateMesh(chunkMan);
				}

				if(relPos.z == 0){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z - 1);
					ch->updateMesh(chunkMan);
				}
				if(relPos.z == 15){
					ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z + 1);
					ch->updateMesh(chunkMan);
				}

				break;
			}

			default:{
				break;
			}
		}

		delete v;
		eventBus.pop();
	}
}

void Minecraft::Client::World::FixedUpdate()
{
	//TIME LOGIC

	timeData->time++;
	timeData->worldAge++;

	//Sun
	sky->Update(timeData->time);
	sun->Update( (float)(timeData->time % 24000) / 24000.0f * 360.0f);
	moon->Update((float)(timeData->time % 24000) / 24000.0f * 360.0f, timeData->worldAge);
	rmg->timeUntilNext--;

	if(lighting(timeData->time % 24000) != lastLevel){
		//Lighting update
		int newLevel = lighting(timeData->time % 24000);

		chunkMan->updateLightingAll(newLevel);
		Logging::debug("NEW LIGHT LEVEL " + newLevel);

		lastLevel = newLevel;
	}

}

void Minecraft::Client::World::Draw()
{
	//Load Projection Matrix
	sceGumMatrixMode(GU_PROJECTION);
	sceGumLoadMatrix(&p->projMatrix);
	
	//Load Matrix For Pre-Offset Drawing
	sceGumMatrixMode(GU_VIEW); 
	sceGumLoadMatrix(&p->viewPreMatrix);
	
	//Skybox
	sky->Draw();

	//Stars
	float starFade = 1.0f;

	if ( (timeData->time % 24000) >= 12000) {
		if (timeData->time % 24000 - 12000 < 2000) {
			starFade = (float)(timeData->time % 24000 - 12000) / 2000.0f;
		}
		else if (timeData->time % 24000 - 12000 >= 2000 && timeData->time % 24000 - 12000 < 10000) {
			starFade = 1.0f;
		}
		else {
			starFade = (float)(12000 - (timeData->time % 24000 - 12000)) / 2000.0f;
		}
	}
	else {
		starFade = 0.0f;
	}

	sceGumPushMatrix();
	sceGumRotateZ((float)(timeData->time % 24000) / 24000.0f * 2 * 3.14159);
	stars->Draw(starFade);
	sceGumPopMatrix();

	//Sun & Moon
	sun->Draw();
	moon->Draw();


	//Load Matrix For Offset Drawing
	sceGumMatrixMode(GU_VIEW);
	sceGumLoadMatrix(&p->viewMatrix);

	//Clouds
	clouds->Draw(p->getPosition(), timeData->time);
	
	//Draw stuff
	terrain_atlas->bindTexture(0, 0, true);
	
	for(const auto& [key, chnk] : chunkMan->getChunks()){
		if(chnk->hasMesh){
			chnk->Draw();
		}
	}


	g_RenderManager.SetOrtho();

	g_RenderManager.SetFontStyle(0.8f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_LEFT, 0);
	g_RenderManager.DebugPrint(0, 7, "%s v%s", GAME_NAME, (IS_SNAPSHOT) ? INTERNAL_SNAPSHOT : INTERNAL_VERSION);

	g_RenderManager.SetFontStyle(0.8f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_RIGHT, 0);
	g_RenderManager.DebugPrint(480, 7, "FPS: %d", (int)fps + 1);

}

int Minecraft::Client::World::tickUpdate(SceSize args, void* argp)
{
	while (true) {
		g_World->FixedUpdate();
		sceKernelDelayThread(1000 * 5); //1000 microseconds in a millisecond, and update 20 times per second, so 50ms
	}

	return 0;
}

int Minecraft::Client::World::chunkManagement(SceSize args, void* argp)
{
	mc::Vector3i last_pos = mc::Vector3i(0, -1, 0);
	while(true){
		mc::Vector3i center = mc::Vector3i((-g_World->p->getPosition().x) / 16, (g_World->p->getPosition().y) / 16, (-g_World->p->getPosition().z) / 16);

		if(center != last_pos){
		std::vector<mc::Vector3i> needed;
		needed.clear();
		std::vector<mc::Vector3i> excess;
		excess.clear();
		
		
		
		//Box bounds
		mc::Vector3i top = {center.x + 2, center.y+1, center.z + 2};
		mc::Vector3i bot = {center.x - 2, center.y-1, center.z - 2};

		
		for(int y = bot.y; y <= top.y && y < 16 && y >= 0; y++){
			for(int x = bot.x; x <= top.x; x++){
				for(int z = bot.z; z <= top.z; z++){
					needed.push_back(mc::Vector3i(x, y, z));
				}
			}
		}

		
		for(const auto& [key, chnk] : g_World->chunkMan->getChunks()){
			bool isNeeded = false;

			for(mc::Vector3i& v : needed){
				if(v == key){
					//Is needed
					isNeeded = true;
				}
			}

			if(!isNeeded){
				excess.push_back(key);
			}
		}

		
		//Get rid of excesses!

		for(mc::Vector3i& v : excess){
			g_World->chunkMan->unloadChunk(v.x, v.y, v.z);
			sceKernelDelayThread(1000 * 20);
		}
		excess.clear();


		sceKernelDelayThread(1000 * 20);
		
		for(mc::Vector3i& v : needed){
			if(!g_World->chunkMan->chunkExists(v.x, v.y, v.z)){
				g_World->chunkMan->loadChunkData(v.x, v.y, v.z);
				sceKernelDelayThread(1000*20);
			}
			
		}

		sceKernelDelayThread(1000*100);

		for(mc::Vector3i& v : needed){
			if(g_World->chunkMan->chunkExists(v.x, v.y, v.z) && !g_World->chunkMan->getChunk(v.x, v.y, v.z)->hasMesh){
				g_World->chunkMan->loadChunkMesh(v.x, v.y, v.z);
				sceKernelDelayThread(1000*20);
			}
			
		}

		last_pos = center;
		}
		sceKernelDelayThread(1000 * 500); //Check every 1/2 seonds

	}

	return 0;
}

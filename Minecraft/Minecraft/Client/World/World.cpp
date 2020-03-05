#include "World.h"

#include <pspkernel.h>
#include <pspthreadman.h>

#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>
#include "../../Version.hpp"
#include <sys/stat.h> 
#include <stdlib.h>
#include <iostream>
#include "ChunkMesh.h"
#include <pspsdk.h>
#include "../ME/me.h"
using namespace Shadow;
using namespace Shadow::Utils;

Minecraft::Client::World* Minecraft::Client::g_World = new Minecraft::Client::World();

Minecraft::Client::World::World()
{
	timeData = new TickTime();
	timeData->time = 0;
	timeData->worldAge = 0;
	genning = true;
}

Minecraft::Client::World::~World()
{
	Cleanup();
}

volatile struct me_struct* mei;
inline void *malloc_64(int size)
{
	int mod_64 {size & 0x3f};
	if (mod_64 != 0) size += 64 - mod_64;
	return((void *)memalign(64, size));
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


	// load up the images
	glbl_loadingscreen = new LoadingScreen();
    glbl_loadingscreen->options_bg = TextureUtil::LoadPng("assets/minecraft/textures/gui/options_background.png");
    glbl_loadingscreen->options_tile = new Sprite(glbl_loadingscreen->options_bg);
    glbl_loadingscreen->options_tile->alpha = 255;
    glbl_loadingscreen->options_tile->Scale(2.0f, 2.0f);
	sceKernelDelayThread(5000);
	glbl_loadingscreen->StartLoadingScreen();

	lastLevel = lighting(0);
	tickUpdateThread = sceKernelCreateThread("TickUpdateThread", tickUpdate, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(tickUpdateThread, 0, 0);


	mkdir( ("saves/" + Terrain::WorldProvider::worldName).c_str(), 0777);

	std::ifstream file("saves/" + Terrain::WorldProvider::worldName + "/level.dat");
	
	if(file.is_open()){
		file >> Terrain::WorldProvider::seed;
		mc::Vector3d position;

		file >> position.x >> position.y >> position.z;

		p->SetPosition(position);

 		file.close();
	}else{
		file.close();
		
		Save();
	}

	srand(time(0));
	Terrain::WorldProvider::noise = new FastNoise(Terrain::WorldProvider::seed);
	Terrain::WorldProvider::noise->SetFrequency(0.1);

	Terrain::bioMap.emplace(Terrain::BIOME_DEFAULT , Terrain::defaultBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_OCEAN , Terrain::oceanBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_RIVER , Terrain::riverBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_FOREST , Terrain::forestBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_WOODLAND_HILLS , Terrain::woodlandBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_FLOWER_FOREST , Terrain::flowerForestBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_BIRCH_FOREST , Terrain::birchForestBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_BIRCH_FOREST_HILLS , Terrain::birchForestBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_TALL_BIRCH_FOREST , Terrain::tallBirchForestBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_TALL_BIRCH_FOREST_HILLS , Terrain::tallBirchForestBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_DARK_FOREST_HILLS , Terrain::darkForestBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_JUNGLE , Terrain::jungleBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_JUNGLE_HILLS , Terrain::jungleBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_JUNGLE_EDGE , Terrain::jungleEdgeBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_TAIGA , Terrain::taigaBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Taiga_Hills , Terrain::taigaBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_Taiga_Mountains , Terrain::taigaBiomeMountains);
    Terrain::bioMap.emplace(Terrain::BIOME_Snowy_Taiga_Hills , Terrain::taigaSnowyBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_Snowy_Taiga_Mountains , Terrain::taigaSnowyBiomeMountains);
    Terrain::bioMap.emplace(Terrain::BIOME_Giant_Tree_Taiga , Terrain::giantTreeTaigaBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Giant_Tree_Taiga_Hills , Terrain::giantTreeTaigaBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_Giant_Spruce_Taiga , Terrain::giantSpruceTaigaBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Giant_Spruce_Taiga_Hills , Terrain::giantSpruceTaigaBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_Mushroom_Fields , Terrain::mushroomBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Mushroom_Fields_Shore , Terrain::mushroomShoreBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Swamp , Terrain::swampBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Swamp_Hills , Terrain::swampHillsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Savanna , Terrain::savannaBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Savanna_Plateau , Terrain::savannaPlateauBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Shattered_Savanna , Terrain::savannaShatteredBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Shattered_Savanna_Plateau , Terrain::savannaShatteredPlateauBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Plains , Terrain::plainsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Sunflower_Plains , Terrain::sunflowerPlainsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Desert , Terrain::desertBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Desert_Hills , Terrain::desertBiomeHills);
    Terrain::bioMap.emplace(Terrain::BIOME_Desert_Lakes , Terrain::desertLakesBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Snowy_Tundra , Terrain::snowyTundraBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Snow_Mountains , Terrain::snowyMountainsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Ice_Spikes , Terrain::iceSpikesBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Mountains , Terrain::mountainsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Wooded_Mountains , Terrain::woodedMountainsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Gravelly_Mountains , Terrain::gravelMountainsBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Badlands , Terrain::mesaBiome);
    Terrain::bioMap.emplace(Terrain::BIOME_Badlands_Plateau , Terrain::mesaPlateauBiome);


	


	genning = true;
	chunkMan = new Terrain::ChunkManager();
	

	crosshair = new Sprite("assets/minecraft/textures/misc/cross.png", 8, 8, 16, 16);

	animationTimer = 0;
	animationLavaFrame = 0;
	animationWaterFrame = 0;

	textureWaterAnimationId = TextureUtil::LoadPngTexturePack("blocks/water_still.png");
	textureLavaAnimationId = TextureUtil::LoadPngTexturePack("blocks/lava_still.png");
	animationLavaStep = true;

	int ret = pspSdkLoadStartModule("mediaengine.prx", PSP_MEMORY_PARTITION_KERNEL);

	mei = (volatile struct me_struct*)malloc_64(sizeof(struct me_struct*));
	mei = (volatile struct me_struct*)(reinterpret_cast< void * >( reinterpret_cast<u32>( (mei) ) | 0x40000000 ) );

	InitME(mei);
	sceKernelDcacheWritebackInvalidateAll();
	



	chunkManagerThread = sceKernelCreateThread("ChunkManagementThread", chunkManagement, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(chunkManagerThread, 0, 0);
}

void Minecraft::Client::World::Cleanup()
{

	Save();
	
	sceKernelTerminateDeleteThread(tickUpdateThread);
	sceKernelTerminateDeleteThread(chunkManagerThread);
	delete textureWaterAnimationId;
	delete textureLavaAnimationId;

	delete timeData;

	for(const auto& [key, chnk] : chunkMan->getChunks() ){
		chunkMan->unloadChunk(chnk->chunk_x, chnk->chunk_y, chnk->chunk_z);
	}

	rmg->Cleanup();
	delete rmg;
	delete sun;
	delete moon;
	delete sky;
	delete stars;
	delete clouds;
	delete crosshair;
	delete chunkMan;
	delete Terrain::WorldProvider::noise;
	Terrain::bioMap.clear();
}
#include <iostream>

void Minecraft::Client::World::Update(float dt)
{
	if(!genning){

	if(glbl_loadingscreen != NULL){
		glbl_loadingscreen->KillLoadingScreen();
		delete glbl_loadingscreen;
		glbl_loadingscreen = NULL;
	}

	fps = 1.0f / dt;
	rmg->FixedUpdate();

	for(const auto& [key, chnk] : chunkMan->getChunks() ){
		chnk->Update(dt);
	}

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
				ch->blocks[relPos.x][relPos.y][relPos.z].ID = 0; //Air
				ch->blocks[relPos.x][relPos.y][relPos.z].meta = 0; //Air

				ch->delta.push_back({mc::Vector3i(relPos.x, relPos.y, relPos.z), {0, 0}});
				
			

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
					ch->blocks[relPos.x][relPos.y][relPos.z].ID = b->blk.ID;
					ch->blocks[relPos.x][relPos.y][relPos.z].meta = b->blk.meta;
					ch->delta.push_back({mc::Vector3i(relPos.x, relPos.y, relPos.z), b->blk});
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

	animationTimer += dt;

    if(animationTimer >= 0.075){
        int waterFrameSize = 16;

        animationTimer = 0.0f; // zeroize timer
        animationWaterFrame += 1; // go to the next water frame

        if(animationWaterFrame >= textureWaterAnimationId->height/textureWaterAnimationId->width) // if all frames passed
        {
            animationWaterFrame = 0; // zeroize frames
        }

        if(animationLavaFrame >= textureLavaAnimationId->height/textureLavaAnimationId->width - 1)
        {
			animationLavaStep = false;
         }
        if(animationLavaFrame == 0)
        {
            animationLavaStep = true;
        }
        if(animationLavaStep == true)
        {
            animationLavaFrame += 1;
        }
        else
        {
            animationLavaFrame -= 1;
        }
		

		
        for(int i = 0; i < waterFrameSize; i++)
        {
            for(int j = 0; j < waterFrameSize; j++)
            {
                // copy each water pixel from water_still.png to terrain.png
                terrain_atlas->setColour(			waterFrameSize*29+i,
                                                    waterFrameSize*13+j,
                                                      textureWaterAnimationId->getRed(i,animationWaterFrame*waterFrameSize+j),
                                                      textureWaterAnimationId->getGreen(i,animationWaterFrame*waterFrameSize+j),
                                                      textureWaterAnimationId->getBlue(i,animationWaterFrame*waterFrameSize+j),
                                                      184);
                // same to lava
                terrain_atlas->setColour(			waterFrameSize*30+i,
                                                    waterFrameSize*13+j,
                                                      textureLavaAnimationId->getRed(i,animationLavaFrame*waterFrameSize+j),
                                                      textureLavaAnimationId->getGreen(i,animationLavaFrame*waterFrameSize+j),
                                                      textureLavaAnimationId->getBlue(i,animationLavaFrame*waterFrameSize+j),
                                                      255);
            }
        }
    }
	}
	
}

void Minecraft::Client::World::FixedUpdate()
{
	//TIME LOGIC

	timeData->time++;
	timeData->worldAge++;
	
	sky->Update(timeData->time);
	sun->Update( (float)(timeData->time % 24000) / 24000.0f * 360.0f);
	moon->Update((float)(timeData->time % 24000) / 24000.0f * 360.0f, timeData->worldAge);
	rmg->timeUntilNext--;

	if(lighting(timeData->time % 24000) != lastLevel){
		//Lighting update
		int newLevel = lighting(timeData->time % 24000);

		chunkMan->updateLightingAll(newLevel, lastLevel);

		lastLevel = newLevel;
	}

}

void Minecraft::Client::World::Save(){

	std::ofstream file("saves/" + Terrain::WorldProvider::worldName + "/level.dat");
	
	file << Terrain::WorldProvider::seed << std::endl;
	mc::Vector3d position = p->getPosition(); 
	file << position.x << " " << position.y << " " << position.z;
	file.close();


	for(const auto& [key, chnk] : chunkMan->getChunks()){
		chnk->save();
	}
}
void dcache_wbinv_all()
{
   for(int i = 0; i < 8192; i += 64)
   {
      __builtin_allegrex_cache(0x14, i);
      __builtin_allegrex_cache(0x14, i);
   }
}
void Minecraft::Client::World::Draw()
{
	if(!genning){
		g_RenderManager.StartFrame(0, 0, 0);

	
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
	

	sceGuEnable(GU_FOG);

	float finalFog = 1.0 - starFade * 0.6f;

	sceGuFog(0.8f, 192.f, GU_COLOR(finalFog, finalFog, finalFog, 1.0));

	//Draw stuff
	terrain_atlas->bindTexture(0, 0, true);
	
	for(const auto& [key, chnk] : chunkMan->getChunks()){
		if(chnk->hasMesh){
			if(p->getFrustum().isBoxInFrustum(chnk->m_aabb)){
				chnk->Draw();
			}
		}
	}
	for(const auto& [key, chnk] : chunkMan->getChunks()){
		if(chnk->hasMesh){
			if(p->getFrustum().isBoxInFrustum(chnk->m_aabb)){
				chnk->DrawTrans();
			}
		}
	}

	sceGuDisable(GU_FOG);

	g_RenderManager.SetOrtho();

	g_RenderManager.DrawSetInverseColors();
	
	sceGuEnable(GU_BLEND);
	crosshair->SetPosition(240, 136);
	crosshair->Draw();


	g_RenderManager.DrawSetDefaultColors();

	g_RenderManager.SetFontStyle(0.8f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_LEFT, 0);
	g_RenderManager.DebugPrint(0, 7, "%s v%s", GAME_NAME, (IS_SNAPSHOT) ? INTERNAL_SNAPSHOT : INTERNAL_VERSION);
	g_RenderManager.DebugPrint(0, 14, "%5.2f %5.2f %5.2f", p->getPosition().x + 32000, p->getPosition().y, p->getPosition().z + 32000);

	g_RenderManager.SetFontStyle(0.8f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_RIGHT, 0);
	g_RenderManager.DebugPrint(480, 7, "FPS: %d", (int)fps + 1);

		g_RenderManager.EndFrame();
	}
}

int Minecraft::Client::World::tickUpdate(SceSize args, void* argp)
{
	while (true) {
		g_World->FixedUpdate();
		sceKernelDelayThread(1000 * 50); //1000 microseconds in a millisecond, and update 20 times per second, so 50ms
	}

	return 0;
}

int Minecraft::Client::World::ChunkMan2(int gWorld){
	World* g_world = (World*)gWorld;
	g_world->genning = false;
	return 0;
}

int Minecraft::Client::World::chunkManagement(SceSize args, void* argp)
{	
	mc::Vector3i last_pos = mc::Vector3i(0, -1, 0);
	while(true){

		mc::Vector3i center = mc::Vector3i((-g_World->p->getPosition().x) / 16, (g_World->p->getPosition().y) / 16, (-g_World->p->getPosition().z) / 16);
		
		if(center != last_pos){
		
		//CPU STUFF!
		std::vector<mc::Vector3i> needed;
		needed.clear();
		std::vector<mc::Vector3i> excess;
		excess.clear();
		//Box bounds
		mc::Vector3i top = {center.x + 1.5f, center.y+1, center.z + 1.5f};
		mc::Vector3i bot = {center.x - 1.5f, center.y-1, center.z - 1.5f};
		for(int y = bot.y; y <= top.y && y < 17 && y >= -1; y++){
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

		//CPU ONLY!
		for(mc::Vector3i& v : excess){
			g_World->chunkMan->unloadChunk(v.x, v.y, v.z);
			if(!g_World->genning){
				sceKernelDelayThread(16 * 1000);
			}
  		}
		excess.clear();

		//ME
		for(mc::Vector3i& v : needed){
			if(!g_World->chunkMan->chunkExists(v.x, v.y, v.z)){
				Terrain::Chunk* c = new Terrain::Chunk();
        		c->chunk_x = v.x;
        		c->chunk_y = v.y;
        		c->chunk_z = v.z;

        		//ME
				c->m_aabb.update({c->chunk_x * CHUNK_SIZE, c->chunk_y * CHUNK_SIZE, c->chunk_z * CHUNK_SIZE});


				#ifndef ME_ENABLED
					Terrain::WorldProvider::generate(c);
				#else

				Terrain::me_generator_struct str;

				int rX = c->chunk_x * CHUNK_SIZE;
				int rY = c->chunk_y * CHUNK_SIZE;
				int rZ = c->chunk_z * CHUNK_SIZE;

				for(int x = 0; x < CHUNK_SIZE; x++){
					for(int z = 0; z < CHUNK_SIZE; z++){
						str.biomeMap[x][z] = Terrain::getBiome(rX + x, rZ + z);
					}
				}
				if(!g_World->genning)
					sceKernelDelayThread(20 * 1000);

        		for(int x = 0; x < CHUNK_SIZE; x++){
            		for(int z = 0; z < CHUNK_SIZE; z++){
						Terrain::NoiseParameters profile = Terrain::bioMap[str.biomeMap[x][z]].params;
            	    	str.heightMap[x][z] = Terrain::getHeight(rX + x, rZ + z, profile);
            		}
        		}

				if(!g_World->genning)
					sceKernelDelayThread(20 * 1000);
				
				str.c = c;
				str.bioMap = Terrain::bioMap;
				str.seed = Terrain::WorldProvider::seed;


				sceKernelDcacheWritebackInvalidateAll();
				BeginME(mei, (int)(&Terrain::WorldProvider::GenerateME), (int)(&str), -1, 0, -1, 0);
				while(!mei->done){
					sceKernelDelayThread(6 * 1000);
				} 
				sceKernelDcacheWritebackInvalidateAll();

				for(int x = 0; x < CHUNK_SIZE; x++){
					for(int y = 0; y < CHUNK_SIZE; y++){
						for(int z = 0; z < CHUNK_SIZE; z++){	
							makeCavesOres(c, x, rX, y, rY, z, rZ, str.heightMap[x][z]);
						}
					}
				}

				if(!g_World->genning)
					sceKernelDelayThread(20 * 1000);

				for(int x = 0; x < CHUNK_SIZE; x++){
					for(int z = 0; z < CHUNK_SIZE; z++){
						if( (str.heightMap[x][z] + 3) / CHUNK_SIZE == rY / CHUNK_SIZE ){
							if(c->blocks[x][str.heightMap[x][z] + 2 - rY][z].ID != 0){
								makeFoliage(c, x, rX, str.heightMap[x][z] + 3 - rY, rY, z, rZ, Terrain::bioMap[str.biomeMap[x][z]]);
							}
						}

					}
				}

				#endif

        		g_World->chunkMan->getChunks().emplace(v, std::move(c));
				if(!g_World->genning)
					sceKernelDelayThread(16 * 1000);
			}
		}


		
		for(mc::Vector3i& v : needed){
			// g_World->chunkMan->loadChunkData2(v.x, v.y, v.z);
			
			if(!g_World->genning)
				sceKernelDelayThread(16 * 1000);
		}

		//CPU ONLY
		for(mc::Vector3i& v : needed){
			g_World->chunkMan->loadChunkData3(v.x, v.y, v.z);
			if(!g_World->genning)
				sceKernelDelayThread(16 * 1000);
		}


		for(mc::Vector3i& v : needed){
			if(g_World->chunkMan->chunkExists(v.x, v.y, v.z) && !g_World->chunkMan->getChunk(v.x, v.y, v.z)->hasMesh){
				g_World->chunkMan->loadChunkMesh(v.x, v.y, v.z);
			
				if(!g_World->genning)
					sceKernelDelayThread(16 * 1000);
				
			}
		}


		last_pos = center;
		}
		g_World->genning = false;
		sceKernelDelayThread(50 * 1000);
	}

	return 0;
}

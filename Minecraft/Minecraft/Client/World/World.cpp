#include "World.h"

#include <pspkernel.h>
#include <pspthreadman.h>
#include "../../Common/Options.hpp"
#include <Utilities/Logger.h>
#include "../../Version.hpp"
#include <sys/stat.h> 
#include <stdlib.h>
#include <iostream>
#include "ChunkMesh.h"
#include <pspsdk.h>
#include <melib.h>
#include <Utilities/Input.h>

Stardust::Graphics::Texture* Minecraft::Client::terrain_atlas = NULL;

Minecraft::Client::World* Minecraft::Client::g_World = new Minecraft::Client::World();

Minecraft::Client::World::World()
{
	timeData = new TickTime();
	timeData->time = 0;
	timeData->worldAge = 0;
	genning = true;
	gameMode = 1;
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
	BlockData::InstancePointer()->loadBlockData();
	killReceived = false;
	readyForKill = false;
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



	lastLevel = 0;
	tickUpdateThread = sceKernelCreateThread("TickUpdateThread", tickUpdate, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(tickUpdateThread, 0, 0);

	
	mkdir( ("saves/" + Terrain::WorldProvider::worldName).c_str(), 0777);

	std::ifstream file("saves/" + Terrain::WorldProvider::worldName + "/level.dat");
	if(file.is_open()){
		file >> Terrain::WorldProvider::seed;
		glm::vec3 position;

		file >> position.x >> position.y >> position.z;

		file >> gameMode;
		file >> timeData->time;
		file >> timeData->worldAge;

		p->SetPosition(position);

 		file.close();
	}else{
		file.close();
		
		Save();
	}
	
	if(file.is_open()){
		file >> Terrain::WorldProvider::seed;
		glm::vec3 position;

		file >> position.x >> position.y >> position.z;

		file >> gameMode;
		file >> timeData->time;
		file >> timeData->worldAge;

		p->SetPosition(position);

 		file.close();
	}else{
		file.close();
		
		Save();
	}

	handleGM();
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
	tUpReady = false;
	cUpReady = false;
	chunkMan = new Terrain::ChunkManager();
	

	crosshair = new Sprite(TextureUtil::LoadPng("assets/minecraft/textures/misc/cross.png"), 8, 8, 16, 16);

	animationTimer = 0;
	animationLavaFrame = 0;
	animationWaterFrame = 0;

	textureWaterAnimationId = TextureUtil::LoadPng("assets/minecraft/textures/blocks/water_still.png");
	textureLavaAnimationId = TextureUtil::LoadPng( "assets/minecraft/textures/blocks/lava_still.png");
	animationLavaStep = true;


	#ifdef ME_ENABLED
		J_Init(false);
	#endif

	
	Stardust::Utilities::LoadConfiguration("config.json");


		sceGuEnable(GU_TEXTURE);
    sceGuEnable(GU_ALPHA_TEST);
    sceGuEnable(GU_BLEND);
    
    g_RenderCore.BeginCommands();
    g_RenderCore.Clear();
    
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 9; y++){
            glbl_loadingscreen->options_tile->RGB(64.0f, 64.0f, 64.0f);
            glbl_loadingscreen->options_tile->SetPosition(x * 32, y * 32);
            glbl_loadingscreen->options_tile->Draw();
        }
    }

    g_RenderCore.SetFontStyle(1.0f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0);
    g_RenderCore.DebugPrint(240, 136, Minecraft::Common::g_TranslationOBJ.getText("menu.generatingTerrain").c_str());

    g_RenderCore.EndCommands();
	

	chunkManagerThread = sceKernelCreateThread("ChunkManagementThread", chunkManagement, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(chunkManagerThread, 0, 0);

	frameTimer = 0;
	fps = 0;
	frameCounter = 0;
}

void Minecraft::Client::World::Cleanup()
{

	#ifdef ME_ENABLED
		J_Cleanup();
	#endif

	Save();
	
	sceKernelTerminateDeleteThread(tickUpdateThread);
	sceKernelTerminateDeleteThread(chunkManagerThread);
	delete textureWaterAnimationId;
	delete textureLavaAnimationId;

	delete timeData;


	for(const auto& [key, chnk] : chunkMan->getChunks() ){
		if(chunkMan->chunkExists(key.x, key.y, key.z))
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
	frameTimer += dt;
	frameCounter++;

	if(frameTimer >= 1){
		fps = frameCounter;
		frameTimer = 0;
		frameCounter = 0;
	}

	if(!genning){

	if(glbl_loadingscreen != NULL){
		glbl_loadingscreen->KillLoadingScreen();
		delete glbl_loadingscreen;
		glbl_loadingscreen = NULL;
	}

	rmg->FixedUpdate();


	p->Update(dt);	

	for(const auto& [key, chnk] : chunkMan->getChunks() ){
		chnk->Update(dt);
	}

	while(!eventBus.empty()){
		Event* v = eventBus.front();

		
		switch(v->type){
			case EVENT_TYPE_BREAK:{
				if(g_World->gameMode <= 1 || g_World->gameMode == 4){

				BlockBreakEvent* b = (BlockBreakEvent*) v;
				glm::vec3 pos = glm::vec3(b->breakPositionAbsolute.x, b->breakPositionAbsolute.y, b->breakPositionAbsolute.z);



				//Calculate chunk position & relative position
				glm::vec3 chunkPos = glm::vec3((int)pos.x/16, (int)pos.y/16, (int)pos.z/16);
				glm::vec3 relPos = glm::vec3((int)pos.x%16, (int)pos.y%16, (int)pos.z%16);

				chunkMan->setBlock(b->breakPositionAbsolute.x, b->breakPositionAbsolute.y, b->breakPositionAbsolute.z, {0, 0});
				Terrain::Chunk* ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z);
				
				bool check = false;
				for(int i = 0; i < ch->delta.size(); i++){
					if(ch->delta.at(i).position == glm::vec3(relPos.x, relPos.y, relPos.z)) {
						check = true;
						ch->delta.at(i) = {glm::vec3(relPos.x, relPos.y, relPos.z), {0,0}};
					}
				}
				if(!check){
					ch->delta.push_back({glm::vec3(relPos.x, relPos.y, relPos.z), {0, 0}});
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
				}


				break;
			}

			case EVENT_TYPE_PLACE:{
				if(g_World->gameMode <= 1 || g_World->gameMode == 4){
					BlockPlaceEvent* b = (BlockPlaceEvent*) v;
				glm::vec3 pos = glm::vec3(b->placePositionAbsolute.x, b->placePositionAbsolute.y, b->placePositionAbsolute.z);

				//Calculate chunk position & relative position
				glm::vec3 chunkPos = glm::vec3((int)pos.x/16, (int)pos.y/16, (int)pos.z/16);
				glm::vec3 relPos = glm::vec3((int)pos.x%16, (int)pos.y%16, (int)pos.z%16);

				Terrain::Chunk* ch = chunkMan->getChunk(chunkPos.x, chunkPos.y, chunkPos.z);
				if(ch->blocks[(int)relPos.x][(int)relPos.y][(int)relPos.z].ID == 0){	
					chunkMan->setBlock(b->placePositionAbsolute.x, b->placePositionAbsolute.y, b->placePositionAbsolute.z, b->blk);
					ch->delta.push_back({glm::vec3(relPos.x, relPos.y, relPos.z), b->blk});

					bool check = false;
				for(int i = 0; i < ch->delta.size(); i++){
					if(ch->delta.at(i).position == glm::vec3(relPos.x, relPos.y, relPos.z)) {
						check = true;
						ch->delta.at(i) = {glm::vec3(relPos.x, relPos.y, relPos.z), b->blk};
					}
				}
				if(!check){
					ch->delta.push_back({glm::vec3(relPos.x, relPos.y, relPos.z), b->blk});
				}

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


void Minecraft::Client::World::handleGM(){
	if(gameMode != 1 && gameMode != 3){
		p->toggleFly();
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
	glm::vec3 position = p->getPosition(); 
	file << position.x << " " << position.y << " " << position.z << std::endl;


	file << gameMode << std::endl;
	file << timeData->time << std::endl;
	file << timeData->worldAge << std::endl;

	file.close();


	for(const auto& [key, chnk] : chunkMan->getChunks()){
		chnk->save();
	}
	
}

void Minecraft::Client::World::Draw()
{
	if(!genning){
	g_RenderCore.BeginCommands();
	g_RenderCore.Clear();

	
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
	if(Common::g_OptionsManager.options.renderClouds != 0){
		clouds->Draw(p->getPosition(), timeData->time);
	}
	

	sceGuEnable(GU_FOG);

	float finalFog = 1.0 - starFade * 0.6f;

	sceGuFog(0.8f, 192.f, GU_COLOR(finalFog, finalFog, finalFog, 1.0));

	//Draw stuff
	terrain_atlas->bindTexture(0, 0, true);
	
	for(const auto& [key, chnk] : chunkMan->getChunks()){
		if(chnk->hasMesh){
			chnk->Draw();
			
		}
	}
	for(const auto& [key, chnk] : chunkMan->getChunks()){
		if(chnk->hasMesh){
			chnk->DrawTrans();
			
		}
	}


	sceGuDisable(GU_FOG);

	sceGumMatrixMode(GU_PROJECTION);
	sceGumLoadIdentity();
	sceGumOrtho(0, 480, 272, 0, -30, 30);

	sceGuBlendFunc(GU_ABS, GU_ONE_MINUS_SRC_ALPHA, GU_SRC_ALPHA, 0, 0);
	
	sceGuEnable(GU_BLEND);
	crosshair->SetPosition(240, 136);
	crosshair->Draw();

	sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);

	g_RenderCore.SetFontStyle(0.8f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_LEFT, 0);
	g_RenderCore.DebugPrint(0, 7, "%s v%s", GAME_NAME, (IS_SNAPSHOT) ? INTERNAL_SNAPSHOT : INTERNAL_VERSION);
	g_RenderCore.DebugPrint(0, 14, "%5.2f %5.2f %5.2f", p->getPosition().x + 32000, p->getPosition().y, p->getPosition().z + 32000);

	g_RenderCore.SetFontStyle(0.8f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_RIGHT, 0);
	g_RenderCore.DebugPrint(480, 7, "FPS: %d", (int)fps + 1);

		g_RenderCore.EndCommands();
	}else{
	}
}

int Minecraft::Client::World::tickUpdate(SceSize args, void* argp)
{
	while (!g_World->killReceived) {
		g_World->FixedUpdate();
		sceKernelDelayThread(1000 * 50); //1000 microseconds in a millisecond, and update 20 times per second, so 50ms
	}

	g_World->tUpReady = true;
	g_World->readyForKill = g_World->cUpReady && g_World->tUpReady;
	return 0;
}


int Minecraft::Client::World::chunkManagement(SceSize args, void* argp)
{	
	glm::vec3 last_pos = glm::vec3(0, -1, 0);
	while(!g_World->killReceived){

		glm::vec3 center = glm::vec3((-g_World->p->getPosition().x) / 16, (g_World->p->getPosition().y) / 16, (-g_World->p->getPosition().z) / 16);
		
		if(center != last_pos){
		
		//CPU STUFF!
		std::vector<mc::Vector3i> needed;
		needed.clear();
		std::vector<mc::Vector3i> excess;
		excess.clear();
		//Box bounds
		mc::Vector3i top = {center.x + (float)Common::g_OptionsManager.options.renderDistance / 3.0f, center.y+1, center.z + (float)Common::g_OptionsManager.options.renderDistance / 3.0f};
		mc::Vector3i bot = {center.x - (float)Common::g_OptionsManager.options.renderDistance / 3.0f, center.y-1, center.z - (float)Common::g_OptionsManager.options.renderDistance / 3.0f};
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
			
			sceKernelDelayThread(4 * 1000);
			
  		}
		excess.clear();

		//ME OPTIMIZABLE
		for(mc::Vector3i& v : needed){
			if(!g_World->chunkMan->chunkExists(v.x, v.y, v.z)){
				g_World->chunkMan->loadChunkData(v.x, v.y, v.z);
				sceKernelDelayThread(4 * 1000);
			}
		}


		//ME OPTIMIZABLE
		for(mc::Vector3i& v : needed){			
			g_World->chunkMan->loadChunkData2(v.x, v.y, v.z);
			sceKernelDelayThread(4 * 1000);
		}

		//CPU ONLY
		for(mc::Vector3i& v : needed){
			g_World->chunkMan->loadChunkData3(v.x, v.y, v.z);
			sceKernelDelayThread(4 * 1000);
		}

		//ME OPTIMIZABLE
		for(mc::Vector3i& v : needed){
			if(g_World->chunkMan->chunkExists(v.x, v.y, v.z) && !g_World->chunkMan->getChunk(v.x, v.y, v.z)->hasMesh){
				g_World->chunkMan->loadChunkMesh(v.x, v.y, v.z);
			
			sceKernelDelayThread(4 * 1000);
				
			}
		}


		last_pos = center;

		#ifdef ME_ENABLED
			J_DispatchJobs(0.0f);
		#endif

		}
		g_World->genning = false;
		sceKernelDelayThread(16 * 1000);
	}

	g_World->cUpReady = true;
	g_World->readyForKill = g_World->cUpReady && g_World->tUpReady;

	return 0;
}

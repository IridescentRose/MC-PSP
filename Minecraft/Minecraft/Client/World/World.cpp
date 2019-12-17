#include "World.h"

#include <pspkernel.h>
#include <pspthreadman.h>

#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>

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

	chnk = new Terrain::Chunk();
	chnk->generateData();
	chnk->generateMesh();
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
	rmg->FixedUpdate();
}

void Minecraft::Client::World::Draw(Player* p)
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

	//Clouds
	clouds->Draw(p->getPosition(), timeData->time);

	//Load Matrix For Offset Drawing
	sceGumMatrixMode(GU_VIEW);
	sceGumLoadMatrix(&p->viewMatrix);
	
	//Draw stuff
	terrain_atlas->bindTexture();
	chnk->Draw();
}

int Minecraft::Client::World::tickUpdate(SceSize args, void* argp)
{
	while (true) {
		g_World->FixedUpdate();
		sceKernelDelayThread(1000 * 50); //1000 microseconds in a millisecond, and update 20 times per second, so 50ms
	}

	return 0;
}

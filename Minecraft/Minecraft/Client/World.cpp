#include "World.h"

#include <pspkernel.h>
#include <pspthreadman.h>

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

	tickUpdateThread = sceKernelCreateThread("TickUpdateThread", tickUpdate, 0x18, 0x10000, THREAD_ATTR_VFPU | THREAD_ATTR_USER, NULL);
	sceKernelStartThread(tickUpdateThread, 0, 0);
	
}

void Minecraft::Client::World::Cleanup()
{
	sceKernelTerminateDeleteThread(tickUpdateThread);
	delete sun;
	delete moon;
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

	sun->Draw();
	moon->Draw();
	//Moon

	//Clouds

	//Weather

	//Load Matrix For Offset Drawing
	sceGumMatrixMode(GU_VIEW);
	sceGumLoadMatrix(&p->viewMatrix);

	//Draw stuff
}

int Minecraft::Client::World::tickUpdate(SceSize args, void* argp)
{
	while (true) {
		g_World->FixedUpdate();
		sceKernelDelayThread(1000 * 5); //1000 microseconds in a millisecond, and update 20 times per second, so 50ms
	}

	return 0;
}

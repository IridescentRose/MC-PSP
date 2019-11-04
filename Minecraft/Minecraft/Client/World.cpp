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
	tickUpdateThread = sceKernelCreateThread("TickUpdateThread", tickUpdate, 0x18, 0x10000, 0, NULL);
	sun = new Rendering::Sun();
}

void Minecraft::Client::World::Cleanup()
{
	sceKernelTerminateDeleteThread(tickUpdateThread);
	delete sun;
}

void Minecraft::Client::World::Update(float dt)
{
}

void Minecraft::Client::World::FixedUpdate()
{
	//TIME LOGIC
	if(timeData->time > 0){
		timeData->time++;
	}
	
	timeData->worldAge++;

	//Sun
	sun->Update( (float)(timeData->time % 24000) / 24000.0f * 360.0f);
}

void Minecraft::Client::World::Draw()
{
	sun->Draw();
}

int Minecraft::Client::World::tickUpdate(SceSize args, void* argp)
{
	while (true) {
		g_World->FixedUpdate();
		sceKernelDelayThread(1000 * 50); //1000 microseconds in a millisecond, and update 20 times per second, so 50ms
	}

	return 0;
}

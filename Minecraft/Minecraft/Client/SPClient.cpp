#include "SPClient.hpp"
#include <sstream>
#include <Graphics/RendererCore.h>
#include "World/World.h"
#include <iostream>
#include <Utilities/Input.h>
using namespace Stardust::Graphics;
using namespace Stardust::Utilities;


namespace Minecraft::Client {

	SPClient::SPClient() {
		g_World = new World();
	}
	SPClient::~SPClient() {

	}

	void SPClient::Init() {
		updateTimer = Stardust::Utilities::Timer();
		
		updateTimer.reset();
		player = new Player();
		player->Init({ -32000.0f, 69.0f, -32000.0f}, 0, 0);

		g_World->p = player;

	}
	void SPClient::Enter() {

		g_World->Init();
	}
	void SPClient::CleanUp() {

		g_World->Save();
		delete g_World;
		delete player;
	}

	void SPClient::Pause() {

	}
	void SPClient::Resume() {

	}

	void SPClient::Update(StateManager* sManager) {
		//Get Delta Time
		float dt = updateTimer.deltaTime();

		int fps = 1.0f / dt;
		g_World->Update(dt);

		
		if(KeyPressed(PSP_CTRL_START)){
			g_World->Save();
			sceKernelExitGame();
		}
		
	}
	void SPClient::Draw(StateManager* sManager) {

		g_World->Draw();
	}


}
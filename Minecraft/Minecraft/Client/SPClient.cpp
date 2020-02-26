#include "SPClient.hpp"
#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>
#include <sstream>
#include <Shadow/Graphics/RenderManager.h>

using namespace Shadow::Graphics;


namespace Minecraft::Client {

	SPClient::SPClient() {

	}
	SPClient::~SPClient() {

	}

	void SPClient::Init() {
		updateTimer = Timer();
		
		updateTimer.reset();
		player = new Player();
		player->Init({ -32000, 69.0f, -32000}, 0, 0);
		
		//CREATIVE
		player->toggleFly();

		g_World->p = player;

	}
	void SPClient::Enter() {

		g_World->Init();
		u32 ramFree = System::freeMemory();
		float ram = ((float)ramFree) / 1024.0f / 1024.0f;
		std::ostringstream os;
		os << ram;
		std::string s(os.str());
		Logging::log("RAM AVAILABLE FOR CLIENT: " + s, Logging::LOGGER_LEVEL_TRACE);

		Logging::logging_level = Logging::LOGGER_LEVEL_INFO;
		//THIS IS WHERE WE HAVE FREE RAM TO LOAD!
		g_World->Save();
	}
	void SPClient::CleanUp() {

	}

	void SPClient::Pause() {

	}
	void SPClient::Resume() {

	}

	void SPClient::Update(StateManager* sManager) {
		//Get Delta Time
		float dt = updateTimer.deltaTime();

		int fps = 1.0f / dt;
		player->Update(dt);	
		g_World->Update(dt);
		
	}
	void SPClient::Draw(StateManager* sManager) {
		g_AudioManager.Update();
		
		g_World->Draw();
	}


}
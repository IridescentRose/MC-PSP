#include "GameClient.hpp"
#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>
#include <sstream>

namespace Minecraft::Client {

	ClientState::ClientState() {

	}
	ClientState::~ClientState() {

	}

	void ClientState::Init() {
		//CONNECT TEST, DON'T START ALLOCATING RAM UNNECESSARILY!

	}
	void ClientState::Enter() {
		u32 ramFree = System::freeMemory();
		float ram = ((float)ramFree) / 1024.0f / 1024.0f;
		std::ostringstream os;
		os << ram;
		std::string s(os.str());


		Logging::log("RAM AFTER MENU: " + s, Logging::LOGGER_LEVEL_TRACE);

		//THIS IS WHERE WE HAVE FREE RAM TO LOAD!
	}
	void ClientState::CleanUp() {

	}

	void ClientState::Pause() {

	}
	void ClientState::Resume() {

	}

	void ClientState::Update(StateManager* sManager) {

	}
	void ClientState::Draw(StateManager* sManager) {

	}
}
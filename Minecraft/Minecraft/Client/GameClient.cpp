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

		u32 ramFree = System::freeMemory();
		float ram = ((float)ramFree) / 1024.0f / 1024.0f;
		std::ostringstream os;
		os << ram;
		std::string s(os.str());


		Logging::log("RAM AFTER MENU: " + s, Logging::LOGGER_LEVEL_TRACE);
	}
	void ClientState::Enter() {

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
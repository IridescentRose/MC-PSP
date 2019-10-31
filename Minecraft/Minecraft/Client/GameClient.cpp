#include "GameClient.hpp"
#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>
#include <sstream>

#include "../Common/Options.hpp"

#include <mclib/mclib.h>
#include <mclib/common/Common.h>
#include <mclib/core/Client.h>
#include <mclib/util/Forge.h>
#include <mclib/util/Hash.h>
#include <mclib/util/Utility.h>
#include <mclib/util/VersionFetcher.h>

namespace Minecraft::Client {

	ClientState::ClientState() {

	}
	ClientState::~ClientState() {

	}

	void ClientState::Init() {
		updateTimer = Timer();
		
		Logging::warn("Connecting!");
		//CONNECT TEST, DON'T START ALLOCATING RAM UNNECESSARILY!
		mc::util::VersionFetcher versionFetcher(connect_info.ip_address, 25565);

		Logging::warn("Fetched version!");
		mc::protocol::Version version = versionFetcher.GetVersion();

		mc::block::BlockRegistry::GetInstance()->RegisterVanillaBlocks();

		Logging::log("Connecting with version " + mc::protocol::to_string(version), Logging::LOGGER_LEVEL_INFO);
		
		mc::protocol::packets::PacketDispatcher dispatcher;
		mc::core::g_Client = new mc::core::Client(&dispatcher, version);

		mc::util::ForgeHandler& forge = versionFetcher.GetForge();

		forge.SetConnection(mc::core::g_Client->GetConnection());

		mc::core::g_Client->GetPlayerController()->SetHandleFall(true);

		//Set more as needed
		mc::core::g_Client->GetConnection()->GetSettings()
			.SetMainHand(Common::g_OptionsManager.options.mainHand ? mc::MainHand::Right : mc::MainHand::Left)
			.SetViewDistance(Common::g_OptionsManager.options.renderDistance)
			.SetChatColors(Common::g_OptionsManager.options.chatColors);

		
		try {
			Logging::log("Logging in.", Logging::LOGGER_LEVEL_INFO);
			mc::core::g_Client->Login(connect_info.ip_address, 25565, connect_info.username, "", mc::core::UpdateMethod::Threaded);
			mc::core::g_Client->Update();
		}
		catch (std::exception& e) {
			Logging::log(e.what(), Logging::LOGGER_LEVEL_FATAL);
			sceKernelExitGame();
		}

		//Once logged in, or when code reaches here, we reset the timer.
		updateTimer.reset();

	}
	void ClientState::Enter() {
		u32 ramFree = System::freeMemory();
		float ram = ((float)ramFree) / 1024.0f / 1024.0f;
		std::ostringstream os;
		os << ram;
		std::string s(os.str());

		//THIS IS WHERE WE HAVE FREE RAM TO LOAD!
	}
	void ClientState::CleanUp() {

	}

	void ClientState::Pause() {

	}
	void ClientState::Resume() {

	}

#define REQUIRED_UPDATE_FREQUENCY 0.050f

	void ClientState::Update(StateManager* sManager) {

		//Get Delta Time
		float dt = updateTimer.deltaTime();

		sceKernelDelayThread(100); //Force thread switch, just in case

		//See if the client connection is still active
		try {
			mc::core::g_Client->GetConnection()->CreatePacket();
		}
		catch (std::exception& e) {
			Logging::log(e.what(), Logging::LOGGER_LEVEL_FATAL);
			sceKernelExitGame();
		}

		//TODO: Update player position and look on interval
		if (updateTimer.elapsed() >= REQUIRED_UPDATE_FREQUENCY) {

		}
		

	}
	void ClientState::Draw(StateManager* sManager) {

	}
}
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

	ClientState::ClientState() : dispatcher(mc::protocol::packets::PacketDispatcher()), mc::protocol::packets::PacketHandler(&dispatcher) {
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
		}
		catch (std::exception& e) {
			Logging::log(e.what(), Logging::LOGGER_LEVEL_FATAL);
			sceKernelExitGame();
		}


		//Once logged in, or when code reaches here, we reset the timer.
		updateTimer.reset();
		player = new Player();
		mc::core::g_Client->GetPlayerManager()->RegisterListener(player);

		//Register listeners
		mc::core::g_Client->GetDispatcher()->RegisterHandler(mc::protocol::State::Play, mc::protocol::play::EntityVelocity, this);
		mc::core::g_Client->GetDispatcher()->RegisterHandler(mc::protocol::State::Play, mc::protocol::play::SpawnPosition, this);


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

		Logging::log("About to check for updates!", Logging::LOGGER_LEVEL_TRACE);
		mc::core::g_Client->Update();
		/*
		player->Update(dt);
		Logging::log("PLAYER POS: " + std::to_string(player->getPosition().x) + " " + std::to_string(player->getPosition().y) + " " + std::to_string(player->getPosition().z), Logging::LOGGER_LEVEL_INFO);
		
		//Update player position and look on interval
		if (updateTimer.elapsed() >= REQUIRED_UPDATE_FREQUENCY && mc::core::g_Client->GetConnection()->GetProtocolState() == mc::protocol::State::Play) {
			Logging::log("Client should update!", Logging::LOGGER_LEVEL_TRACE);

			mc::protocol::packets::out::PlayerPositionAndLookPacket response(player->getPosition(), player->getYaw(), player->getPitch(), player->isOnGround());
			Logging::log("Created Response!", Logging::LOGGER_LEVEL_TRACE);
			mc::core::g_Client->GetConnection()->SendPacket(&response);
			Logging::log("Sent Response!", Logging::LOGGER_LEVEL_TRACE);
			//Handle sneaking & sprinting later
			updateTimer.reset();
		}
		else if(updateTimer.elapsed() >= REQUIRED_UPDATE_FREQUENCY) {
			updateTimer.reset();
		}*/

		sceKernelDelayThread(100); //Force thread switch, just in case		

	}
	void ClientState::Draw(StateManager* sManager) {

	}
	void ClientState::HandlePacket(mc::protocol::packets::in::EntityVelocityPacket* packet)
	{

		Logging::log("Handling Velocity!", Logging::LOGGER_LEVEL_TRACE);
		mc::EntityId eid = packet->GetEntityId();

		//Velocity for PLAYERS
		//TODO: VELOCITY FOR MOBS

		auto playerEntity = mc::core::g_Client->GetEntityManager()->GetPlayerEntity();
		if (playerEntity && playerEntity->GetEntityId() == eid) {
			player->SetVelocity(ToVector3d(packet->GetVelocity()) * 20.0 / 8000.0);
			Logging::log("Handled Velocity!", Logging::LOGGER_LEVEL_TRACE);
		}
	}
	void ClientState::HandlePacket(mc::protocol::packets::in::SpawnPositionPacket* packet)
	{
		//Nothing needs to be done here... Happens in playerListener
		Logging::log("Handled Spawn Packet!", Logging::LOGGER_LEVEL_TRACE);
	}
}
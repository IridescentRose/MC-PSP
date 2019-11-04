#pragma once
#include <string>
#include <Shadow/Utils/StateManager.h>
#include <Shadow/Utils/GameState.h>
#include <Shadow/Utils/Timer.hpp>
#include "Player.h"
#include <mclib/protocol/packets/PacketHandler.h>
#include <mclib/protocol/packets/PacketDispatcher.h>

using namespace Shadow::Utils;
using namespace Shadow;

namespace Minecraft::Client {

	struct ConnectInfo {
		std::string username;
		std::string ip_address;
	};

	class ClientState : public GameState, mc::protocol::packets::PacketHandler {
	public:
		ClientState();
		~ClientState();
		
		void Init();
		void Enter();
		void CleanUp();

		void Pause();
		void Resume();

		void Update(StateManager* sManager);
		void Draw(StateManager* sManager);

		void HandlePacket(mc::protocol::packets::in::EntityVelocityPacket* packet);
		void HandlePacket(mc::protocol::packets::in::SpawnPositionPacket* packet);

		mc::protocol::packets::PacketDispatcher dispatcher;
		ConnectInfo connect_info;
	private:

		Timer updateTimer;
		Player* player;
	};
}
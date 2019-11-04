#pragma once
#include <string>
#include <Shadow/Utils/StateManager.h>
#include <Shadow/Utils/GameState.h>
#include <Shadow/Utils/Timer.hpp>
#include "Player.h"
#include <mclib/protocol/packets/PacketHandler.h>
#include <mclib/protocol/packets/PacketDispatcher.h>
#include "World.h"

using namespace Shadow::Utils;
using namespace Shadow;

namespace Minecraft {
	namespace Client {
		class SPClient : public GameState {
		public:
			SPClient();
			~SPClient();

			void Init();
			void Enter();
			void CleanUp();

			void Pause();
			void Resume();

			void Update(StateManager* sManager);
			void Draw(StateManager* sManager);

		private:
			Timer updateTimer;
			Player* player;
		};
	}
}
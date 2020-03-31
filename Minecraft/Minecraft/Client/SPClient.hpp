#pragma once
#include <string>
#include "../State/StateManager.h"
#include "../State/GameState.h"
#include "World/World.h"
#include <Utilities/Timer.h>
#include "Player.h"

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
			Stardust::Utilities::Timer updateTimer;
			Player* player;
		};
	}
}
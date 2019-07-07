#pragma once
#include <Aurealis/Utils/GameState.h>
#include <string>
#include "NetworkSystem.h"

using namespace Aurealis::Utils;

namespace Minecraft {
	class StateClient : public CGameState {
	public:
		StateClient();

		void Init();
		
		void Enter();
		void CleanUp();

		
		void Pause();
		void Resume();

		void HandleEvents(StateManager* sManager);
		void Update(StateManager* sManager);
		void Draw(StateManager* sManager);
	private:
		NetworkSystem* nw_man;

		unsigned char user_length;
		unsigned char ip_length;
	};
}
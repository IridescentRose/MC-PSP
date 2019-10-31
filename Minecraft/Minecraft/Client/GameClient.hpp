#pragma once
#include <string>
#include <Shadow/Utils/StateManager.h>
#include <Shadow/Utils/GameState.h>
#include <Shadow/Utils/Timer.hpp>


using namespace Shadow::Utils;
using namespace Shadow;

namespace Minecraft::Client {

	struct ConnectInfo {
		std::string username;
		std::string ip_address;
	};

	class ClientState : public GameState {
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

		ConnectInfo connect_info;
		Timer updateTimer;
	private:

	};
}
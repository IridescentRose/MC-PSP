#pragma once
#include <string>
#include <Shadow/Utils/StateManager.h>
#include <Shadow/Utils/GameState.h>

namespace Minecraft::Client {
	using namespace Shadow::Utils;

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
	private:

	};
}
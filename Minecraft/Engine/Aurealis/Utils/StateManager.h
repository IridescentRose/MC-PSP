#pragma once
#include <vector>

namespace Aurealis
{
	namespace Utils
	{

		class CGameState;


		class StateManager
		{
		public:

			void Init();
			void Enter();
			void CleanUp();

			void ChangeState(CGameState* state);
			void AddState(CGameState* state);
			void RemoveState();

			void HandleEvents();
			void Update();
			void Draw();

			bool Running() {return m_running;}
			void Quit() {m_running = false;}

		private:

			std::vector<CGameState*> states;
			bool m_running;


		};
	}
}

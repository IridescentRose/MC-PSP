#pragma once

#include <Aurealis/Utils/GameState.h>

#include <Shadow/Audio/AudioManager.hpp>
using namespace Shadow::Audio;
using namespace Aurealis::Utils;

namespace Minecraft::Menus{
    class MenuState : public CGameState {
    public:
	    MenuState();
	    virtual ~MenuState();

	    void Init();
	    void Enter();
	    void CleanUp();

	    void Pause();
	    void Resume();

	    void HandleEvents(StateManager* sManager);
	    void Update(StateManager* sManager);
	    void Draw(StateManager* sManager);
    private:
        void menuPass();
        void panoramaPass();

        OSL_SOUND* bgm;
    };
}
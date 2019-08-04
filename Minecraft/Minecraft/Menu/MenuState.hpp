#pragma once

#include <Aurealis/Utils/GameState.h>
#include "Panorama.hpp"
#include <Shadow/Audio/AudioManager.hpp>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/Graphics/Sprite.h>
#include <json/json.h>

#include <Aurealis/System/SystemManager.h>
using namespace Aurealis::System;
using namespace Shadow::Audio;
using namespace Aurealis::Utils;

namespace Minecraft::Menus{

	enum MenuStates{
		MENU_STATE_TITLE = 0
	};

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

        OSL_SOUND* bgm, *button;
		Panorama* panorama;
		Timer t;

		Texture* logo;
		Sprite* Minecraft1, *Minecraft2;

		Texture* widgets;

		std::string splashText;

		float splashSize, dt, elapsed;

		Sprite *selected, *unselected, *disabled, *lang, *hlang;
		Sprite *miniSel, *miniUnSel;
		int selectPosY, selectPosX;

		MenuStates menu_states;

    };
}
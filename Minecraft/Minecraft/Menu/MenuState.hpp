#pragma once

#include <Aurealis/Utils/GameState.h>
#include "components/Panorama.hpp"
#include <Shadow/Audio/AudioManager.hpp>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/Graphics/Sprite.h>
#include <json/json.h>

#include <Aurealis/Graphics/RenderManager.h>
#include <string>
#include <fstream>
#include "../Version.hpp"
#include <sstream>

#include <Aurealis/System/SystemManager.h>
#include "../Common/Translations.hpp"

#define PSP_MENU_SIZE 0.8
using namespace Aurealis::System;
using namespace Shadow::Audio;
using namespace Aurealis::Utils;

namespace Minecraft::Menus{

	enum MenuStates{
		MENU_STATE_TITLE = 0,
		MENU_STATE_LANGUAGE = 1,
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

		void titleScreenDraw();
		void titleScreenUpdate();

		void languageScreenDraw();
		void languageScreenUpdate();

        OSL_SOUND* bgm, *button;
		Panorama* panorama;
		Timer t;

		Texture* logo;
		Sprite* Minecraft1, *Minecraft2;

		Texture *widgets, *options_bg;

		std::string splashText;

		float splashSize, dt, elapsed;

		Sprite *selected, *unselected, *disabled, *lang, *hlang;
		Sprite *miniSel, *miniUnSel;
		Sprite *options_tile;

		int selectPosY, selectPosX;

		int selectRegion, langPos, langPosSel, langPosMax;

		MenuStates menu_states, previous_states;

    };
}
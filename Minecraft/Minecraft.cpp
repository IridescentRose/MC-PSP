#include <math.h>
#include <psptypes.h>

#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/System/SystemManager.h>
#include <Aurealis/Utils/StateManager.h>
#include <Shadow/Audio/AudioManager.hpp>
#include <Aurealis/Graphics/TextureUtil.h>

#include "Minecraft/Menu/Logo.hpp"
#include "Minecraft/Version.hpp"
#include "Minecraft/Menu/MenuState.hpp"
using namespace Minecraft::Menus;

using namespace Shadow::Audio;
using namespace Aurealis::Graphics;
using namespace Aurealis::Utils;
using namespace Aurealis::System;
using namespace Aurealis;

PSP_MODULE_INFO("Minecraft", 0, VERSION_MAJOR, VERSION_MINOR);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU|THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-1024);

void initGame(){
SetupCallbacks();
	scePowerSetClockFrequency(333, 333, 166);
	srand(time(NULL));

	//initialize render manager
	{
		g_RenderManager.Init();
		g_RenderManager.CollectPerformance(true);
		g_RenderManager.InitDebugFont();
		g_RenderManager.SetClearColour(0xFF000000);
	}
	//set perspectives
	{
		sceGumMatrixMode(GU_PROJECTION);
		sceGumLoadIdentity();
		sceGumOrtho(0, 480, 272, 0, -30, 30);

		sceGumMatrixMode(GU_VIEW);
		sceGumLoadIdentity();

		sceGumMatrixMode(GU_MODEL);
		sceGumLoadIdentity();
	}

	//init and load sounds
	g_AudioManager.init();
}

void doSplash(){
	//splash screen!
	{
		Texture* tex = TextureUtil::LoadPng("./Assets/ConstTextures/mojang.png");
		Logo* logo = new Logo();
		logo->render(tex, GU_COLOR(1.0f, 1.0f, 1.0f, 1.0f), 4.0f);
		delete logo;
		delete tex;
	}
}

void exitGame(){
	sceGuTerm();
	sceKernelExitGame();
}

void mainLoop(){
	StateManager stateManager;
	stateManager.Init();
	
	MenuState *state = new MenuState();
	state->Init();
	stateManager.ChangeState(state);

	while ( stateManager.Running() )
	{
		stateManager.HandleEvents();
		stateManager.Update();
		stateManager.Draw();
	}
}

int main()
{
	initGame();
	doSplash();

	mainLoop();

	exitGame();
	return 0;
}

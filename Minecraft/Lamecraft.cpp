#include <math.h>
#include <psptypes.h>

#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Utils/Logger.h>
#include <Aurealis/Utils/Timer.h>
#include <Aurealis/System/SystemManager.h>
#include <Aurealis/Graphics/Camera.h>
#include <Aurealis/Utils/StateManager.h>
#include "LameCraft/Menu/Version.h"
#include "LameCraft/Menu/StateMenu.h"
#include "LameCraft/Menu/SplashScreen.h"
#include <Aurealis/Audio/SoundManager.h>
#include <Aurealis/Graphics/TextureUtil.h>
using namespace Aurealis::Graphics;
using namespace Aurealis::Utils;
using namespace Aurealis::System;
using namespace Aurealis::Audio;
using namespace Aurealis;

PSP_MODULE_INFO("LameCraft", 0, VERSION_MAJOR, VERSION_MINOR);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU|THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-1024);

int main()
{
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
	g_SoundManager.Init();

	//new state manager
	StateManager stateManager;
	stateManager.Init();

	
	//splash screens
	{
		Texture* tex1 = TextureUtil::LoadPng("./Assets/ConstTextures/iridescence.png");
		Texture* tex2 = TextureUtil::LoadPng("./Assets/ConstTextures/genesis.png");
		SplashScreen* screen = new SplashScreen(tex1, 0, 0, 480, 272, 2);
		screen->ShowSplash();
		delete screen;
		SplashScreen* screen2 = new SplashScreen(tex2, 0, 0, 480, 272, 2);
		screen2->ShowSplash();
		delete screen2;
		delete tex1;
		delete tex2;
		g_RenderManager.SetClearColour(0xFFFFFFFF);
	}
	
	//new active state
	StateMenu *statePlay = new StateMenu();
	statePlay->Init();
	stateManager.ChangeState(statePlay);

	//true
	while ( stateManager.Running() )
	{
		stateManager.HandleEvents();
		stateManager.Update();
		stateManager.Draw();
	}

	sceGuTerm();			// Terminating the Graphics System
	sceKernelExitGame();	// Quits Application

	return 0;
}

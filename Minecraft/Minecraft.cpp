#include <math.h>
#include <psptypes.h>

#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Utils/StateManager.h>
#include <Shadow/Graphics/TextureUtil.h>

#include <Platform/Platform.h>

#include "Minecraft/Menu/Logo.hpp"
#include "Minecraft/Version.hpp"
#include "Minecraft/Menu/MenuState.hpp"
using namespace Minecraft::Menus;

using namespace Shadow::Graphics;
using namespace Shadow::Utils;
using namespace Shadow;

PSP_MODULE_INFO("Minecraft", 0, VERSION_MAJOR, VERSION_MINOR);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU|THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-256);

void initGame(){
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

	VirtualFileInit();
	oslInitAudio();
}

void doSplash(){
	//splash screen!
	{
		Texture* tex = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/mojang.png");
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
	
	MenuState *state = new MenuState();
	state->Init();
	stateManager.ChangeState(state);

	while ( true )
	{
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

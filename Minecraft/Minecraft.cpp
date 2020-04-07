
#include <Platform/Platform.h>
#include <Graphics/TextureUtil.h>
#include <Graphics/2D/SpriteBase.h>
#include <Utilities/Logger.h>
#include <Utilities/Timer.h>
#include <Graphics/RendererCore.h>
#include "Minecraft/Version.hpp"
#include "Minecraft/State/GameState.h"
#include "Minecraft/State/StateManager.h"
#include "Minecraft/Menu/MenuState.hpp"

PSP_MODULE_INFO("Minecraft", 0, VERSION_MAJOR, VERSION_MINOR);
PSP_MAIN_THREAD_ATTR(THREAD_ATTR_VFPU|THREAD_ATTR_USER);
PSP_HEAP_SIZE_KB(-256);


void doSplash(){
	//2D Mode initialization
	sceGumMatrixMode(GU_PROJECTION);
	sceGumLoadIdentity();
	sceGumOrtho(0, 480, 272, 0, -30, 30);
	sceGumMatrixMode(GU_VIEW);
	sceGumLoadIdentity();
	sceGumMatrixMode(GU_MODEL);
	sceGumLoadIdentity();

	Stardust::Graphics::g_RenderCore.SetClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	//splash screen!
	Stardust::Graphics::Texture* tex = Stardust::Graphics::TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/mojang.png");
	
	Stardust::Graphics::Render2D::Sprite* sprite = new Stardust::Graphics::Render2D::Sprite(tex);
	sprite->SetPosition(240, 136);
	sprite->Scale(1.0f, 1.0f);

	float time = 3.0f;
	Stardust::Utilities::Timer* timer = new Stardust::Utilities::Timer();
	timer->reset();

	Stardust::Graphics::g_RenderCore.SetClearColor(255, 255, 255, 255);

	while(time > 0.0f){
		Stardust::Graphics::g_RenderCore.BeginCommands();
		Stardust::Graphics::g_RenderCore.Clear();

		time -= timer->deltaTime();
		sprite->Draw();

		Stardust::Graphics::g_RenderCore.EndCommands();
	}
	
	delete sprite;
	delete timer;
	delete tex;
}


void mainLoop(){
	StateManager stateManager;
	stateManager.running = true;

	Minecraft::Menus::MenuState *state = new Minecraft::Menus::MenuState();
	state->Init();
	stateManager.ChangeState(state);

	while ( stateManager.running )
	{
		stateManager.Update();
		stateManager.Draw();
	}
}


int main()
{
	Stardust::Platform::initPlatform();
	doSplash();

	mainLoop();

	Stardust::Platform::exitPlatform();
	return 0;
}

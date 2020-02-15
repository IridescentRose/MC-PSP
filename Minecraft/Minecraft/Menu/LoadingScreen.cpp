#include "LoadingScreen.hpp"
#include <pspthreadman.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspdisplay.h>
#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Sprite.h>

using namespace Shadow::Graphics;

Sprite* options_tile;
Texture* options_bg;


LoadingScreen::LoadingScreen()
{
	// the loadingscreen is loaded as a thread
	thid_ = sceKernelCreateThread("LoadingThread", RunLoadingScreen, 0x18, 0x10000, THREAD_ATTR_VFPU|THREAD_ATTR_USER, NULL);
	// start the thread
	sceKernelStartThread(thid_, 0, 0);
}


void LoadingScreen::KillLoadingScreen()
{
	// shut down the loading screen again.
	sceKernelTerminateDeleteThread(thid_);
    delete options_tile;
    delete options_bg;
}


int LoadingScreen::RunLoadingScreen(SceSize args, void *argp)
{
	// load up the images
    options_bg = TextureUtil::LoadPng("assets/minecraft/textures/gui/options_background.png");
    options_tile = new Sprite(options_bg);
    options_tile->alpha = 255;
    options_tile->Scale(2.0f, 2.0f);

    sceGuEnable(GU_TEXTURE);
    sceGuEnable(GU_ALPHA_TEST);
    sceGuEnable(GU_BLEND);
    g_RenderManager.SetOrtho();
    g_RenderManager.StartFrame(0, 0, 0);
    
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 9; y++){
            options_tile->RGB(64.0f, 64.0f, 64.0f);
            options_tile->SetPosition(x * 32, y * 32);
            options_tile->Draw();
        }
    }

    g_RenderManager.SetFontStyle(1.0f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0);
    g_RenderManager.DebugPrint(240, 136, "Loading...");

    g_RenderManager.EndFrame();
	while(1){
    sceKernelDelayThread(1000000);
    }
	return 0;
}


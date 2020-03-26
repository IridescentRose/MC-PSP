#include "LoadingScreen.hpp"
#include <pspthreadman.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspdisplay.h>

#include "../Common/Translations.hpp"


LoadingScreen::LoadingScreen()
{
	// the loadingscreen is loaded as a thread
	thid_ = sceKernelCreateThread("LoadingThread", RunLoadingScreen, 0x18, 0x10000, THREAD_ATTR_VFPU|THREAD_ATTR_USER, NULL);
	
}
LoadingScreen* glbl_loadingscreen;

void LoadingScreen::KillLoadingScreen()
{
	// shut down the loading screen again.
	sceKernelTerminateDeleteThread(thid_);
    delete options_tile;
    delete options_bg;
}

void LoadingScreen::StartLoadingScreen(){
    // start the thread
	sceKernelStartThread(thid_, 0, 0);
}

int LoadingScreen::RunLoadingScreen(SceSize args, void *argp)
{

    sceGuEnable(GU_TEXTURE);
    sceGuEnable(GU_ALPHA_TEST);
    sceGuEnable(GU_BLEND);
    
    g_RenderCore.BeginCommands();
    g_RenderCore.Clear();
    
    for(int x = 0; x < 16; x++){
        for(int y = 0; y < 9; y++){
            glbl_loadingscreen->options_tile->RGB(64.0f, 64.0f, 64.0f);
            glbl_loadingscreen->options_tile->SetPosition(x * 32, y * 32);
            glbl_loadingscreen->options_tile->Draw();
        }
    }

    g_RenderCore.SetFontStyle(1.0f, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0);
    g_RenderCore.DebugPrint(240, 136, Minecraft::Common::g_TranslationOBJ.getText("menu.generatingTerrain").c_str());

    g_RenderCore.EndCommands();
	while(1){
    sceKernelDelayThread(1000000);
    }
	return 0;
}


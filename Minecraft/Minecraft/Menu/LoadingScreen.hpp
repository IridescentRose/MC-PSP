#pragma once

#include <pspkerneltypes.h>
#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Sprite.h>
using namespace Shadow::Graphics;


class LoadingScreen
{

protected:
    static int RunLoadingScreen(SceSize args, void *argp); //static int
    void RenderAll();
	SceUID thid_;

public:
	LoadingScreen();
	void StartLoadingScreen();
	void KillLoadingScreen();

Sprite* options_tile;
Texture* options_bg;
};

extern LoadingScreen* glbl_loadingscreen;
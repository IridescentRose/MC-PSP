#pragma once

#include <pspkerneltypes.h>
#include <Graphics/RendererCore.h>
#include <Graphics/2D/SpriteBase.h>
using namespace Stardust::Graphics;
using namespace Stardust::Graphics::Render2D;


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
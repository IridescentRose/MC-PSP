#pragma once

#include <pspkerneltypes.h>

class LoadingScreen
{

protected:
    static int RunLoadingScreen(SceSize args, void *argp); //static int
    void RenderAll();
	SceUID thid_;

public:
	LoadingScreen();
	void KillLoadingScreen();
};
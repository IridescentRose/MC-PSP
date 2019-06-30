#ifndef LOADINGSCREEN_H_
#define LOADINGSCREEN_H_

#include <pspkerneltypes.h>
#include <Aurealis/Graphics/TextureUtil.h>
class LoadingScreen
{

protected:
    static int RunLoadingScreen(SceSize args, void *argp); //static int
    void RenderAll();
	SceUID thid_;

public:
	LoadingScreen();
	void KillLoadingScreen();
	static int readiness;
	static int stateName;
};

#endif

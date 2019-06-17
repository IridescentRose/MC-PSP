#ifndef LOADINGSCREEN_H_
#define LOADINGSCREEN_H_

#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Graphics/Sprite.h>
#include <Aurealis/Utils/Timer.h>
#include "TextureHelper.h"

using namespace Aurealis::Graphics;
using namespace Aurealis::Utils;

class SplashScreen
{
public:

	SplashScreen(const char* filename,int startW,int startH,int endW,int endH,float splashTime);
	SplashScreen(int textureNumber,int startW,int startH,int endW,int endH,float splashTime);
	~SplashScreen();

	void ShowSplash();

private:

	float finishTime;
	float timer;
	float dt;
	Sprite* sprite;
	Timer mTimer;

};

#endif

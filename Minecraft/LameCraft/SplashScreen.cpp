#include "SplashScreen.h"

SplashScreen::SplashScreen(Texture* texture, int startW, int startH, int endW, int endH, float splashTime)
{
	sprite = new Sprite(texture, startW, startH, endW, endH);
	sprite->SetPosition(240, 136);

	finishTime = splashTime;
	timer = 0.0f;
	dt = mTimer.GetDeltaTime();
}

SplashScreen::~SplashScreen()
{
	delete sprite;
}


void SplashScreen::ShowSplash()
{
	dt = mTimer.GetDeltaTime();
	while(timer < finishTime)
	{
		dt = mTimer.GetDeltaTime();

		g_RenderManager.StartFrame(1,1,1);

		sceGuDisable(GU_DEPTH_TEST);
		sceGuEnable(GU_BLEND);
		sceGuColor(GU_COLOR(1,1,1,1.0f));

		sprite->Draw();

		sceGuDisable(GU_BLEND);
		sceGuEnable(GU_DEPTH_TEST);

		g_RenderManager.EndFrame();

		timer+=dt;
	}
	return;
}


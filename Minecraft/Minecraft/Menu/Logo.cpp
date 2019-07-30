#include "Logo.hpp"

namespace Minecraft::Menus{
    Logo::Logo(){

    }

    Logo::~Logo(){

    }

    void Logo::render(Texture* tex, unsigned int backgroundColor, float t){
        time = Timer();
        sprite = new Sprite(tex);
        sprite->SetPosition(240, 136);
        float timer = 0.0f;

        while(timer < t){
            timer += time.GetDeltaTime();

            g_RenderManager.StartFrame(1,1,1);


		    sceGuDisable(GU_DEPTH_TEST);
		    sceGuEnable(GU_BLEND);
            g_RenderManager.SetClearColour(backgroundColor);
            g_RenderManager.CleanBuffers();

            float percent = timer / (t/4.0f);
            if(percent >= 1.0f){
                percent = 1.0f;
            }

            sprite->Alpha(percent * 255.0f);

		    sprite->Draw();

		    sceGuDisable(GU_BLEND);
		    sceGuEnable(GU_DEPTH_TEST);

		    g_RenderManager.EndFrame();



        }
    }
}
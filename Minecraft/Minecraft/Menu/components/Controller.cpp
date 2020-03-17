#include "../MenuState.hpp"

namespace Minecraft::Menus{
    
	void MenuState::controlDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        for(int i = 0; i < 8; i++){
            opt_unsel->SetPosition(120, 48 + 24 * i);
            opt_unsel->Draw();
        }

        for(int i = 0; i < 8; i++){
            opt_unsel->SetPosition(360, 48 + 24 * i);
            opt_unsel->Draw();
        }

        unselected->SetPosition(240, 256);
        unselected->Draw();

        if(selectPosY == 16){
            selected->SetPosition(240, 256);
            selected->Draw();
        }else{
            opt_sel->SetPosition( 120 + 240 * (selectPosY / 8), 48 + 24*(selectPosY % 8) );
            opt_sel->Draw();
        }


        g_RenderManager.DebugPrint(240, 24, Common::g_TranslationOBJ.getText("controls.title").c_str());

        if(selectPosY == 16){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(240, 256, Common::g_TranslationOBJ.getText("gui.done").c_str());

    }

	void MenuState::controlUpdate(){

        if(Input::KeyPressed(PSP_CTRL_DOWN)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            selectPosY++;
            if(selectPosY > 16){
                selectPosY = 16;
            }
        }
        
        if(Input::KeyPressed(PSP_CTRL_UP)){
            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }

        if(Input::KeyPressed(PSP_CTRL_CROSS) && selectPosY == 16){
            Input::writeConfiguration("config.json");

            selectPosX = 0;
            selectPosY = 0;
            selectRegion = 0;
            previous_states = menu_states;
            menu_states = MENU_STATE_OPTIONS_MAIN;
        }

    }
}
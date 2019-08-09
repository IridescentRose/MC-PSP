#include "../MenuState.hpp"

namespace Minecraft::Menus{
    void MenuState::optionsMainScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }

            opt_dis->SetPosition(152, 48);
            opt_dis->Draw();

            opt_unsel->SetPosition(168 + 160, 48);
            opt_unsel->Draw();

            for(int i = 0; i < 4; i++){
                opt_unsel->SetPosition(168 + 160, 108 + i * 24);
                opt_unsel->Draw();
            }

            for(int i = 0; i < 4; i++){
                opt_unsel->SetPosition(152, 108 + i * 24);
                opt_unsel->Draw();
            }

            unselected->SetPosition(240, 272 - 24);
            unselected->Draw();

                        
        }

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 32, Common::g_TranslationOBJ.getText("options.title").c_str());

        g_RenderManager.DebugPrint(152, 108, Common::g_TranslationOBJ.getText("options.skinCustomisation").c_str());
        g_RenderManager.DebugPrint(152, 108 + 24, Common::g_TranslationOBJ.getText("options.video").c_str());
        g_RenderManager.DebugPrint(152, 108 + 48, Common::g_TranslationOBJ.getText("options.language").c_str());
        g_RenderManager.DebugPrint(152, 108 + 72, Common::g_TranslationOBJ.getText("options.resourcepack").c_str());


        g_RenderManager.DebugPrint(168 + 160, 108, Common::g_TranslationOBJ.getText("options.sounds").c_str());
        g_RenderManager.DebugPrint(168 + 160, 108 + 24, Common::g_TranslationOBJ.getText("options.controls").c_str());
        g_RenderManager.DebugPrint(168 + 160, 108 + 48, Common::g_TranslationOBJ.getText("options.chat.title").c_str());
        g_RenderManager.DebugPrint(168 + 160, 108 + 72, Common::g_TranslationOBJ.getText("options.accessibility.title").c_str());

        g_RenderManager.DebugPrint(240, 272 - 24, Common::g_TranslationOBJ.getText("gui.done").c_str());
    }
	void MenuState::optionsMainScreenUpdate(){
        if(g_System.KeyPressed(PSP_CTRL_RTRIGGER)){
            selectRegion++;
            if(selectRegion > 1){
                selectRegion = 1;
            }
        }

        if(g_System.KeyPressed(PSP_CTRL_LTRIGGER)){
            selectRegion--;
            if(selectRegion < 0){
                selectRegion = 0;
            }
        }

        if(g_System.KeyPressed(PSP_CTRL_DOWN)){
            selectPosY++;
            if(selectPosY > 5){
                selectPosY = 5;
            }
        }
        
        if(g_System.KeyPressed(PSP_CTRL_UP)){
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }
    

        if(g_System.KeyPressed(PSP_CTRL_CROSS)){
            if(selectRegion == 0){ //LEFT SIDE
                if(selectPosY == 0){} //NOTHING, this is modified by L/R
                if(selectPosY == 1){
                    //SKIN CUSTOMIZATION
                }
                if(selectPosY == 2){
                    //VIDEO SETTINGS!
                }
                if(selectPosY == 3){
                    //LANGUAGE!
                    selectPosX = 0;
                    selectPosY = 0;
                    selectRegion = 0;
                    previous_states = menu_states;
                    menu_states = MENU_STATE_LANGUAGE;
                }
                if(selectPosY == 4){
                    //RESOURCE PACKS
                    //TODO: ASK DARTH!
                }
            }
            if(selectRegion == 1){ //RIGHT SIDE
                if(selectPosY == 0){
                    //REALMS NOTIFICATIONS
                } 
                if(selectPosY == 1){
                    //MUSIC & SOUNDS
                }
                if(selectPosY == 2){
                    //CONTROLS
                }
                if(selectPosY == 3){
                    //CHAT SETTINGS
                }
                if(selectPosY == 4){
                    //ACCESSIBILITY SETTINGS
                }
            }
            if(selectPosY == 5){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = MENU_STATE_TITLE;
                previous_states = MENU_STATE_OPTIONS_MAIN;

                //CLOSE OPTIONS STREAMING!
            }
        }
    }
}
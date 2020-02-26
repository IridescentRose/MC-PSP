#include "../MenuState.hpp"

namespace Minecraft::Menus{
    void MenuState::playSelectDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 6; y++){
                options_tile->RGB(32.0f, 32.0f, 32.0f);
                options_tile->SetPosition(x*32, y * 32 + 48.0f);
                options_tile->Draw();
            }
        }

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("selectWorld.title").c_str());


        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 0){
            opt_sel->SetPosition(156, 236);
            opt_sel->Draw();
        }else{
            opt_unsel->SetPosition(156, 236);
            opt_unsel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 1){
            opt_sel->SetPosition(324, 236);
            opt_sel->Draw();
        }else{
            opt_unsel->SetPosition(324, 236);
            opt_unsel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 2){
            tinySel->SetPosition(368, 256);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(368, 256);
            tinyUnSel->Draw();
        }
        
        tinyDis->SetPosition(280, 256);
        tinyDis->Draw();


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 0){
            tinySel->SetPosition(112, 256);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(112, 256);
            tinyUnSel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 1){
            tinySel->SetPosition(200, 256);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(200, 256);
            tinyUnSel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 0){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(156, 236, Common::g_TranslationOBJ.getText("selectWorld.select").c_str());

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 1){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(324, 236, Common::g_TranslationOBJ.getText("selectWorld.create").c_str());


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 2){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(368, 256, Common::g_TranslationOBJ.getText("gui.cancel").c_str());

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(280, 256, Common::g_TranslationOBJ.getText("selectWorld.recreate").c_str());


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 0){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(112, 256, Common::g_TranslationOBJ.getText("selectWorld.edit").c_str());


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 1){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(200, 256, Common::g_TranslationOBJ.getText("selectWorld.delete").c_str());

    }
    void MenuState::playSelectUpdate(){
        if(Input::KeyPressed(PSP_CTRL_RTRIGGER)){
            selectRegion++;
        }

        if(Input::KeyPressed(PSP_CTRL_LTRIGGER)){
            selectRegion--;
        }

        if(selectRegion < 0){
            selectRegion = 0;
        }

        if(selectRegion > 1){
            selectRegion = 1;
        }

        if(selectRegion == 1){
            if(Input::KeyPressed(PSP_CTRL_UP)){
                selectPosY--;
            }
            if(Input::KeyPressed(PSP_CTRL_DOWN)){
                selectPosY++;
            }

            if(selectPosY > 1){
                selectPosY = 1;
            }

            if(selectPosY < 0){
                selectPosY = 0;
            }


            if(Input::KeyPressed(PSP_CTRL_LEFT)){
                selectPosX--;
            }

            if(Input::KeyPressed(PSP_CTRL_RIGHT)){
                selectPosX++;
            }

            if(selectPosY == 1){
                if(selectPosX > 2){
                    selectPosX = 2;
                }
            }

            if(selectPosX < 0){
                selectPosX = 0;
            }

            if(selectPosY == 0){
                if(selectPosX > 1){
                    selectPosX = 1;
                }
            }

        }

        if(Input::KeyPressed(PSP_CTRL_CROSS)){
            if(selectRegion == 1){
                if(selectPosY == 0 && selectPosX == 1){
                    //Create New

                    selectPosX = 0;
                    selectPosY = 0;
                    selectRegion = 0;
                    previous_states = menu_states;
                    menu_states = MENU_STATE_PLAY_GENERATE;
                }

                if(selectPosY == 0 && selectPosX == 0){
                    //LOAD WORLD!
                }

                if(selectPosY == 1 && selectPosX == 2){
                    //Cancel!
                    selectPosX = 0;
                    selectPosY = 0;
                    selectRegion = 0;
                    menu_states = MENU_STATE_TITLE;
                    previous_states = MENU_STATE_LOAD_SELECT;
                }

                if(selectPosY == 1 && selectPosX == 0){
                    //RENAME
                }

                if(selectPosY == 1 && selectPosX == 1){
                    //DELETE

                }


            }
        }
    }
}
#include "../MenuState.hpp"

#include <Utilities/Input.h>

using namespace Stardust::Utilities;

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
            unselected->SetPosition(120, 48 + 24 * i);
            unselected->Draw();
        }

        for(int i = 0; i < 8; i++){
            unselected->SetPosition(360, 48 + 24 * i);
            unselected->Draw();
        }

        unselected->SetPosition(240, 256);
        unselected->Draw();

        if(selectPosY == 16){
            selected->SetPosition(240, 256);
            selected->Draw();
        }else{
            selected->SetPosition( 120 + 240 * (selectPosY / 8), 48 + 24*(selectPosY % 8) );
            selected->Draw();
        }


        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 24, Common::g_TranslationOBJ.getText("controls.title").c_str());

        if(selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*0, (Common::g_TranslationOBJ.getText("key.forward") + ": " + toString(buttonFromAction("walkForward"))).c_str());


        if(selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*1, (Common::g_TranslationOBJ.getText("key.back") + ": " + toString(buttonFromAction("walkBackward"))).c_str());


        if(selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*2, (Common::g_TranslationOBJ.getText("key.left") + ": " + toString(buttonFromAction("walkStrafeLeft"))).c_str());


        if(selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*3, (Common::g_TranslationOBJ.getText("key.right") + ": " + toString(buttonFromAction("walkStrafeRight"))).c_str());


        if(selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*4, ("Look Up: " + toString(buttonFromAction("lookUp"))).c_str());


        if(selectPosY == 5){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*5, ("Look Down: " + toString(buttonFromAction("lookDown"))).c_str());


        if(selectPosY == 6){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*6, ("Look Left: " + toString(buttonFromAction("lookLeft"))).c_str());


        if(selectPosY == 7){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(120, 48 + 24*7, ("Look Right: " + toString(buttonFromAction("lookRight"))).c_str());



        if(selectPosY == 8){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*0, (Common::g_TranslationOBJ.getText("key.sprint") + ": " + toString(buttonFromAction("sprint"))).c_str());


        if(selectPosY == 9){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*1, (Common::g_TranslationOBJ.getText("key.sneak") + ": " + toString(buttonFromAction("sneak"))).c_str());


        if(selectPosY == 10){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*2, (Common::g_TranslationOBJ.getText("key.jump") + ": " + toString(buttonFromAction("jump"))).c_str());


        if(selectPosY == 11){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*3, (Common::g_TranslationOBJ.getText("key.keyboard.pause") + ": " + toString(buttonFromAction("pause"))).c_str());



        if(selectPosY == 12){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*4, (Common::g_TranslationOBJ.getText("key.attack") + ": " + toString(buttonFromAction("break"))).c_str());


        if(selectPosY == 13){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*5, (Common::g_TranslationOBJ.getText("key.use") + ": " + toString(buttonFromAction("place"))).c_str());


        if(selectPosY == 14){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*6, ("Hotbar Left: " + toString(buttonFromAction("scrollLeft"))).c_str());


        if(selectPosY == 15){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(360, 48 + 24*7, ("Hotbar Right: " + toString(buttonFromAction("scrollRight"))).c_str());




        if(selectPosY == 16){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 256, Common::g_TranslationOBJ.getText("gui.done").c_str());

    }

	void MenuState::controlUpdate(){

        if(KeyPressed(PSP_CTRL_DOWN)){
            button->Play(0);
            selectPosY++;
            if(selectPosY > 16){
                selectPosY = 16;
            }
        }
        
        if(KeyPressed(PSP_CTRL_UP)){
            button->Play(0);
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }

        if(KeyPressed(PSP_CTRL_CROSS) && selectPosY == 16){
            SaveConfiguration("config.json");
            LoadConfiguration("config.json");

            selectPosX = 0;
            selectPosY = 0;
            selectRegion = 0;
            previous_states = menu_states;
            menu_states = MENU_STATE_OPTIONS_MAIN;
        }
/*
        if(KeyPressed(PSP_CTRL_CROSS) && selectPosY != 16){
            switch(selectPosY){
                case 0:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("walkForwards");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "walkForwards");
                    break;
                }

                case 1:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("walkBackward");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "walkBackward");
                    break;
                }

                case 2:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("walkStrafeLeft");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "walkStrafeLeft");
                    break;
                }

                case 3:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("walkStrafeRight");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "walkStrafeRight");
                    break;
                }


                case 4:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("lookUp");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "lookUp");

                    break;
                }

                case 5:{
                    
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("lookDown");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "lookDown");

                    break;
                }

                case 6:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("lookLeft");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "lookLeft");

                    break;
                }

                case 7:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("lookRight");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "lookRight");

                    break;
                }
                case 8:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("sprint");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "sprint");

                    break;
                }
                case 9:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("sneak");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "sneak");

                    break;
                }
                case 10:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("jump");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "jump");

                    break;
                }
                case 11:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("pause");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "pause");

                    break;
                }
                case 12:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("break");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "break");

                    break;
                }
                case 13:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("place");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "place");

                    break;
                }
                case 14:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("hotLeft");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "hotLeft");

                    break;
                }
                case 15:{
                    int act = (PspCtrlButtons)nextAction();

                    actions.erase(act);
                    
                    int i = buttonFromAction("hotRight");
                    if(i != -1){
                        actions.erase(i);
                    }

                    actions.emplace(act, "hotRight");

                    break;
                }
              
            }
        }
  
            */
    }
}
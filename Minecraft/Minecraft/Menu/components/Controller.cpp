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


        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 24, Common::g_TranslationOBJ.getText("controls.title").c_str());

        if(selectPosY == 0){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*0, (Common::g_TranslationOBJ.getText("key.forward") + ": " + Input::toString(Input::findButtonPair("walkForward"))).c_str());


        if(selectPosY == 1){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*1, (Common::g_TranslationOBJ.getText("key.back") + ": " + Input::toString(Input::findButtonPair("walkBackward"))).c_str());


        if(selectPosY == 2){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*2, (Common::g_TranslationOBJ.getText("key.left") + ": " + Input::toString(Input::findButtonPair("walkStrafeLeft"))).c_str());


        if(selectPosY == 3){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*3, (Common::g_TranslationOBJ.getText("key.right") + ": " + Input::toString(Input::findButtonPair("walkStrafeRight"))).c_str());


        if(selectPosY == 4){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*4, ("Look Up: " + Input::toString(Input::findButtonPair("lookUp"))).c_str());


        if(selectPosY == 5){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*5, ("Look Down: " + Input::toString(Input::findButtonPair("lookDown"))).c_str());


        if(selectPosY == 6){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*6, ("Look Left: " + Input::toString(Input::findButtonPair("lookLeft"))).c_str());


        if(selectPosY == 7){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(120, 48 + 24*7, ("Look Right: " + Input::toString(Input::findButtonPair("lookRight"))).c_str());



        if(selectPosY == 8){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*0, (Common::g_TranslationOBJ.getText("key.sprint") + ": " + Input::toString(Input::findButtonPair("sprint"))).c_str());


        if(selectPosY == 9){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*1, (Common::g_TranslationOBJ.getText("key.sneak") + ": " + Input::toString(Input::findButtonPair("sneak"))).c_str());


        if(selectPosY == 10){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*2, (Common::g_TranslationOBJ.getText("key.jump") + ": " + Input::toString(Input::findButtonPair("jump"))).c_str());


        if(selectPosY == 11){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*3, (Common::g_TranslationOBJ.getText("key.keyboard.pause") + ": " + Input::toString(Input::findButtonPair("pause"))).c_str());



        if(selectPosY == 12){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*4, (Common::g_TranslationOBJ.getText("key.attack") + ": " + Input::toString(Input::findButtonPair("break"))).c_str());


        if(selectPosY == 13){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*5, (Common::g_TranslationOBJ.getText("key.use") + ": " + Input::toString(Input::findButtonPair("place"))).c_str());


        if(selectPosY == 14){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*6, ("Hotbar Left: " + Input::toString(Input::findButtonPair("scrollLeft"))).c_str());


        if(selectPosY == 15){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(360, 48 + 24*7, ("Hotbar Right: " + Input::toString(Input::findButtonPair("scrollRight"))).c_str());





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
            Input::loadConfiguration("config.json");

            selectPosX = 0;
            selectPosY = 0;
            selectRegion = 0;
            previous_states = menu_states;
            menu_states = MENU_STATE_OPTIONS_MAIN;
        }

        if(Input::KeyPressed(PSP_CTRL_CROSS) && selectPosY != 16){
            switch(selectPosY){
                case 0:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("walkForwards");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "walkForwards");
                    break;
                }

                case 1:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("walkBackward");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "walkBackward");
                    break;
                }

                case 2:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("walkStrafeLeft");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "walkStrafeLeft");
                    break;
                }

                case 3:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("walkStrafeRight");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "walkStrafeRight");
                    break;
                }


                case 4:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("lookUp");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "lookUp");

                    break;
                }

                case 5:{
                    
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("lookDown");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "lookDown");

                    break;
                }

                case 6:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("lookLeft");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "lookLeft");

                    break;
                }

                case 7:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("lookRight");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "lookRight");

                    break;
                }
                case 8:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("sprint");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "sprint");

                    break;
                }
                case 9:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("sneak");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "sneak");

                    break;
                }
                case 10:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("jump");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "jump");

                    break;
                }
                case 11:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("pause");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "pause");

                    break;
                }
                case 12:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("break");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "break");

                    break;
                }
                case 13:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("place");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "place");

                    break;
                }
                case 14:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("hotLeft");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "hotLeft");

                    break;
                }
                case 15:{
                    int act = (PspCtrlButtons)Input::nextAction();

                    Input::actions.erase(act);
                    
                    int i = Input::findButtonPair("hotRight");
                    if(i != -1){
                        Input::actions.erase(i);
                    }

                    Input::actions.emplace(act, "hotRight");

                    break;
                }
                
            }
        }

    }
}
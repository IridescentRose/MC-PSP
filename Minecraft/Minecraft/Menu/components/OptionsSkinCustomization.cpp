#include "../MenuState.hpp"

namespace Minecraft::Menus{
    void MenuState::optionsSkinScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }


        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 32, Common::g_TranslationOBJ.getText("options.skinCustomisation.title").c_str());

        for(int i = 0; i < 4; i++){
            opt_unsel->SetPosition(240 - 88, 64 + 24 * i);
            opt_unsel->Draw();
        }

        for(int i = 0; i < 4; i++){
            opt_unsel->SetPosition(240 + 88, 64 + 24 * i);
            opt_unsel->Draw();
        }

        unselected->SetPosition(240, 160);
        unselected->Draw();

        if(selectPosY <= 3){
            opt_sel->SetPosition(240 - 88 + 88 * 2 * selectRegion, 64 + 24 * selectPosY);
            opt_sel->Draw();
        }else{
            selected->SetPosition(240, 160);
            selected->Draw();
        }

        //TEXT
        if(selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 160, Common::g_TranslationOBJ.getText("gui.done").c_str());
        
        if(selectPosY == 0 && selectRegion == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 64 + 0, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.cape").c_str(), (Common::g_OptionsManager.options.modelPart_cape) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));
        
        if(selectPosY == 1 && selectRegion == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 64 + 24, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.left_sleeve").c_str(), (Common::g_OptionsManager.options.modelPart_left_sleeve) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));
        
        if(selectPosY == 2 && selectRegion == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 64 + 48, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.left_pants_leg").c_str(), (Common::g_OptionsManager.options.modelPart_left_pants_leg) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));

        if(selectPosY == 3 && selectRegion == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 64 + 72, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.hat").c_str(), (Common::g_OptionsManager.options.modelPart_hat) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));


        
        if(selectPosY == 0 && selectRegion == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 64 + 0, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.jacket").c_str(), (Common::g_OptionsManager.options.modelPart_jacket) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));
        
        if(selectPosY == 1 && selectRegion == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 64 + 24, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.right_sleeve").c_str(), (Common::g_OptionsManager.options.modelPart_right_sleeve) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));
        
        if(selectPosY == 2 && selectRegion == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 64 + 48, "%s: %s ", Common::g_TranslationOBJ.getText("options.modelPart.right_pants_leg").c_str(), (Common::g_OptionsManager.options.modelPart_right_pants_leg) ? (Common::g_TranslationOBJ.getText("options.on").c_str()) : (Common::g_TranslationOBJ.getText("options.off").c_str()));

        if(selectPosY == 3 && selectRegion == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 64 + 72, "%s: %s ", Common::g_TranslationOBJ.getText("options.mainHand").c_str(), (Common::g_OptionsManager.options.mainHand) ? (Common::g_TranslationOBJ.getText("options.mainHand.right").c_str()) : (Common::g_TranslationOBJ.getText("options.mainHand.left").c_str()));

    }

    void MenuState::optionsSkinScreenUpdate(){
        if(KeyPressed(PSP_CTRL_RTRIGGER)){
            button->Play(0);
            selectRegion++;
            if(selectRegion > 1){
                selectRegion = 1;
            }
        }

        if(KeyPressed(PSP_CTRL_LTRIGGER)){
            button->Play(0);
            selectRegion--;
            if(selectRegion < 0){
                selectRegion = 0;
            }
        }

        if(KeyPressed(PSP_CTRL_DOWN)){
            button->Play(0);
            selectPosY++;
            if(selectPosY > 4){
                selectPosY = 4;
            }
        }
        
        if(KeyPressed(PSP_CTRL_UP)){
            button->Play(0);
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }

        if(KeyPressed(PSP_CTRL_CROSS)){
            button->Play(0);
            if(selectRegion == 0){ //LEFT SIDE
                if(selectPosY == 0){
                    Common::g_OptionsManager.options.modelPart_cape = !Common::g_OptionsManager.options.modelPart_cape;
                }
                if(selectPosY == 1){
                    
                    Common::g_OptionsManager.options.modelPart_left_sleeve = !Common::g_OptionsManager.options.modelPart_left_sleeve;
                }
                if(selectPosY == 2){
                    
                    Common::g_OptionsManager.options.modelPart_left_pants_leg = !Common::g_OptionsManager.options.modelPart_left_pants_leg;
                }
                if(selectPosY == 3){
                    
                    Common::g_OptionsManager.options.modelPart_hat = !Common::g_OptionsManager.options.modelPart_hat;
                }
            }
            if(selectRegion == 1){ //RIGHT SIDE
                if(selectPosY == 0){

                    Common::g_OptionsManager.options.modelPart_jacket = !Common::g_OptionsManager.options.modelPart_jacket;
                } 
                if(selectPosY == 1){
                    
                    Common::g_OptionsManager.options.modelPart_right_sleeve = !Common::g_OptionsManager.options.modelPart_right_sleeve;
                }
                if(selectPosY == 2){
                    
                    Common::g_OptionsManager.options.modelPart_right_pants_leg = !Common::g_OptionsManager.options.modelPart_right_pants_leg;
                }
                if(selectPosY == 3){
                    
                    Common::g_OptionsManager.options.mainHand = !Common::g_OptionsManager.options.mainHand;
                }
            }
            if(selectPosY == 4){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = previous_states;
                previous_states = MENU_STATE_SKIN_CUSTOMIZATION;
            }
        }
        
    }
}
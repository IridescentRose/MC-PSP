#include "../MenuState.hpp"

namespace Minecraft::Menus{
    void MenuState::optionsChatScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("options.chat.title").c_str());
        
        //LEFT
        opt_unsel->SetPosition(240 - 88, 48);
        opt_unsel->Draw();

        opt_unsel->SetPosition(240 - 88, 48 + 24);
        opt_unsel->Draw();

        opt_unsel->SetPosition(240 - 88, 48 + 48);
        opt_unsel->Draw();

        opt_dis->SetPosition(240 - 88, 48 + 72);
        opt_dis->Draw();

        opt_dis->SetPosition(240 - 88, 48 + 96);
        opt_dis->Draw();

        opt_unsel->SetPosition(240 - 88, 48 + 120);
        opt_unsel->Draw();
        
        //RIGHT
        opt_unsel->SetPosition(240 + 88, 48);
        opt_unsel->Draw();

        opt_dis->SetPosition(240 + 88, 48 + 24);
        opt_dis->Draw();

        opt_dis->SetPosition(240 + 88, 48 + 48);
        opt_dis->Draw();

        opt_dis->SetPosition(240 + 88, 48 + 72);
        opt_dis->Draw();

        opt_unsel->SetPosition(240 + 88, 48 + 96);
        opt_unsel->Draw();

        unselected->SetPosition(240, 48 + 144);
        unselected->Draw();
        if(selectPosY > 5){
            selected->SetPosition(240, 48 + 144);
            selected->Draw();
        }

        if(selectRegion == 0 && (selectPosY < 3)){
            opt_sel->SetPosition(240 - 88, 48 + 24 * selectPosY);
            opt_sel->Draw();
        }
        if(selectPosY == 5){
            opt_sel->SetPosition(240 - 88, 48 + 24 * selectPosY);
            opt_sel->Draw();
        }

        if(selectRegion == 1 && (selectPosY == 0 || selectPosY == 4)){
            opt_sel->SetPosition(240 + 88, 48 + 24 * selectPosY);
            opt_sel->Draw();
        }

        //SLIDERS

        slider->SetPosition(240 - 8 - 158 + (Common::g_OptionsManager.options.chatHeightFocused)*156, 48 + 72);
        slider_sel->SetPosition(240 - 8 - 158 + (Common::g_OptionsManager.options.chatHeightFocused)*156, 48 + 72);
        (selectRegion == 0 && selectPosY == 3) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 - 8 - 158 + (Common::g_OptionsManager.options.chatWidth)*156, 48 + 96);
        slider_sel->SetPosition(240 - 8 - 158 + (Common::g_OptionsManager.options.chatWidth)*156, 48 + 96);
        (selectRegion == 0 && selectPosY == 4) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 + 10 + (Common::g_OptionsManager.options.chatOpacity)*156, 48 + 24);
        slider_sel->SetPosition(240 + 10 + (Common::g_OptionsManager.options.chatOpacity)*156, 48 + 24);
        (selectRegion == 1 && selectPosY == 1) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 + 10 + (Common::g_OptionsManager.options.chatScale)*156, 48 + 48);
        slider_sel->SetPosition(240 + 10 + (Common::g_OptionsManager.options.chatScale)*156, 48 + 48);
        (selectRegion == 1 && selectPosY == 2) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 + 10 + (Common::g_OptionsManager.options.chatHeightUnfocused)*156, 48 + 72);
        slider_sel->SetPosition(240 + 10 + (Common::g_OptionsManager.options.chatHeightUnfocused)*156, 48 + 72);
        (selectRegion == 1 && selectPosY == 3) ? slider_sel->Draw() : slider->Draw();

        //TEXT
        if(selectRegion == 0 && selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 48, "%s: %s", Common::g_TranslationOBJ.getText("options.chat.visibility").c_str(), (Common::g_OptionsManager.options.chatVisibility == 0) ? Common::g_TranslationOBJ.getText("options.chat.visibility.full").c_str() : (Common::g_OptionsManager.options.chatVisibility == 1) ? Common::g_TranslationOBJ.getText("options.chat.visibility.system").c_str() : Common::g_TranslationOBJ.getText("options.chat.visibility.hidden").c_str());

        if(selectRegion == 0 && selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 48 + 24, "%s: %s", Common::g_TranslationOBJ.getText("options.chat.links").c_str(), (Common::g_OptionsManager.options.chatLinks) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        if(selectRegion == 0 && selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 48 + 48, "%s: %s", Common::g_TranslationOBJ.getText("options.chat.links.prompt").c_str(), (Common::g_OptionsManager.options.chatLinks) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());


        if(selectRegion == 0 && selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 48 + 72, "%s: %dpx", Common::g_TranslationOBJ.getText("options.chat.height.focused").c_str(), (int)(Common::g_OptionsManager.options.chatHeightFocused * 180));

        if(selectRegion == 0 && selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 48 + 96, "%s: %dpx", Common::g_TranslationOBJ.getText("options.chat.width").c_str(), (int)(Common::g_OptionsManager.options.chatWidth * 320));

        if(selectPosY == 5){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 48 + 120, "%s: %s", Common::g_TranslationOBJ.getText("options.narrator").c_str(), Common::g_TranslationOBJ.getText("options.narrator.notavailable").c_str());


        if(selectRegion == 1 && selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 48, "%s: %s", Common::g_TranslationOBJ.getText("options.chat.color").c_str(), (Common::g_OptionsManager.options.chatColors) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());
        
        if(selectRegion == 1 && selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 48 + 24, "%s: %d%%", Common::g_TranslationOBJ.getText("options.chat.opacity").c_str(), (int)(Common::g_OptionsManager.options.chatOpacity * 100));

        if(selectRegion == 1 && selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 48 + 48, "%s: %d%%", Common::g_TranslationOBJ.getText("options.chat.scale").c_str(), (int)(Common::g_OptionsManager.options.chatScale * 100));

        if(selectRegion == 1 && selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 48 + 72, "%s: %dpx", Common::g_TranslationOBJ.getText("options.chat.height.unfocused").c_str(), (int)(Common::g_OptionsManager.options.chatHeightUnfocused * 204));

        if(selectRegion == 1 && selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 48+96, "%s: %s", Common::g_TranslationOBJ.getText("options.reducedDebugInfo").c_str(), (Common::g_OptionsManager.options.reducedDebugInfo) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());


        if(selectPosY == 6){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 48 + 144, "%s", Common::g_TranslationOBJ.getText("gui.done").c_str());
    }
    void MenuState::optionsChatScreenUpdate(){
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
            if(selectPosY > 6){
                selectPosY = 6;
            }
        }
        
        if(KeyPressed(PSP_CTRL_UP)){
            button->Play(0);
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }

        if(KeyPressed(PSP_CTRL_LEFT)){
            if(selectPosY == 3 && selectRegion == 0){
                Common::g_OptionsManager.options.chatHeightFocused -= 1/180.0f;
            }
            if(Common::g_OptionsManager.options.chatHeightFocused > 1){
                Common::g_OptionsManager.options.chatHeightFocused = 1;
            }
            if(Common::g_OptionsManager.options.chatHeightFocused < 0){
                Common::g_OptionsManager.options.chatHeightFocused = 0;
            }

            if(selectPosY == 4 && selectRegion == 0){
                Common::g_OptionsManager.options.chatWidth -= 1/320.0f;
            }
            if(Common::g_OptionsManager.options.chatWidth > 1){
                Common::g_OptionsManager.options.chatWidth = 1;
            }
            if(Common::g_OptionsManager.options.chatWidth < 0){
                Common::g_OptionsManager.options.chatWidth = 0;
            }
            

            if(selectPosY == 1 && selectRegion == 1){
                Common::g_OptionsManager.options.chatOpacity -= 1/100.0f;
            }
            if(Common::g_OptionsManager.options.chatOpacity > 1){
                Common::g_OptionsManager.options.chatOpacity = 1;
            }
            if(Common::g_OptionsManager.options.chatOpacity < 0){
                Common::g_OptionsManager.options.chatOpacity = 0;
            }
            

            if(selectPosY == 2 && selectRegion == 1){
                Common::g_OptionsManager.options.chatScale -= 1/100.0f;
            }
            if(Common::g_OptionsManager.options.chatScale > 1){
                Common::g_OptionsManager.options.chatScale = 1;
            }
            if(Common::g_OptionsManager.options.chatScale < 0){
                Common::g_OptionsManager.options.chatScale = 0;
            }
            
            if(selectPosY == 3 && selectRegion == 1){
                Common::g_OptionsManager.options.chatHeightUnfocused -= 1/204.0f;
            }
            if(Common::g_OptionsManager.options.chatHeightUnfocused > 1){
                Common::g_OptionsManager.options.chatHeightUnfocused = 1;
            }
            if(Common::g_OptionsManager.options.chatHeightUnfocused < 0){
                Common::g_OptionsManager.options.chatHeightUnfocused = 0;
            }

        }

        if(KeyPressed(PSP_CTRL_RIGHT)){
            if(selectPosY == 3 && selectRegion == 0){
                Common::g_OptionsManager.options.chatHeightFocused += 1/180.0f;
            }
            if(Common::g_OptionsManager.options.chatHeightFocused > 1){
                Common::g_OptionsManager.options.chatHeightFocused = 1;
            }
            if(Common::g_OptionsManager.options.chatHeightFocused < 0){
                Common::g_OptionsManager.options.chatHeightFocused = 0;
            }

            if(selectPosY == 4 && selectRegion == 0){
                Common::g_OptionsManager.options.chatWidth += 1/320.0f;
            }
            if(Common::g_OptionsManager.options.chatWidth > 1){
                Common::g_OptionsManager.options.chatWidth = 1;
            }
            if(Common::g_OptionsManager.options.chatWidth < 0){
                Common::g_OptionsManager.options.chatWidth = 0;
            }
            

            if(selectPosY == 1 && selectRegion == 1){
                Common::g_OptionsManager.options.chatOpacity += 1/100.0f;
            }
            if(Common::g_OptionsManager.options.chatOpacity > 1){
                Common::g_OptionsManager.options.chatOpacity = 1;
            }
            if(Common::g_OptionsManager.options.chatOpacity < 0){
                Common::g_OptionsManager.options.chatOpacity = 0;
            }
            

            if(selectPosY == 2 && selectRegion == 1){
                Common::g_OptionsManager.options.chatScale += 1/100.0f;
            }
            if(Common::g_OptionsManager.options.chatScale > 1){
                Common::g_OptionsManager.options.chatScale = 1;
            }
            if(Common::g_OptionsManager.options.chatScale < 0){
                Common::g_OptionsManager.options.chatScale = 0;
            }
            
            if(selectPosY == 3 && selectRegion == 1){
                Common::g_OptionsManager.options.chatHeightUnfocused += 1/204.0f;
            }
            if(Common::g_OptionsManager.options.chatHeightUnfocused > 1){
                Common::g_OptionsManager.options.chatHeightUnfocused = 1;
            }
            if(Common::g_OptionsManager.options.chatHeightUnfocused < 0){
                Common::g_OptionsManager.options.chatHeightUnfocused = 0;
            }
        }

        if(KeyPressed(PSP_CTRL_CROSS)){
            button->Play(0);
            if(selectRegion == 1 && selectPosY == 0){
                Common::g_OptionsManager.options.chatColors = !Common::g_OptionsManager.options.chatColors;
            }
            if(selectRegion == 1 && selectPosY == 4){
                Common::g_OptionsManager.options.reducedDebugInfo = !Common::g_OptionsManager.options.reducedDebugInfo;
            }

            if(selectRegion == 0 && selectPosY == 0){
                Common::g_OptionsManager.options.chatVisibility++;
                if(Common::g_OptionsManager.options.chatVisibility > 2){
                    Common::g_OptionsManager.options.chatVisibility = 0;
                }
            }

            if(selectPosY == 6){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = previous_states;
                previous_states = MENU_STATE_CHAT_SETTINGS;
            }
        }

    }
}
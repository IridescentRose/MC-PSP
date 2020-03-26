#include "../MenuState.hpp"

namespace Minecraft::Menus{
    void MenuState::optionsVideoScreenDraw(){
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
                options_tile->SetPosition(x*32, y * 32 + 56.0f);
                options_tile->Draw();
            }
        }


        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("options.videoTitle").c_str());
        

        for(int i = 0; i < 8; i++){
            opt_unsel->SetPosition(240 - 88, 52 + 24 * i);
            opt_unsel->Draw();
        }
        for(int i = 0; i < 8; i++){
            opt_unsel->SetPosition(240 + 88, 52 + 24 * i);
            opt_unsel->Draw();
        }

        unselected->SetPosition(240, 272 - 24);
        unselected->Draw();

        opt_dis->SetPosition(240 - 88, 52 + 24 * 4);
        opt_dis->Draw();

        opt_dis->SetPosition(240 + 88, 52);
        opt_dis->Draw();

        opt_dis->SetPosition(240 + 88, 52 + 24 * 1);
        opt_dis->Draw();

        opt_dis->SetPosition(240 + 88, 52 + 24 * 6);
        opt_dis->Draw();

        if(selectRegion == 0 && ((selectPosY >= 0 && selectPosY < 4) || (selectPosY >= 5 && selectPosY < 8))){
            opt_sel->SetPosition(240 - 88, 52 + 24 * selectPosY);
            opt_sel->Draw();
        }

        if(selectRegion == 1 && ((selectPosY >= 2 && selectPosY < 6) || (selectPosY == 7))){
            opt_sel->SetPosition(240 + 88, 52 + 24 * selectPosY);
            opt_sel->Draw();
        }

        if(selectPosY == 8){
            selected->SetPosition(240, 272 - 24);
            selected->Draw();
        }

        //Sliders

        slider->SetPosition(240 - 164 + (Common::g_OptionsManager.options.gamma)*152.0f, 52 + 24 * 4);
        slider_sel->SetPosition(240 - 164 + (Common::g_OptionsManager.options.gamma)*152.0f, 52 + 24 * 4);
        if(selectRegion == 0 && selectPosY == 4){
            slider_sel->Draw();
        }else{
            slider->Draw();
        }

        slider->SetPosition(240 + 12 + ((Common::g_OptionsManager.options.renderDistance - 1) / 7.0f)*152.0f, 52);
        slider_sel->SetPosition(240 + 12 + ((Common::g_OptionsManager.options.renderDistance - 1) / 7.0f)*152.0f, 52);
        if(selectRegion == 1 && selectPosY == 0){
            slider_sel->Draw();
        }else{
            slider->Draw();
        }

        //FPS NOT INTERACTABLE!
        slider->SetPosition(240 + 164, 52 + 24);
        slider_sel->SetPosition(240 + 164, 52 + 24);
        if(selectRegion == 1 && selectPosY == 1){
            slider_sel->Draw();
        }else{
            slider->Draw();
        }

        //MIPMAPS NOT INTERACTABLE
        slider->SetPosition(240 + 164, 52 + 24 * 6);
        slider_sel->SetPosition(240 + 164, 52 + 24 * 6);
        if(selectRegion == 1 && selectPosY == 6){
            slider_sel->Draw();
        }else{
            slider->Draw();
        }
        
        //Text
        //Done button
        if(selectPosY == 8){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 272 - 24, Common::g_TranslationOBJ.getText("gui.done").c_str());

        if(selectRegion == 0 && selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52, "%s: %s", Common::g_TranslationOBJ.getText("options.graphics").c_str(), (Common::g_OptionsManager.options.fancyGraphics) ? Common::g_TranslationOBJ.getText("options.graphics.fancy").c_str() : Common::g_TranslationOBJ.getText("options.graphics.fast").c_str());

        if(selectRegion == 0 && selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+24, "%s: %s", Common::g_TranslationOBJ.getText("options.ao").c_str(), (Common::g_OptionsManager.options.ao == 0) ? Common::g_TranslationOBJ.getText("options.ao.off").c_str() : ((Common::g_OptionsManager.options.ao == 1) ? Common::g_TranslationOBJ.getText("options.ao.min").c_str() : Common::g_TranslationOBJ.getText("options.ao.max").c_str()));

        //NON-INTERACTABLE
        if(selectRegion == 0 && selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+48, "%s: %s", Common::g_TranslationOBJ.getText("options.anaglyph").c_str(), Common::g_TranslationOBJ.getText("options.off").c_str());
        //NON-INTERACTABLE
        if(selectRegion == 0 && selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+72, "%s: %s", Common::g_TranslationOBJ.getText("options.guiScale").c_str(), Common::g_TranslationOBJ.getText("options.guiScale.auto").c_str());

        if(selectRegion == 0 && selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+96, "%s: %d", Common::g_TranslationOBJ.getText("options.gamma").c_str(), (int)(Common::g_OptionsManager.options.gamma * 100) );

        if(selectRegion == 0 && selectPosY == 5){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+96 + 24, "%s: %s", Common::g_TranslationOBJ.getText("options.particles").c_str(), (Common::g_OptionsManager.options.particles == 0) ? Common::g_TranslationOBJ.getText("options.particles.all").c_str() : ((Common::g_OptionsManager.options.particles == 1) ? Common::g_TranslationOBJ.getText("options.particles.decreased").c_str() : Common::g_TranslationOBJ.getText("options.particles.minimal").c_str()));
        
        
        if(selectRegion == 0 && selectPosY == 6){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+96+48, "%s: %s", Common::g_TranslationOBJ.getText("options.vsync").c_str(), (Common::g_OptionsManager.options.enableVsync) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        if(selectRegion == 0 && selectPosY == 7){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 - 88, 52+96+72, "%s: %s", Common::g_TranslationOBJ.getText("options.vbo").c_str(), (Common::g_OptionsManager.options.useVbo) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        if(selectRegion == 1 && selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52, "%s: %d", Common::g_TranslationOBJ.getText("options.renderDistance").c_str(), Common::g_OptionsManager.options.renderDistance);

        if(selectRegion == 1 && selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+24, "60 fps");

        if(selectRegion == 1 && selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+48, "%s: %s", Common::g_TranslationOBJ.getText("options.viewBobbing").c_str(), (Common::g_OptionsManager.options.bobView) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());


        if(selectRegion == 1 && selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+72, "%s: %s", Common::g_TranslationOBJ.getText("options.attackIndicator").c_str(), (Common::g_OptionsManager.options.attackIndicator == 1) ? Common::g_TranslationOBJ.getText("options.attack.crosshair").c_str() : ((Common::g_OptionsManager.options.attackIndicator == 2) ? Common::g_TranslationOBJ.getText("options.attack.hotbar").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str()));

        if(selectRegion == 1 && selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+96, "%s: %s", Common::g_TranslationOBJ.getText("options.renderClouds").c_str(), (Common::g_OptionsManager.options.renderClouds) ? Common::g_TranslationOBJ.getText("options.graphics.fancy").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        if(selectRegion == 1 && selectPosY == 5){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+120, "%s: %s", Common::g_TranslationOBJ.getText("options.fullscreen").c_str(), Common::g_TranslationOBJ.getText("options.on").c_str());

        if(selectRegion == 1 && selectPosY == 6){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+144, "%s: %d", Common::g_TranslationOBJ.getText("options.mipmapLevels").c_str(), 4);

        if(selectRegion == 1 && selectPosY == 7){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240 + 88, 52+168, "%s: %s", Common::g_TranslationOBJ.getText("options.entityShadows").c_str(), (Common::g_OptionsManager.options.entityShadows) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        

    }
    void MenuState::optionsVideoScreenUpdate(){
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
            if(selectPosY > 8){
                selectPosY = 8;
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
            if(selectPosY == 4 && selectRegion == 0){
                Common::g_OptionsManager.options.gamma -= 1 / 100.0f;
            }
            if(Common::g_OptionsManager.options.gamma < 0){
                Common::g_OptionsManager.options.gamma = 0.0f;
            }
            if(selectPosY == 0 && selectRegion == 1){
                Common::g_OptionsManager.options.renderDistance--;
            }
            if(Common::g_OptionsManager.options.renderDistance < 1){
                Common::g_OptionsManager.options.renderDistance = 1;
            }
        }
        if(KeyPressed(PSP_CTRL_RIGHT)){
            if(selectPosY == 4 && selectRegion == 0){
                Common::g_OptionsManager.options.gamma += 1 / 100.0f;
            }
            if(Common::g_OptionsManager.options.gamma > 1){
                Common::g_OptionsManager.options.gamma = 1.0f;
            }
            if(selectPosY == 0 && selectRegion == 1){
                Common::g_OptionsManager.options.renderDistance++;
            }
            if(Common::g_OptionsManager.options.gamma > 8){
                Common::g_OptionsManager.options.gamma = 8;
            }
        }

        if(KeyPressed(PSP_CTRL_CROSS)){
            button->Play(0);

            if(selectPosY == 0 && selectRegion == 0){
                Common::g_OptionsManager.options.fancyGraphics = !Common::g_OptionsManager.options.fancyGraphics;
            }

            if(selectPosY == 2 && selectRegion == 1){
                Common::g_OptionsManager.options.bobView = !Common::g_OptionsManager.options.bobView;
            }

            if(selectPosY == 4 && selectRegion == 1){
                Common::g_OptionsManager.options.renderClouds = !Common::g_OptionsManager.options.renderClouds;
            }

            if(selectPosY == 7 && selectRegion == 1){
                Common::g_OptionsManager.options.entityShadows = !Common::g_OptionsManager.options.entityShadows;
            }

            if(selectPosY == 1 && selectRegion == 0){
                Common::g_OptionsManager.options.ao -= 1;
                if(Common::g_OptionsManager.options.ao < 0){
                    Common::g_OptionsManager.options.ao = 2;
                }
            }
            if(selectPosY == 5 && selectRegion == 0){
                Common::g_OptionsManager.options.particles -= 1;
                if(Common::g_OptionsManager.options.particles < 0){
                    Common::g_OptionsManager.options.particles = 2;
                }
            }

            if(selectPosY == 3 && selectRegion == 1){
                Common::g_OptionsManager.options.attackIndicator -= 1;
                if(Common::g_OptionsManager.options.attackIndicator < 0){
                    Common::g_OptionsManager.options.attackIndicator = 2;
                }
            }
            if(selectPosY == 8){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = previous_states;
                previous_states = MENU_STATE_VIDEO;
            }
        }
    }
}
#include "../MenuState.hpp"

namespace Minecraft::Menus{

    void MenuState::optionsMusicScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }


        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 32, Common::g_TranslationOBJ.getText("options.sounds.title").c_str());

        
        mega_slider->SetPosition(240, 64);
        mega_slider->Draw();

        for(int i = 0; i < 5; i++){
            opt_dis->SetPosition(240 - 88, 64 + 24 + 24 * i);
            opt_dis->Draw();
        }

        for(int i = 0; i < 4; i++){
            opt_dis->SetPosition(240 + 88, 64 + 24 + 24 * i);
            opt_dis->Draw();
        }

        opt_unsel->SetPosition(240, 168 + 40);
        opt_unsel->Draw();
        if(selectPosY == 6){
            opt_sel->SetPosition(240, 168 + 40);
            opt_sel->Draw();
        }

        unselected->SetPosition(240, 240);
        unselected->Draw();
        if(selectPosY == 7){
            selected->SetPosition(240, 240);
            selected->Draw();
        }

        //Slider drawing

        //Mega slider
        slider->SetPosition(240 - 168 + (336 * Common::g_OptionsManager.options.soundCategory_master), 64);
        slider_sel->SetPosition(240 - 168 + (336 * Common::g_OptionsManager.options.soundCategory_master), 64);
        (selectPosY == 0) ? slider_sel->Draw() : slider->Draw();

        //Left side of sliders
        slider->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_music), 64 + 24);
        slider_sel->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_music), 64 + 24);
        (selectRegion == 0 && selectPosY == 1) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_weather), 64 + 48);
        slider_sel->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_weather), 64 + 48);
        (selectRegion == 0 && selectPosY == 2) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_hostile), 64 + 72);
        slider_sel->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_hostile), 64 + 72);
        (selectRegion == 0 && selectPosY == 3) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_player), 64 + 96);
        slider_sel->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_player), 64 + 96);
        slider->Draw();
        (selectRegion == 0 && selectPosY == 4) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_voice), 64 + 120);
        slider_sel->SetPosition(240 - 168 + (160 * Common::g_OptionsManager.options.soundCategory_voice), 64 + 120);
        slider->Draw();
        (selectPosY == 5) ? slider_sel->Draw() : slider->Draw();


        //Right side of sliders
        slider->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_record), 64 + 24);
        slider_sel->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_record), 64 + 24);
        slider->Draw();
        (selectRegion == 1 && selectPosY == 1) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_block), 64 + 48);
        slider_sel->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_block), 64 + 48);
        (selectRegion == 1 && selectPosY == 2) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_neutral), 64 + 72);
        slider_sel->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_neutral), 64 + 72);
        (selectRegion == 1 && selectPosY == 3) ? slider_sel->Draw() : slider->Draw();

        slider->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_ambient), 64 + 96);
        slider_sel->SetPosition(240 + 8 + (160 * Common::g_OptionsManager.options.soundCategory_ambient), 64 + 96);
        slider->Draw();
        (selectRegion == 1 && selectPosY == 4) ? slider_sel->Draw() : slider->Draw();

        //Text
        if(selectPosY == 6){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 208, "%s: %s", Common::g_TranslationOBJ.getText("options.showSubtitles").c_str(), (Common::g_OptionsManager.options.showSubtitles) ? Common::g_TranslationOBJ.getText("options.on").c_str() : Common::g_TranslationOBJ.getText("options.off").c_str());

        if(selectPosY == 7){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 240, Common::g_TranslationOBJ.getText("gui.done").c_str());

        if(selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 64, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.master").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_master * 100));

        if(selectRegion == 0 && selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240-88, 64 + 24, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.music").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_music * 100));

        if(selectRegion == 0 && selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240-88, 64 + 48, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.weather").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_weather * 100));

        if(selectRegion == 0 && selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240-88, 64 + 72, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.hostile").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_hostile * 100));
        
        if(selectRegion == 0 && selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240-88, 64 + 96, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.player").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_player * 100));

        if(selectPosY == 5){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240-88, 64 + 120, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.voice").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_voice * 100));


        if(selectRegion == 1 && selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240+88, 64 + 24, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.record").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_record * 100));

        if(selectRegion == 1 && selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240+88, 64 + 48, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.block").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_block * 100));

        if(selectRegion == 1 && selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240+88, 64 + 72, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.neutral").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_neutral * 100));
        
        if(selectRegion == 1 && selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240+88, 64 + 96, "%s: %d%%", Common::g_TranslationOBJ.getText("soundCategory.ambient").c_str(), (int)(Common::g_OptionsManager.options.soundCategory_ambient * 100));
    }

    void MenuState::optionsMusicScreenUpdate(){
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
            if(selectPosY > 7){
                selectPosY = 7;
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

            if(selectPosY == 0){
                Common::g_OptionsManager.options.soundCategory_master -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_master < 0){
                    Common::g_OptionsManager.options.soundCategory_master = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_master > 1){
                    Common::g_OptionsManager.options.soundCategory_master = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 1){
                Common::g_OptionsManager.options.soundCategory_music -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_music < 0){
                    Common::g_OptionsManager.options.soundCategory_music = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_music > 1){
                    Common::g_OptionsManager.options.soundCategory_music = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 2){
                Common::g_OptionsManager.options.soundCategory_weather -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_weather < 0){
                    Common::g_OptionsManager.options.soundCategory_weather = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_weather > 1){
                    Common::g_OptionsManager.options.soundCategory_weather = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 3){
                Common::g_OptionsManager.options.soundCategory_hostile -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_hostile < 0){
                    Common::g_OptionsManager.options.soundCategory_hostile = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_hostile > 1){
                    Common::g_OptionsManager.options.soundCategory_hostile = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 4){
                Common::g_OptionsManager.options.soundCategory_player -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_player < 0){
                    Common::g_OptionsManager.options.soundCategory_player = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_player > 1){
                    Common::g_OptionsManager.options.soundCategory_player = 1.0f;
                }
            }

            if(selectPosY == 5){
                Common::g_OptionsManager.options.soundCategory_voice -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_voice < 0){
                    Common::g_OptionsManager.options.soundCategory_voice = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_voice > 1){
                    Common::g_OptionsManager.options.soundCategory_voice = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 1){
                Common::g_OptionsManager.options.soundCategory_record -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_record < 0){
                    Common::g_OptionsManager.options.soundCategory_record = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_record > 1){
                    Common::g_OptionsManager.options.soundCategory_record = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 2){
                Common::g_OptionsManager.options.soundCategory_block -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_block < 0){
                    Common::g_OptionsManager.options.soundCategory_block = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_block > 1){
                    Common::g_OptionsManager.options.soundCategory_block = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 3){
                Common::g_OptionsManager.options.soundCategory_neutral -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_neutral < 0){
                    Common::g_OptionsManager.options.soundCategory_neutral = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_neutral > 1){
                    Common::g_OptionsManager.options.soundCategory_neutral = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 4){
                Common::g_OptionsManager.options.soundCategory_ambient -= 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_ambient < 0){
                    Common::g_OptionsManager.options.soundCategory_ambient = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_ambient > 1){
                    Common::g_OptionsManager.options.soundCategory_ambient = 1.0f;
                }
            }

        }
        if(KeyPressed(PSP_CTRL_RIGHT)){
            if(selectPosY == 0){
                Common::g_OptionsManager.options.soundCategory_master += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_master < 0){
                    Common::g_OptionsManager.options.soundCategory_master = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_master > 1){
                    Common::g_OptionsManager.options.soundCategory_master = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 1){
                Common::g_OptionsManager.options.soundCategory_music += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_music < 0){
                    Common::g_OptionsManager.options.soundCategory_music = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_music > 1){
                    Common::g_OptionsManager.options.soundCategory_music = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 2){
                Common::g_OptionsManager.options.soundCategory_weather += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_weather < 0){
                    Common::g_OptionsManager.options.soundCategory_weather = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_weather > 1){
                    Common::g_OptionsManager.options.soundCategory_weather = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 3){
                Common::g_OptionsManager.options.soundCategory_hostile += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_hostile < 0){
                    Common::g_OptionsManager.options.soundCategory_hostile = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_hostile > 1){
                    Common::g_OptionsManager.options.soundCategory_hostile = 1.0f;
                }
            }

            if(selectRegion == 0 && selectPosY == 4){
                Common::g_OptionsManager.options.soundCategory_player += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_player < 0){
                    Common::g_OptionsManager.options.soundCategory_player = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_player > 1){
                    Common::g_OptionsManager.options.soundCategory_player = 1.0f;
                }
            }

            if(selectPosY == 5){
                Common::g_OptionsManager.options.soundCategory_voice += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_voice < 0){
                    Common::g_OptionsManager.options.soundCategory_voice = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_voice > 1){
                    Common::g_OptionsManager.options.soundCategory_voice = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 1){
                Common::g_OptionsManager.options.soundCategory_record += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_record < 0){
                    Common::g_OptionsManager.options.soundCategory_record = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_record > 1){
                    Common::g_OptionsManager.options.soundCategory_record = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 2){
                Common::g_OptionsManager.options.soundCategory_block += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_block < 0){
                    Common::g_OptionsManager.options.soundCategory_block = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_block > 1){
                    Common::g_OptionsManager.options.soundCategory_block = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 3){
                Common::g_OptionsManager.options.soundCategory_neutral += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_neutral < 0){
                    Common::g_OptionsManager.options.soundCategory_neutral = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_neutral > 1){
                    Common::g_OptionsManager.options.soundCategory_neutral = 1.0f;
                }
            }

            if(selectRegion == 1 && selectPosY == 4){
                Common::g_OptionsManager.options.soundCategory_ambient += 0.01f;
                if(Common::g_OptionsManager.options.soundCategory_ambient < 0){
                    Common::g_OptionsManager.options.soundCategory_ambient = 0.0f;
                }
                if(Common::g_OptionsManager.options.soundCategory_ambient > 1){
                    Common::g_OptionsManager.options.soundCategory_ambient = 1.0f;
                }
            }
        }

        if(KeyPressed(PSP_CTRL_CROSS)){
            if(selectPosY == 6){
                Common::g_OptionsManager.options.showSubtitles = !Common::g_OptionsManager.options.showSubtitles;
            }
            if(selectPosY == 7){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = previous_states;
                previous_states = MENU_STATE_MUSIC;
            }
        }
    }

}
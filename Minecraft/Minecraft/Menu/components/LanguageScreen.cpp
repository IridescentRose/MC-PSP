#include "../MenuState.hpp"

namespace Minecraft::Menus{
    
	void MenuState::languageScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 5; y++){
                options_tile->RGB(32.0f, 32.0f, 32.0f);
                options_tile->SetPosition(x*32, y * 32 + 48.0f);
                options_tile->Draw();
            }
        }

        //Languages at top of screen
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 24 - 7, Common::g_TranslationOBJ.getText("options.language").c_str());

        //Language Disclaimer
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 208 - 7, ((std::string)("(" + Common::g_TranslationOBJ.getText("options.languageWarning") + ")")).c_str() );

        unselected->SetPosition(240, 232);
        unselected->Draw();

        if(selectRegion == 1){
            selected->SetPosition(240, 232);
            selected->Draw();
        }

        disabled->RGB(150.0f, 150.0f, 150.0f);
        disabled->SetPosition(240, 42 + langPosSel * 20);
        disabled->Draw();

        //Done button
        if(selectRegion != 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 240 - 7, Common::g_TranslationOBJ.getText("gui.done").c_str());

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        
        for(int i = 0; i < 8; i++){
            std::string res = Common::g_TranslationOBJ.availableTranslations()[i + langPos].name + " (" + Common::g_TranslationOBJ.availableTranslations()[i + langPos].region + ")";
            g_RenderCore.DebugPrint(240, 41 + i * 20, res.c_str());
        }
    }
	void MenuState::languageScreenUpdate(){

        if(KeyPressed(PSP_CTRL_RTRIGGER)){
            selectRegion++;
        }
        if(KeyPressed(PSP_CTRL_LTRIGGER)){
            selectRegion--;
        }
        if(selectRegion > 1){
            selectRegion = 1;
        }
        if(selectRegion < 0){
            selectRegion = 0;
        }

        if(selectRegion == 0){
            if(KeyPressed(PSP_CTRL_DOWN)){
                if(langPosSel == 7){
                    //Then we scroll down the actual pos
                    langPos++;
                    if(langPos > (langPosMax - 8)){
                        langPos = langPosMax - 8;
                    }
                }
                if(langPosSel != 7){
                    langPosSel++;
                }
            }
            if(KeyPressed(PSP_CTRL_UP)){
                if(langPosSel == 0){
                    langPos--;
                    if(langPos < 0){
                        langPos = 0;
                    }
                }

                if(langPosSel != 0){
                    langPosSel--;
                }
            }

            if(KeyPressed(PSP_CTRL_CROSS)){
                Common::g_TranslationOBJ.setTranslation(Common::g_TranslationOBJ.availableTranslations()[langPosSel + langPos].code.c_str());
                
                Common::g_OptionsManager.open();
                Common::g_OptionsManager.options.lang = Common::g_TranslationOBJ.availableTranslations()[langPosSel + langPos].code;
                Common::g_OptionsManager.close();
    
            }

        }else{
            if(KeyPressed(PSP_CTRL_CROSS)){
                menu_states = previous_states;
                previous_states = MENU_STATE_LANGUAGE;

                button->Play(0);

                selectRegion = 0;
            }
        }
    }
}
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
        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 24, Common::g_TranslationOBJ.getText("options.language").c_str());

        //Language Disclaimer
        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 208, ((std::string)("(" + Common::g_TranslationOBJ.getText("options.languageWarning") + ")")).c_str() );

        unselected->SetPosition(240, 232);
        unselected->Draw();

        //Done button
        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 240, Common::g_TranslationOBJ.getText("gui.done").c_str());

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        
        for(int i = 0; i < 8; i++){
            std::string res = Common::g_TranslationOBJ.availableTranslations()[i + langPos].name + " (" + Common::g_TranslationOBJ.availableTranslations()[i + langPos].region + ")";
            g_RenderManager.DebugPrint(240, 48 + i * 20, res.c_str());
        }
    }
	void MenuState::languageScreenUpdate(){

    }
}
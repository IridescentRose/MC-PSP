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

    }
}
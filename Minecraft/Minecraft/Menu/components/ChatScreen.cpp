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

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("options.chat.title").c_str());
        
    }
    void MenuState::optionsChatScreenUpdate(){
        
    }
}
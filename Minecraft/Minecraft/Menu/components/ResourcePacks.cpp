#include "../MenuState.hpp"

namespace Minecraft::Menus{
    
	void MenuState::optionsResourceScreenDraw(){
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
                options_tile->SetPosition(x*32, y * 32 + 48.0f);
                options_tile->Draw();
            }
        }


        //Languages at top of screen
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 24 - 7, Common::g_TranslationOBJ.getText("resourcePack.title").c_str());
        g_RenderCore.DebugPrint(160, 48 - 7, Common::g_TranslationOBJ.getText("resourcePack.available.title").c_str());
        g_RenderCore.DebugPrint(320, 48 - 7, Common::g_TranslationOBJ.getText("resourcePack.selected.title").c_str());

        unselected->SetPosition(240, 240);
        unselected->Draw();

        if(selectRegion == 2){
            selected->SetPosition(240, 240);
            selected->Draw();
        }

        //Done button
        if(selectRegion < 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 247 - 7, Common::g_TranslationOBJ.getText("gui.done").c_str());
    }

    void MenuState::optionsResourceScreenUpdate(){
        if(KeyPressed(PSP_CTRL_CROSS)){
            menu_states = previous_states;
            previous_states = MENU_STATE_RESOURCE_PACK;

            button->Play(0);

            selectRegion = 0;
        }
    }

}
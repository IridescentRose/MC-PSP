#include "../MenuState.hpp"
#include "../../Version.hpp"
namespace Minecraft::Menus{

	void MenuState::optionsSnooperScreenDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("options.snooper.title").c_str());


        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 6; y++){
                options_tile->RGB(32.0f, 32.0f, 32.0f);
                options_tile->SetPosition(x*32, y * 32 + 56.0f);
                options_tile->Draw();
            }
        }


        selected->SetPosition(240, 272 - 24);
        selected->Draw();

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);

        g_RenderCore.DebugPrint(240, 272 - 24, Common::g_TranslationOBJ.getText("gui.done").c_str());

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 48, "client_brand");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 48, "vanilla");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 60, "cpu_cores");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 60, "1");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 72, "display_frequency");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 72, "60");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 84, "display_type");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 84, "fullscreen");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 96, "endianness");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 96, "little");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 108, "fps_target");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 108, "60");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 120, "os_architecture");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 120, "allegrex64");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 132, "os_name");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 132, "PSP CFW");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 144, "os_version");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 144, "6.61");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 156, "max_memory");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 156, "32-64 MB");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 168, "graphics_vendor");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 168, "MIPS Technologies");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 180, "graphics_api_vendor");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 180, "Sony Computer Entertainment");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 192, "graphics_api_version");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 192, "1.0");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 204, "vsync");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 204, "enabled");

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 216, "version");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 216, EMULATED_VERSION);

        //LEFT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(4, 228, "internal_version");
        //RIGHT
        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
        g_RenderCore.DebugPrint(240, 228, INTERNAL_VERSION);

    }

	void MenuState::optionsSnooperScreenUpdate(){

        if(KeyPressed(PSP_CTRL_CROSS)){
            button->Play(0);
            selectPosX = 0;
            selectPosY = 0;
            selectRegion = 0;
            menu_states = previous_states;
            previous_states = MENU_STATE_SNOOPER;
        }
    }
}
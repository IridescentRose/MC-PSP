#include "../MenuState.hpp"

namespace Minecraft::Menus{
    
	void MenuState::controlDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        for(int i = 0; i < 8; i++){
            opt_unsel->SetPosition(120, 48 + 24 * i);
            opt_unsel->Draw();
        }

        for(int i = 0; i < 8; i++){
            opt_unsel->SetPosition(360, 48 + 24 * i);
            opt_unsel->Draw();
        }

        unselected->SetPosition(240, 256);
        unselected->Draw();



    }

	void MenuState::controlUpdate(){

    }
}
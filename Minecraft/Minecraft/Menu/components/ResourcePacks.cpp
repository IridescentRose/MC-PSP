#include "../MenuState.hpp"

namespace Minecraft::Menus {
	void MenuState::resourcePackScreenDraw() {
		for (int x = 0; x < 16; x++) {
			for (int y = 0; y < 9; y++) {
				options_tile->RGB(64.0f, 64.0f, 64.0f);
				options_tile->SetPosition(x * 32, y * 32);
				options_tile->Draw();
			}
		}

		for (int x = 0; x < 16; x++) {
			for (int y = 0; y < 6; y++) {
				options_tile->RGB(32.0f, 32.0f, 32.0f);
				options_tile->SetPosition(x * 32, y * 32 + 56.0f);
				options_tile->Draw();
			}
		}


	}

	void MenuState::resourcePackScreenUpdate() {

	}
}
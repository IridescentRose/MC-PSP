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

		if (selectRegion == 2) {
			selected->SetPosition(240, 272 - 24 - 7);
			selected->Draw();
		}
		else {
			unselected->SetPosition(240, 272 - 24 - 7);
			unselected->Draw();
		}

		//Find which packs aren't open!
		int unOpened = 0;
		int opened = 0;
		for (int i = 0; i < packData.size(); i++) {
			bool isActive = false;

			for (int c = 0; c < texPacksEnabled.size(); c++) {
				if (texPacksEnabled[c] == packData[i].name) {
					isActive = true;
				}
			}

			//Draw on left
			if (!isActive) {
				if (selectPosY == unOpened && selectRegion == 0) {
					g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
				}
				else {
					g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
				}
				g_RenderManager.DebugPrint(100, 80 + unOpened * 20, "%s", packData[i].name.c_str());
				unOpened++;
			}
			else {
				if (selectPosY == opened && selectRegion == 1) {
					g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
				}
				else {
					g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
				}
				g_RenderManager.DebugPrint(340, 80 + opened * 20, "%s", packData[i].name.c_str());
				opened++;
			}
		}
		if (selectPosY == opened && selectRegion == 1) {
			g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
		}
		else {
			g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
		}
		g_RenderManager.DebugPrint(340, 80 + opened * 20, "Default");


		if (selectPosY > opened && selectRegion == 1) {
			selectPosY = opened;
		}else if(selectPosY > unOpened && selectRegion == 0){
			selectPosY = unOpened;
		}

		if (Input::KeyPressed(PSP_CTRL_CROSS)) {
			g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);

			if (selectRegion == 0) {

				int z = 0;

				for (int i = 0; i < packData.size(); i++) {
					bool isActive = false;

					for (int c = 0; c < texPacksEnabled.size(); c++) {
						if (texPacksEnabled[c] == packData[i].name) {
							isActive = true;
						}
					}

					//Draw on left
					if (!isActive) {
						if (z == selectPosY) {
							texPacksEnabled.push_back(packData[i].name);
						}
					}
				}
			}
			else if (selectRegion == 1) {
				if(texPacksEnabled.size() > 0)
					texPacksEnabled.pop_back();
			}

		}





		if (selectRegion == 2) {
			g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
		}
		else {
			g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
		}
		g_RenderManager.DebugPrint(240, 240, Common::g_TranslationOBJ.getText("gui.done").c_str());


		g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
		g_RenderManager.DebugPrint(240, 20, Common::g_TranslationOBJ.getText("resourcePack.title").c_str());

		g_RenderManager.DebugPrint(160, 60, Common::g_TranslationOBJ.getText("resourcePack.available.title").c_str());
		g_RenderManager.DebugPrint(320, 60, Common::g_TranslationOBJ.getText("resourcePack.selected.title").c_str());
	}

	void MenuState::resourcePackScreenUpdate() {
		if (Input::KeyPressed(PSP_CTRL_RTRIGGER)) {
			g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
			selectRegion++;
			if (selectRegion > 2) {
				selectRegion = 2;
			}
		}

		if (Input::KeyPressed(PSP_CTRL_LTRIGGER)) {
			g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
			selectRegion--;
			if (selectRegion < 0) {
				selectRegion = 0;
			}
		}

		if (Input::KeyPressed(PSP_CTRL_UP)) {
			selectPosY--;
			if (selectPosY < 0) {
				selectPosY = 0;
			}
		}
		if (Input::KeyPressed(PSP_CTRL_UP)) {
			selectPosY++;
		}

		if (Input::KeyPressed(PSP_CTRL_CROSS)) {
			g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);

			if (selectRegion == 2) {
				selectPosX = 0;
				selectPosY = 0;
				selectRegion = 0;
				menu_states = previous_states;
				previous_states = MENU_STATE_RESOURCE_PACKS;
			}
		}
	}
}
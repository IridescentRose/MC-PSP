#include "../MenuState.hpp"

#include <Shadow/System/NetworkDriver.h>
#include <Shadow/System/Dialogs.h>
#include "../../Client/GameClient.hpp"
using namespace Shadow::System;

namespace Minecraft::Menus{
    
	void MenuState::optionsMultiplayerScreenDraw(){
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

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(240, 24, Common::g_TranslationOBJ.getText("multiplayer.title").c_str());
        
        miniDis->SetPosition(136, 272 - 32);
        miniDis->Draw();
        

        if(selectPosY == 0 && selectPosX == 1){
            miniSel->SetPosition(240, 272 - 32);
            miniSel->Draw();
        }else{
            miniUnSel->SetPosition(240, 272 - 32);
            miniUnSel->Draw();
        }

        if(selectPosY == 0 && selectPosX == 2){
            miniSel->SetPosition(344, 272 - 32);
            miniSel->Draw();
        }else{
            miniUnSel->SetPosition(344, 272 - 32);
            miniUnSel->Draw();
        }

        tinyDis->SetPosition(124, 272 - 10);
        tinyDis->Draw();

        tinyDis->SetPosition(201, 272 - 10);
        tinyDis->Draw();

        if(selectPosY == 1 && selectPosX == 2){
            tinySel->SetPosition(279, 272 - 10);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(279, 272 - 10);
            tinyUnSel->Draw();
        }


        if(selectPosY == 1 && selectPosX == 3){
            tinySel->SetPosition(356, 272 - 10);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(356, 272 - 10);
            tinyUnSel->Draw();
        }

        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF777777, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderManager.DebugPrint(136, 272 - 32, Common::g_TranslationOBJ.getText("selectServer.select").c_str());
        g_RenderManager.DebugPrint(124, 272 - 10, Common::g_TranslationOBJ.getText("selectServer.edit").c_str());
        g_RenderManager.DebugPrint(201, 272 - 10, Common::g_TranslationOBJ.getText("selectServer.delete").c_str());

        if(selectPosY == 0 && selectPosX == 1){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(240, 272 - 32, Common::g_TranslationOBJ.getText("selectServer.direct").c_str());

        if(selectPosY == 0 && selectPosX == 2){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(344, 272 - 32, Common::g_TranslationOBJ.getText("selectServer.add").c_str());

        if(selectPosY == 1 && selectPosX == 2){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(279, 272 - 10, Common::g_TranslationOBJ.getText("selectServer.refresh").c_str());

        if(selectPosY == 1 && selectPosX == 3){
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderManager.DebugPrint(356, 272 - 10, Common::g_TranslationOBJ.getText("gui.cancel").c_str());

    }
	void MenuState::optionsMultiplayerScreenUpdate(StateManager* sManager){

		if (!tryConnect && !connected) {
			Network::Init();

			bool res = Network::dialogConnect();
			connected = res;
			tryConnect = true;
			
			if (connected) {
				//Ask for username
				//GET USER

				unsigned short test2[16];
				unsigned short opis2[9] = { 'U', 's', 'e', 'r', 'n', 'a', 'm', 'e', '\0' };
				if (Dialogs::ShowOSK(opis2, test2, 16) != -1)
				{
					for (int j = 0; test2[j]; j++)
					{
						unsigned c = test2[j];

						if (32 <= c && c <= 127) // print ascii only
							username += c;
					}

				}

				//TODO: STORE USERNAME!!!
			}
			else {
				Network::Cleanup(); //Fixes crashing.
			}
			
		}

if(Input::KeyPressed(PSP_CTRL_UP)){
                    selectPosY--;

                    if(selectPosY < 0){
                        selectPosY = 0;
                    }
                    
                        if(selectPosX > 2){
                            selectPosX = 2;
                        }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
                if(Input::KeyPressed(PSP_CTRL_DOWN)){
                    selectPosY++;

                    if(selectPosY > 1){
                        selectPosY = 1;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
                if(Input::KeyPressed(PSP_CTRL_LEFT)){
                    selectPosX--;

                    if(selectPosX < 0){
                        selectPosX = 0;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
                if(Input::KeyPressed(PSP_CTRL_RIGHT)){
                    selectPosX++;

                    if(selectPosX > 3){
                        selectPosX = 3;
                    }
                    if(selectPosY == 0 && selectPosX > 2){
                        selectPosX = 2;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
        if(Input::KeyPressed(PSP_CTRL_CROSS)){

            g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
            if(selectPosX == 3){
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = previous_states;
                previous_states = MENU_STATE_MULTIPLAYER;
				tryConnect = false;
            }
			if (selectPosX == 1 && selectPosY == 0) {

				unsigned short test2[15];
				unsigned short opis2[11] = { 'I', 'P', ' ', 'A', 'd', 'd', 'r', 'e', 's', 's', '\0' };
				if (Dialogs::ShowOSK(opis2, test2, 15) != -1)
				{
					for (int j = 0; test2[j]; j++)
					{
						unsigned c = test2[j];

						if (32 <= c && c <= 127) // print ascii only
							ipaddr += c;
					}

				}

				Client::ClientState* client = new Client::ClientState();
				client->connect_info.ip_address = ipaddr;
				client->connect_info.username = username;

				client->Init(); //Connect!
				//TODO: CHECK CONNECTION FAILS?
				sManager->PushState(client);

			}
        }
    }
}
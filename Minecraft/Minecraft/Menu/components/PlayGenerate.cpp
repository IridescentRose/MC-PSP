#include "../MenuState.hpp"

#include "../../Client/SPClient.hpp"
#include <Graphics/Dialogs.h>

namespace Minecraft::Menus{
    void MenuState::playGenerateDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }

        disabled->SetPosition(240, 60);
        disabled->Draw();

        disabled->SetPosition(240, 100);
        disabled->Draw();

        if(selectPosY == 2){
            selected->SetPosition(240, 160);
            selected->Draw();
        }else{
            unselected->SetPosition(240, 160);
            unselected->Draw();
        }

        if(selectPosY == 3){
            selected->SetPosition(240, 220);
            selected->Draw();
        }else{
            unselected->SetPosition(240, 220);
            unselected->Draw();
        }

        if(selectPosY == 4){
            selected->SetPosition(240, 250);
            selected->Draw();
        }else{
            unselected->SetPosition(240, 250);
            unselected->Draw();
        }

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("selectWorld.create").c_str());
        g_RenderCore.DebugPrint(240, 44, Common::g_TranslationOBJ.getText("selectWorld.enterName").c_str());
        g_RenderCore.DebugPrint(240, 84, Common::g_TranslationOBJ.getText("selectWorld.enterSeed").c_str());




        if(selectPosY == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        
        //g_RenderCore.DebugPrint(240, 60, Terrain::WorldProvider::worldName.c_str());

        if(selectPosY == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        
        g_RenderCore.DebugPrint(240, 100, seedName.c_str());



        if(selectPosY == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }

        std::string modeSelect = "";


        switch(Client::g_World->gameMode){
            case 0:{
                modeSelect = Common::g_TranslationOBJ.getText("gameMode.survival");
                break;
            }
            case 1:{
                modeSelect = Common::g_TranslationOBJ.getText("gameMode.creative");
                break;
            }
            case 2:{
                modeSelect = Common::g_TranslationOBJ.getText("gameMode.adventure");
                break;
            }
            case 3:{
                modeSelect = Common::g_TranslationOBJ.getText("gameMode.spectator");
                break;
            }
            case 4:{
                modeSelect = Common::g_TranslationOBJ.getText("gameMode.hardcore");
                break;
            }
        }

        g_RenderCore.DebugPrint(240, 160, (Common::g_TranslationOBJ.getText("selectWorld.gameMode") + ": " + modeSelect).c_str());

        if(selectPosY == 3){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        
        g_RenderCore.DebugPrint(240, 220, Common::g_TranslationOBJ.getText("gui.done").c_str());


        if(selectPosY == 4){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(240, 250, Common::g_TranslationOBJ.getText("gui.cancel").c_str());

    }

    unsigned long int hashString(std::string s){
        const int A = 54059;
        const int B = 76963;
        const int FIRST = 37;

        unsigned long int h = FIRST;

        for(int i = 0; i < s.length(); i++){
            h = (h * A) ^ (s.at(i) * B);
        }

        return h;
    }    

	void MenuState::playGenerateUpdate(StateManager* sManager){




        if(KeyPressed(PSP_CTRL_CROSS)){

        if(selectPosY == 0){
                unsigned short test2[16];

        for(int i = 0; i < 16; i++){
            test2[i] = '\0';
        }
		unsigned short opis2[5] = { 'N', 'a', 'm', 'e', '\0' };
		if (ShowOSK(opis2, test2, 16) != -1)
		{

        Terrain::WorldProvider::worldName = "";
			for (int j = 0; test2[j]; j++)
			{
				unsigned c = test2[j];
				if (32 <= c && c <= 127) // print ascii only
					Terrain::WorldProvider::worldName += c;
			}
		}


        
            }

            if(selectPosY == 1){
                unsigned short test2[16];

        for(int i = 0; i < 16; i++){
            test2[i] = '\0';
        }
		unsigned short opis2[5] = { 'S', 'e', 'e', 'd', '\0' };
		if (ShowOSK(opis2, test2, 16) != -1)
		{
			for (int j = 0; test2[j]; j++)
			{
				unsigned c = test2[j];
				if (32 <= c && c <= 127) // print ascii only
					seedName += c;
			}
		}
        
		        Terrain::WorldProvider::seed = hashString(seedName);
            }

            if(selectPosY == 4){
                //Return
                selectPosX = 0;
                selectPosY = 0;
                selectRegion = 0;
                menu_states = previous_states;
                previous_states = MENU_STATE_PLAY_GENERATE;
            }
            if(selectPosY == 3){
                //Generate
               Client::terrain_atlas = TextureUtil::LoadPng("assets/minecraft/textures/terrain_atlas.png");
                
                gm = Client::g_World->gameMode;
                Client::SPClient* client = new Client::SPClient();
						
		        client->Init();

                
                Client::g_World->gameMode = gm;
                Client::g_World->handleGM();
		        sManager->PushState(client);
            }

            if(selectPosY == 2){
                Client::g_World->gameMode++;
                if(Client::g_World->gameMode > 4){
                    Client::g_World->gameMode = 0;
                }
            }
        }
        if(KeyPressed(PSP_CTRL_UP)){
            selectPosY--;
            if(selectPosY < 0){
                selectPosY = 0;
            }
        }
        if(KeyPressed(PSP_CTRL_DOWN)){
            selectPosY++;
            if(selectPosY > 4){
                selectPosY = 4;
            }
            
        }

        /*
        
        
        
        */
    }
}
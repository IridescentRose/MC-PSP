#include "../MenuState.hpp"

#include "../../Client/SPClient.hpp"
#include <Shadow/System/Dialogs.h>

using namespace Shadow::System;

namespace Minecraft::Menus{
    void MenuState::playGenerateDraw(){
        for(int x = 0; x < 16; x++){
            for(int y = 0; y < 9; y++){
                options_tile->RGB(64.0f, 64.0f, 64.0f);
                options_tile->SetPosition(x * 32, y * 32);
                options_tile->Draw();
            }
        }


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
        unsigned short test2[16];

        for(int i = 0; i < 16; i++){
            test2[i] = '\0';
        }
        std::string seed;
		unsigned short opis2[5] = { 'S', 'e', 'e', 'd', '\0' };
		if (Dialogs::ShowOSK(opis2, test2, 16) != -1)
		{
			for (int j = 0; test2[j]; j++)
			{
				unsigned c = test2[j];
				if (32 <= c && c <= 127) // print ascii only
					seed += c;
			}
		}
        terrain_atlas = TextureUtil::LoadPng("assets/minecraft/textures/terrain_atlas.png");
		Terrain::WorldProvider::seed = hashString(seed);
        
        Client::SPClient* client = new Client::SPClient();
						
		client->Init();

		sManager->PushState(client);
        
    }
}
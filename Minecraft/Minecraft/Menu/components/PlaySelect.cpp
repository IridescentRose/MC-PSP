#include "../MenuState.hpp"

#include <dirent.h>
#include <sys/stat.h>


#include <Graphics/Dialogs.h>

#include "../../Client/SPClient.hpp"

void remove_dir(char *path)
{
        struct dirent *entry = NULL;
        DIR *dir = NULL;
        dir = opendir(path);
        while(entry = readdir(dir))
        {   
                DIR *sub_dir = NULL;
                FILE *file = NULL;
                char abs_path[100] = {0};
                if(*(entry->d_name) != '.')
                {   
                        sprintf(abs_path, "%s/%s", path, entry->d_name);
                        if(sub_dir = opendir(abs_path))
                        {   
                                closedir(sub_dir);
                                remove_dir(abs_path);
                        }   
                        else 
                        {   
                                if(file = fopen(abs_path, "r"))
                                {   
                                        fclose(file);
                                        remove(abs_path);
                                }   
                        }   
                }   
        }   
        remove(path);
}

namespace Minecraft::Menus{
    void MenuState::playSelectDraw(){
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

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(240, 16, Common::g_TranslationOBJ.getText("selectWorld.title").c_str());

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 0){
            opt_sel->SetPosition(156, 236);
            opt_sel->Draw();
        }else{
            opt_unsel->SetPosition(156, 236);
            opt_unsel->Draw();
        }

        for(int i = 0; i < 8; i++){

            if(i + loadPos < entries.size()){
                if(i + loadPos == loadPosSel){
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderCore.DebugPrint(240, 41 + i * 20, entries[i + loadPos].c_str());
            }
        }

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 1){
            opt_sel->SetPosition(324, 236);
            opt_sel->Draw();
        }else{
            opt_unsel->SetPosition(324, 236);
            opt_unsel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 2){
            tinySel->SetPosition(368, 256);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(368, 256);
            tinyUnSel->Draw();
        }
        
        tinyDis->SetPosition(280, 256);
        tinyDis->Draw();


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 0){
            tinySel->SetPosition(112, 256);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(112, 256);
            tinyUnSel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 1){
            tinySel->SetPosition(200, 256);
            tinySel->Draw();
        }else{
            tinyUnSel->SetPosition(200, 256);
            tinyUnSel->Draw();
        }

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(156, 236, Common::g_TranslationOBJ.getText("selectWorld.select").c_str());

        if(selectRegion == 1 && selectPosY == 0 && selectPosX == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(324, 236, Common::g_TranslationOBJ.getText("selectWorld.create").c_str());


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 2){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(368, 256, Common::g_TranslationOBJ.getText("gui.cancel").c_str());

        g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        g_RenderCore.DebugPrint(280, 256, Common::g_TranslationOBJ.getText("selectWorld.recreate").c_str());


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 0){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(112, 256, Common::g_TranslationOBJ.getText("selectWorld.edit").c_str());


        if(selectRegion == 1 && selectPosY == 1 && selectPosX == 1){
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }else{
            g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        }
        g_RenderCore.DebugPrint(200, 256, Common::g_TranslationOBJ.getText("selectWorld.delete").c_str());

    }
    void MenuState::playSelectUpdate(StateManager* sManager){
        if(KeyPressed(PSP_CTRL_RTRIGGER)){
            selectRegion++;
        }

        if(KeyPressed(PSP_CTRL_LTRIGGER)){
            selectRegion--;
        }

        if(selectRegion < 0){
            selectRegion = 0;
        }

        if(selectRegion > 1){
            selectRegion = 1;
        }



        if(selectRegion == 1){
            if(KeyPressed(PSP_CTRL_UP)){
                selectPosY--;
            }
            if(KeyPressed(PSP_CTRL_DOWN)){
                selectPosY++;
            }

            if(selectPosY > 1){
                selectPosY = 1;
            }

            if(selectPosY < 0){
                selectPosY = 0;
            }


            if(KeyPressed(PSP_CTRL_LEFT)){
                selectPosX--;
            }

            if(KeyPressed(PSP_CTRL_RIGHT)){
                selectPosX++;
            }

            if(selectPosY == 1){
                if(selectPosX > 2){
                    selectPosX = 2;
                }
            }

            if(selectPosX < 0){
                selectPosX = 0;
            }

            if(selectPosY == 0){
                if(selectPosX > 1){
                    selectPosX = 1;
                }
            }

        }else{
            if(KeyPressed(PSP_CTRL_UP)){
                loadPosSel--;
            }
            if(KeyPressed(PSP_CTRL_DOWN)){
                loadPosSel++;
            }

        }

        if(loadPosSel >= entries.size()){
                loadPosSel = entries.size() - 1;
            }

            if(loadPosSel < 0){
                loadPosSel = 0;
            }

            if(loadPosSel - loadPos > 8){
                loadPos++;
            }

            if(loadPosSel - loadPos < 0){
                loadPos--;
            }

            if(loadPos < 0){
                loadPos = 0;
            }
            if(loadPos > entries.size() - 9){
                loadPos = entries.size() - 9;
            }

        if(KeyPressed(PSP_CTRL_CROSS)){
            if(selectRegion == 1){
                
                if(entries.size() > 0 ){
                    
                if(selectPosY == 0 && selectPosX == 0){
                    
                    Terrain::WorldProvider::worldName = entries[loadPosSel];
                    
                    Client::terrain_atlas = TextureUtil::LoadPng("assets/minecraft/textures/terrain_atlas.png");

                    //LOAD WORLD!
                    Client::SPClient* client = new Client::SPClient();
						
		            client->Init();

		            sManager->PushState(client);
                }

                if(selectPosY == 1 && selectPosX == 0){
                    //RENAME
                    
                    unsigned short test2[16];
                    std::string newName = entries[loadPosSel];

                    for(int i = 0; i < 16; i++){
                        test2[i] = '\0';
                    }
		            unsigned short opis2[5] = { 'N', 'a', 'm', 'e', '\0' };
		
                    if (ShowOSK(opis2, test2, 16) != -1){
                        newName = "";
			            for (int j = 0; test2[j]; j++){
				            unsigned c = test2[j];
				            if (32 <= c && c <= 127) // print ascii only
					            newName += c;
			            }
		            }
        

                    rename(("saves/" + entries[loadPosSel]).c_str(), ("saves/" + newName).c_str());

                    DIR *dir;
                    struct dirent *ent;
                    entries.clear();
                    if ((dir = opendir ("saves/")) != NULL) {
                        while ((ent = readdir (dir)) != NULL) {
                            if(std::string(ent->d_name) != "." &&  std::string(ent->d_name) != ".."){
                                struct stat buffer;

                                if(stat( ("saves/" + std::string(ent->d_name) + "/level.dat").c_str(), &buffer) == 0)
                                    entries.push_back(std::string(ent->d_name));
                            }
                        }
                        closedir (dir);
                    }
                }

                if(selectPosY == 1 && selectPosX == 1){
                    //DELETE
                    remove_dir((char*) ("saves/" + entries[loadPosSel] + "/").c_str());

                    DIR *dir;
                    struct dirent *ent;
                    entries.clear();
                    if ((dir = opendir ("saves/")) != NULL) {
                        while ((ent = readdir (dir)) != NULL) {
                            if(std::string(ent->d_name) != "." &&  std::string(ent->d_name) != ".."){
                                struct stat buffer;

                                if(stat( ("saves/" + std::string(ent->d_name) + "/level.dat").c_str(), &buffer) == 0)
                                    entries.push_back(std::string(ent->d_name));
                            }
                        }
                        closedir (dir);
                    }
                }

                }


                if(selectPosY == 0 && selectPosX == 1){
                    //Create New

                    selectPosX = 0;
                    selectPosY = 0;
                    selectRegion = 0;
                    previous_states = menu_states;

                    menu_states = MENU_STATE_PLAY_GENERATE;
                }

                if(selectPosY == 1 && selectPosX == 2){
                    //Cancel!
                    selectPosX = 0;
                    selectPosY = 0;
                    selectRegion = 0;
                    menu_states = MENU_STATE_TITLE;
                    previous_states = MENU_STATE_LOAD_SELECT;
                }


            }
        }
    }
}
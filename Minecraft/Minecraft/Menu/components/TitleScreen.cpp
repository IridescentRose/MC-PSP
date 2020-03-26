#include "../MenuState.hpp"
//#include "../../Client/SPClient.hpp"
#include <dirent.h>
#include <sys/stat.h>
namespace Minecraft::Menus{
        
    void MenuState::titleScreenDraw(){
        sceGuDisable(GU_DEPTH_TEST);
			    sceGuEnable(GU_BLEND);

                //275 total
                //Centre = 142
                //Cetnre should be at 240
                //First is 155 - 142

                Minecraft1->SetPosition( 240 - (142 - 84), 60);
                Minecraft1->Draw();

                Minecraft2->SetPosition(240 + (142 - 64), 60);
                Minecraft2->Draw();




                unselected->SetPosition(240, 136);
                unselected->Draw();

                unselected->SetPosition(240, 156 + 6);
                unselected->Draw();

                unselected->SetPosition(240, 176 + 12);
                unselected->Draw();

                lang->SetPosition(124, 224);
                lang->Draw();

                miniUnSel->SetPosition(188, 224);
                miniUnSel->Draw();

                miniUnSel->SetPosition(292, 224);
                miniUnSel->Draw();

                if(selectPosY >= 0 && selectPosY <= 2){
                    selected->SetPosition(240, 136 + 26 * selectPosY);
                    selected->Draw();
                }else{
                    //Special select!
                    if(selectPosX == 0){
                        hlang->SetPosition(124, 224);
                        hlang->Draw();
                    }else{
                        miniSel->SetPosition(188 + (selectPosX-1) * (292 - 188), 224);
                        miniSel->Draw();
                    }
                }

                //SELECTED SYSTEM


                //Labels
                if(selectPosY == 0){
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderCore.DebugPrint(240, 136, Common::g_TranslationOBJ.getText("menu.singleplayer").c_str());

                if(selectPosY == 1){
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderCore.DebugPrint(240, 162, Common::g_TranslationOBJ.getText("menu.multiplayer").c_str());

                if(selectPosY == 2){
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderCore.DebugPrint(240, 188, Common::g_TranslationOBJ.getText("menu.online").c_str());

                if(selectPosY == 3 && selectPosX == 1){
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderCore.DebugPrint(188, 224, Common::g_TranslationOBJ.getText("menu.options").c_str());

                if(selectPosY == 3 && selectPosX == 2){
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderCore.DebugPrint(292, 224, Common::g_TranslationOBJ.getText("menu.quit").c_str());


                //FOOT NOTES!

                g_RenderCore.SetFontStyle(splashSize, 0xFF00FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                g_RenderCore.DebugPrint(344, 72, "%s", splashText.c_str());

                g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
                g_RenderCore.DebugPrint(0, 272 - 7, " %s %s", GAME_NAME, EMULATED_VERSION);

                g_RenderCore.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_RIGHT, 0.0f);
                g_RenderCore.DebugPrint(480, 272 - 7, "Copyright Mojang AB. Do not distribute! ");

    }

    void MenuState::titleScreenUpdate(StateManager* sManager){

		splashSize = vfpu_sinf(elapsed * 2 * 2 * 3.14159f) * (0.618f - (1.0f - 0.618f)) / 8 + (1.0f - 0.687f) * 2;
                if(KeyPressed(PSP_CTRL_UP)){
                    selectPosY--;

                    if(selectPosY < 0){
                        selectPosY = 0;
                    }
                    button->Play(0);
                }
                if(KeyPressed(PSP_CTRL_DOWN)){
                    selectPosY++;

                    if(selectPosY > 3){
                        selectPosY = 3;
                    }
                    button->Play(0);
                }
                if(KeyPressed(PSP_CTRL_LEFT)){
                    selectPosX--;

                    if(selectPosX < 0){
                        selectPosX = 0;
                    }
                    button->Play(0);
                }
                if(KeyPressed(PSP_CTRL_RIGHT)){
                    selectPosX++;

                    if(selectPosX > 2){
                        selectPosX = 2;
                    }
                    button->Play(0);
                }

                if(KeyPressed(PSP_CTRL_START)){
                    sceKernelExitGame();
                }

                if(KeyPressed(PSP_CTRL_CROSS)){
                    if(selectPosY == 0){
                        //SINGLE PLAYER MENU
                        selectPosX = 0;
                        selectPosY = 0;
                        selectRegion = 0;
                        previous_states = menu_states;
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
                        menu_states = MENU_STATE_LOAD_SELECT;
                        //Terrain::WorldProvider::seed = rand();

                        

                    }
                    if(selectPosY == 1){
                        //MP MENU
                        selectPosX = 0;
                        selectPosY = 0;
                        previous_states = menu_states;
                        menu_states = MENU_STATE_MULTIPLAYER;
                    }
                    if(selectPosY == 2){
                        //MINECRAFT REALMS MENU
                    }

                    if(selectPosY == 3){
                        if(selectPosX == 0){
                            //LANGUAGE MENU
                            selectPosX = 0;
                            selectPosY = 0;

                            previous_states = menu_states;
                            menu_states = MENU_STATE_LANGUAGE;
                        }
                        if(selectPosX == 1){
                            //OPTIONS MENU
                            selectPosX = 0;
                            selectPosY = 0;
                            previous_states = menu_states;
                            menu_states = MENU_STATE_OPTIONS_MAIN;
                        }
                        if(selectPosX == 2){
                            //QUIT
                            sceKernelExitGame();
                        }
                    }
                }

    }

}
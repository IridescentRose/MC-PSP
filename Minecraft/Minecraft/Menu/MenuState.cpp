#include "MenuState.hpp"

#include <Aurealis/Graphics/RenderManager.h>
#include <string>
#include <fstream>
#include "../Version.hpp"
#include <sstream>

#define PSP_MENU_SIZE 0.8
namespace Minecraft::Menus{

	MenuState::MenuState(){
        elapsed = 0;
        dt = 0;
        selectPosY = selectPosX = 0;
    }

    MenuState::~MenuState(){

    }

	void MenuState::Init(){
        t = Timer();
        //BGM!!!
        srand(time(0));
	    int musicChoice = rand() % 4 + 1; //1 - 4
        std::stringstream ss;
        ss << "./assets/sounds/ambient/menu/menu";
        ss << musicChoice;
        ss << ".bgm";

	    bgm = oslLoadSoundFile(ss.str().c_str(),OSL_FMT_STREAM);
        button = oslLoadSoundFile("./assets/sounds/other/button1.wav", 0);
	    g_AudioManager.PlayMusic(bgm);

        panorama = new Panorama();

        menu_states = MENU_STATE_TITLE;

        logo = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/logo.png");
        Logo = new Sprite(logo);
        Logo->Scale(0.9375f, 0.9375f);

        std::ifstream infile("./assets/minecraft/texts/splashes.txt");

        std::vector<std::string> splashes;

        std::string temp;
	    while(std::getline(infile, temp)){
		    splashes.push_back(temp);
	    }
	
	    srand(time(0));
	    int chosen = rand() % splashes.size();
	
	    splashText = splashes[chosen];

        selectPosY = 0;
        selectPosX = 1;

        widgets = TextureUtil::LoadPng("./assets/minecraft/textures/gui/widgets.png");
        disabled = new Sprite(widgets, 0, 46, 200, 20);
        unselected = new Sprite(widgets, 0, 66, 200, 20);
        selected = new Sprite(widgets, 0, 86, 200, 20);

        lang = new Sprite(widgets, 0, 106, 20, 20);
        hlang = new Sprite(widgets, 0, 126, 20, 20);
    }

	void MenuState::Enter(){

    }
	void MenuState::CleanUp(){

        delete panorama;

        //BGM!!!
        oslDeleteSound(bgm);
    }

	void MenuState::Pause(){

    }
	void MenuState::Resume(){

    }

	void MenuState::HandleEvents(StateManager* sManager){

    }
	void MenuState::Update(StateManager* sManager){
        dt = t.GetDeltaTime();
        elapsed += dt;

        g_System.InputUpdate();
        switch(menu_states){
            case MENU_STATE_TITLE:{
                if(g_System.KeyPressed(PSP_CTRL_UP)){
                    selectPosY--;

                    if(selectPosY < 0){
                        selectPosY = 0;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
                if(g_System.KeyPressed(PSP_CTRL_DOWN)){
                    selectPosY++;

                    if(selectPosY > 3){
                        selectPosY = 3;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
                if(g_System.KeyPressed(PSP_CTRL_LEFT)){
                    selectPosX--;

                    if(selectPosX < 0){
                        selectPosX = 0;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }
                if(g_System.KeyPressed(PSP_CTRL_RIGHT)){
                    selectPosX++;

                    if(selectPosX > 2){
                        selectPosX = 2;
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }

                if(g_System.KeyPressed(PSP_CTRL_START)){
                    sceKernelExitGame();
                }

                if(g_System.KeyPressed(PSP_CTRL_CROSS)){
                    if(selectPosY == 0){
                        //SINGLE PLAYER MENU
                    }
                    if(selectPosY == 1){
                        //MULTI PLAYER MENU
                    }
                    if(selectPosY == 2){
                        //MINECRAFT REALMS MENU
                    }

                    if(selectPosY == 3){
                        if(selectPosX == 0){
                            //LANGUAGE MENU
                        }
                        if(selectPosX == 1){
                            //OPTIONS MENU
                        }
                        if(selectPosX == 2){
                            //QUIT
                            sceKernelExitGame();
                        }
                    }
                    g_AudioManager.PlaySound(button, AUDIO_CHANNEL_GUI);
                }

                break;
            }
        }

        splashSize = vfpu_sinf(elapsed * 3.14159f) * (0.618f - (1.0f - 0.618f))/4.0f + (1.0f - 0.687f)*2 ;
    }
    

	void MenuState::Draw(StateManager* sManager){
        g_RenderManager.StartFrame(0, 0, 0);

        g_RenderManager.SetPerspective(75, 480.0f / 272.0f, 0.3f, 1000.0f); //Into 3D Mode for panorama

        panoramaPass();

        g_RenderManager.SetOrtho(0,0,0,0,0,0); //Into 2D Mode for menu pass

        menuPass();

        g_RenderManager.EndFrame();
    }
    


    void MenuState::menuPass(){
        switch(menu_states){
            case MENU_STATE_TITLE:{

			    sceGuDisable(GU_DEPTH_TEST);
			    sceGuEnable(GU_BLEND);

                Logo->SetPosition(240, 60);
                Logo->Draw();




                unselected->SetPosition(240, 136);
                unselected->Draw();

                unselected->SetPosition(240, 156 + 6);
                unselected->Draw();

                unselected->SetPosition(240, 176 + 12);
                unselected->Draw();

                lang->SetPosition(124, 224);
                lang->Draw();

                unselected->Scale(0.48f, 1.0f);
                unselected->SetPosition(188, 224);
                unselected->Draw();

                unselected->SetPosition(292, 224);
                unselected->Draw();
                unselected->Scale(1/ 0.48f, 1.0f);

                if(selectPosY >= 0 && selectPosY <= 2){
                    selected->SetPosition(240, 136 + 26 * selectPosY);
                    selected->Draw();
                }else{
                    //Special select!
                    if(selectPosX == 0){
                        hlang->SetPosition(124, 224);
                        hlang->Draw();
                    }else{
                        selected->Scale(0.48f, 1.0f);
                        selected->SetPosition(188 + (selectPosX-1) * (292 - 188), 224);
                        selected->Draw();
                        selected->Scale(1.0f / 0.48f, 1.0f);
                    }
                }

                //SELECTED SYSTEM


                //Labels
                if(selectPosY == 0){
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderManager.DebugPrint(240, 136 + 7, "Singleplayer");

                if(selectPosY == 1){
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderManager.DebugPrint(240, 162 + 7, "Multiplayer");

                if(selectPosY == 2){
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderManager.DebugPrint(240, 188 + 7, "Minecraft Realms");

                if(selectPosY == 3 && selectPosX == 1){
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderManager.DebugPrint(188, 224 + 7, "Options");

                if(selectPosY == 3 && selectPosX == 2){
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFF77FFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }else{
                    g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
                }
                g_RenderManager.DebugPrint(292, 224 + 7, "Quit Game");


                //FOOT NOTES!


                g_RenderManager.SetFontStyle(splashSize, 0xFF00FFFF, 0, INTRAFONT_ALIGN_CENTER, -20.0f);
                g_RenderManager.DebugPrint(344, 72, "%s", splashText.c_str());

                g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_LEFT, 0.0f);
                g_RenderManager.DebugPrint(0, 272, " %s %s", GAME_NAME, EMULATED_VERSION);

                g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_RIGHT, 0.0f);
                g_RenderManager.DebugPrint(480, 272, "Copyright Mojang AB. Do not distribute! ");

                break;
            }
        }   
    }


    void MenuState::panoramaPass(){
        panorama->update(dt);
        panorama->render();
    }
}
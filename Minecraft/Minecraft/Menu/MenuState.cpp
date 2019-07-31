#include "MenuState.hpp"

#include <Aurealis/Graphics/RenderManager.h>
#include <string>
#include <sstream>

namespace Minecraft::Menus{

	MenuState::MenuState(){

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

	    bgm = oslLoadSoundFile(ss.str().c_str(),0);
	    g_AudioManager.PlayMusic(bgm);

        panorama = new Panorama();

        menu_states = MENU_STATE_TITLE;

        logo = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/logo.png");
        Logo = new Sprite(logo);
        Logo->Scale(0.9375f, 0.9375f);
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
        switch(menu_states){

        }
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

                Logo->SetPosition(240, 60);
                Logo->Draw();

                break;
            }
        }   
    }


    void MenuState::panoramaPass(){
        panorama->update(t.GetDeltaTime());
        panorama->render();
    }
}
#include "MenuState.hpp"
#include <Shadow/Utils/Logger.h>

namespace Minecraft::Menus{

	MenuState::MenuState(){
        elapsed = 0;
        dt = 0;
        selectRegion = selectPosY = selectPosX = 0;
        langPos = langPosMax = langPosSel = 0;
		tryConnect = false;
		connected = false;
    }

    MenuState::~MenuState(){

    }

	void MenuState::Init(){

		//Delete Logs from past launch
		remove(Logging::logFile.c_str());
		Logging::logging_level = Logging::LOGGER_LEVEL_TRACE; //Most "verbose"



		u32 ramFree = freeMemory();
		float ram = ((float)ramFree) / 1024.0f / 1024.0f;
		std::ostringstream os;
		os << ram;
		std::string s(os.str());


		Logging::log("RAM BEFORE MENU: " + s, Logging::LOGGER_LEVEL_TRACE);

        t = Timer();
        Common::g_OptionsManager.init();
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

        logo = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/minecraft.png");
        Minecraft1 = new Sprite(logo, 0, 0, 155, 45);
        Minecraft2 = new Sprite(logo, 0, 45, 120, 45);

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

        opt_dis = new Sprite(widgets, 0, 46, 200, 20);
        opt_dis->Scale(0.8f, 1.0f);

        mega_slider = new Sprite(widgets, 0, 46, 200, 20);
        mega_slider->Scale(336.0f / 200.0f, 1.0f);

        opt_unsel = new Sprite(widgets, 0, 66, 200, 20);
        opt_unsel->Scale(0.8f, 1.0f);

        opt_sel = new Sprite(widgets, 0, 86, 200, 20);
        opt_sel->Scale(0.8f, 1.0f);

        miniSel = new Sprite(widgets, 0, 86, 200, 20);
        miniSel->Scale(0.48f, 1.0f);
        miniUnSel = new Sprite(widgets, 0, 66, 200, 20);
        miniUnSel->Scale(0.48f, 1.0f);
        miniDis = new Sprite(widgets, 0, 46, 200, 20);
        miniDis->Scale(0.48f, 1.0f);

        tinySel = new Sprite(widgets, 0, 86, 200, 20);
        tinySel->Scale(0.36f, 1.0f);
        tinyUnSel = new Sprite(widgets, 0, 66, 200, 20);
        tinyUnSel->Scale(0.36f, 1.0f);
        tinyDis = new Sprite(widgets, 0, 46, 200, 20);
        tinyDis->Scale(0.36f, 1.0f);
        
        slider = new Sprite(widgets, 0, 66, 200, 20);
        slider->Scale(0.025f, 1.0f);
        slider_sel = new Sprite(widgets, 0, 86, 200, 20);
        slider_sel->Scale(0.025f, 1.0f);

        lang = new Sprite(widgets, 0, 106, 20, 20);
        hlang = new Sprite(widgets, 0, 126, 20, 20);

        options_bg = TextureUtil::LoadPng("assets/minecraft/textures/gui/options_background.png");
        options_tile = new Sprite(options_bg);
        options_tile->Scale(2.0f, 2.0f);

        Common::g_TranslationOBJ.init();
        Common::g_TranslationOBJ.setTranslation(Common::g_OptionsManager.options.lang);

        langPosMax = Common::g_TranslationOBJ.availableTranslations().size();
		

		ramFree = freeMemory();
		ram = ((float)ramFree) / 1024.0f / 1024.0f;
		std::ostringstream os2;
		os2 << ram;
		std::string s1(os2.str());


		Logging::log("RAM DURING MENU: " + s1, Logging::LOGGER_LEVEL_TRACE);
    }

	void MenuState::Enter(){

    }
	void MenuState::CleanUp(){
        
    }

	void MenuState::Pause(){
		//CLEAN SOUND
		oslStopSound(bgm);
		oslDeleteSound(bgm);
		oslStopSound(button);
		oslDeleteSound(button);

		//CLEAN TEXTURES
		delete logo;
		delete widgets;
		delete options_bg;

		//CLEAN SPRITES
		delete selected;
		delete unselected;
		delete disabled;
		delete lang;
		delete hlang;
		delete opt_sel;
		delete opt_unsel;
		delete opt_dis;
		delete miniSel;
		delete miniUnSel;
		delete miniDis;
		delete tinySel;
		delete tinyUnSel;
		delete tinyDis;
		delete options_tile;
		delete slider;
		delete slider_sel;
		delete mega_slider;
		delete Minecraft1;
		delete Minecraft2;

		//CLEAN PANORAMA
		delete panorama;
    }
	void MenuState::Resume(){
		elapsed = 0;
		dt = 0;
		selectRegion = selectPosY = selectPosX = 0;
		langPos = langPosMax = langPosSel = 0;
		tryConnect = false;
		connected = false;

		t = Timer();
		//BGM!!!
		srand(time(0));
		int musicChoice = rand() % 4 + 1; //1 - 4
		std::stringstream ss;
		ss << "./assets/sounds/ambient/menu/menu";
		ss << musicChoice;
		ss << ".bgm";

		bgm = oslLoadSoundFile(ss.str().c_str(), OSL_FMT_STREAM);
		button = oslLoadSoundFile("./assets/sounds/other/button1.wav", 0);
		g_AudioManager.PlayMusic(bgm);

		panorama = new Panorama();

		menu_states = MENU_STATE_TITLE;

		logo = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/minecraft.png");
		Minecraft1 = new Sprite(logo, 0, 0, 155, 45);
		Minecraft2 = new Sprite(logo, 0, 45, 120, 45);
		
		selectPosY = 0;
		selectPosX = 1;

		widgets = TextureUtil::LoadPng("./assets/minecraft/textures/gui/widgets.png");
		disabled = new Sprite(widgets, 0, 46, 200, 20);
		unselected = new Sprite(widgets, 0, 66, 200, 20);
		selected = new Sprite(widgets, 0, 86, 200, 20);

		opt_dis = new Sprite(widgets, 0, 46, 200, 20);
		opt_dis->Scale(0.8f, 1.0f);

		mega_slider = new Sprite(widgets, 0, 46, 200, 20);
		mega_slider->Scale(336.0f / 200.0f, 1.0f);

		opt_unsel = new Sprite(widgets, 0, 66, 200, 20);
		opt_unsel->Scale(0.8f, 1.0f);

		opt_sel = new Sprite(widgets, 0, 86, 200, 20);
		opt_sel->Scale(0.8f, 1.0f);

		miniSel = new Sprite(widgets, 0, 86, 200, 20);
		miniSel->Scale(0.48f, 1.0f);
		miniUnSel = new Sprite(widgets, 0, 66, 200, 20);
		miniUnSel->Scale(0.48f, 1.0f);
		miniDis = new Sprite(widgets, 0, 46, 200, 20);
		miniDis->Scale(0.48f, 1.0f);

		tinySel = new Sprite(widgets, 0, 86, 200, 20);
		tinySel->Scale(0.36f, 1.0f);
		tinyUnSel = new Sprite(widgets, 0, 66, 200, 20);
		tinyUnSel->Scale(0.36f, 1.0f);
		tinyDis = new Sprite(widgets, 0, 46, 200, 20);
		tinyDis->Scale(0.36f, 1.0f);

		slider = new Sprite(widgets, 0, 66, 200, 20);
		slider->Scale(0.025f, 1.0f);
		slider_sel = new Sprite(widgets, 0, 86, 200, 20);
		slider_sel->Scale(0.025f, 1.0f);

		lang = new Sprite(widgets, 0, 106, 20, 20);
		hlang = new Sprite(widgets, 0, 126, 20, 20);

		options_bg = TextureUtil::LoadPng("assets/minecraft/textures/gui/options_background.png");
		options_tile = new Sprite(options_bg);
		options_tile->Scale(2.0f, 2.0f);


		Common::g_TranslationOBJ.setTranslation(Common::g_OptionsManager.options.lang);
		langPosMax = Common::g_TranslationOBJ.availableTranslations().size();
    }

	void MenuState::Update(StateManager* sManager){
        dt = t.deltaTime();
        elapsed += dt;

        Input::InputUpdate();
        switch(menu_states){
            case MENU_STATE_TITLE:{
                titleScreenUpdate();
                break;
            }

            case MENU_STATE_LANGUAGE:{
                languageScreenUpdate();
                break;
            }

            case MENU_STATE_OPTIONS_MAIN:{
                optionsMainScreenUpdate();
                break;
            }

            case MENU_STATE_SKIN_CUSTOMIZATION:{
                optionsSkinScreenUpdate();
                break;
            }
            case MENU_STATE_MUSIC:{
                optionsMusicScreenUpdate();
                break;
            }

            case MENU_STATE_CHAT_SETTINGS:{
                optionsChatScreenUpdate();
                break;
            }
            case MENU_STATE_VIDEO:{
                optionsVideoScreenUpdate();
                break;
            }

            case MENU_STATE_SNOOPER:{
                optionsSnooperScreenUpdate();
                break;
            }
            case MENU_STATE_MULTIPLAYER:{
               optionsMultiplayerScreenUpdate(sManager);
               break;
            }
        }
    }
    

	void MenuState::Draw(StateManager* sManager){
        g_RenderManager.StartFrame(0, 0, 0);

        if(menu_states == MENU_STATE_TITLE){
            g_RenderManager.SetPerspective(75, 480.0f / 272.0f, 0.3f, 1000.0f); //Into 3D Mode for panorama
            panoramaPass();
        }

        g_RenderManager.SetOrtho(0,0,0,0,0,0); //Into 2D Mode for menu pass
        menuPass();

        
        #ifdef DEBUG
        g_RenderManager.SetFontStyle(PSP_MENU_SIZE, 0xFFFFFFFF, 0, INTRAFONT_ALIGN_CENTER, 0.0f);
        
        u32 ramFree = Input::freeMemory();
        
        g_RenderManager.DebugPrint(240, 15, "RAM: %.3f MB", ((float)ramFree) / 1024.0f / 1024.0f );
        #endif
		
        g_RenderManager.EndFrame();
    }

    void MenuState::menuPass(){
        switch(menu_states){
            case MENU_STATE_TITLE:{
                titleScreenDraw();
                break;
            }

            case MENU_STATE_LANGUAGE:{
                languageScreenDraw();
                break;
            }

            case MENU_STATE_OPTIONS_MAIN:{
                optionsMainScreenDraw();
                break;
            }

            case MENU_STATE_SKIN_CUSTOMIZATION:{
                optionsSkinScreenDraw();
                break;
            }
            case MENU_STATE_MUSIC:{
                optionsMusicScreenDraw();
                break;
            }

            case MENU_STATE_CHAT_SETTINGS:{
                optionsChatScreenDraw();
                break;
            }
            case MENU_STATE_VIDEO:{
                optionsVideoScreenDraw();
                break;
            }

            case MENU_STATE_SNOOPER:{
                optionsSnooperScreenDraw();
                break;
            }

            case MENU_STATE_MULTIPLAYER:{
                optionsMultiplayerScreenDraw();
                break;
            }
        }   
    }


    void MenuState::panoramaPass(){
        panorama->update(dt);
        panorama->render();
    }
}
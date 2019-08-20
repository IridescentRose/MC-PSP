#include "Options.hpp"

namespace Minecraft::Common{

    OptionsManager::OptionsManager(){
        options = g_DefaultOptions;
    }
    
    OptionsManager::~OptionsManager(){

    }

    void OptionsManager::init(){

    }

    void OptionsManager::cleanup(){

    }

    void OptionsManager::open(){

    }

    void OptionsManager::close(){

    }

    Options g_DefaultOptions = {1343, false, 0.5f, 0.0f, 0.0f, 0.0f, 4, 0, 0, true, 60, false, 2, true, 2, 2, true, "", "", "", "en_us", 0, true, true, true, 1.0f, true, false, false, false, false, false, true, false, 0, 0, true, 1.0f, 0.44366196f, 1.0f, 1.0f, 4, false, false, true, true, true, 1, false, true, true, 0, "movement", true, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, true, true, true, true, true, true, true};

    OptionsManager g_OptionsManager = OptionsManager();
}
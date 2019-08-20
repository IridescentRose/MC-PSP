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

    Options g_DefaultOptions = {};

    OptionsManager g_OptionsManager = OptionsManager();
}
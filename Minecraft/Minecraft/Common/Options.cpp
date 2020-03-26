#include "Options.hpp"
#include <Utilities/Logger.h>
namespace Minecraft::Common{

    OptionsManager::OptionsManager(){
        options = g_DefaultOptions;
    }
    
    OptionsManager::~OptionsManager(){

    }

    bool getBool(const std::string& val){
        return (val == "true") ? true : false;
    }
    std::string BTS(bool var){
        return (var) ? "true" : "false";
    }

    void loadData(Options& options, const std::string& key, const std::string& value){
        
    }

    void writeFile(const Options& options){
        std::ofstream output("options.txt");
        output << "version" << ":" << options.version << "\n";
        output << "invertYMouse" << ":" << BTS(options.invertYMouse) << "\n";
        output << "mouseSensitivity" << ":" << options.mouseSensitivity  << "\n";
        output << "fov" << ":" << options.fov << "\n";
        output << "gamma" << ":" << options.gamma << "\n";
        output << "saturation" << ":" << options.saturation  << "\n";
        output << "renderDistance" << ":" << options.renderDistance  << "\n";
        output << "guiScale" << ":" << options.guiScale  << "\n";
        output << "particles" << ":" << options.particles  << "\n";
        output << "bobView" << ":" << BTS(options.bobView) << "\n";
        output << "maxFPS" << ":" << options.maxFPS  << "\n";
        output << "fboEnable" << ":" << BTS(options.fboEnable) << "\n";
        output << "difficulty" << ":" << options.difficulty  << "\n";
        output << "fancyGraphics" << ":" << BTS(options.fancyGraphics) << "\n";
        output << "ao" << ":" << options.ao  << "\n";
        output << "biomeBlendRadius" << ":" << options.biomeBlendRadius  << "\n";
        output << "renderClouds" << ":" << BTS(options.renderClouds) << "\n";
        output << "resourcePacks" << ":" << options.resourcePacks  << "\n";
        output << "incompatibleResourcePacks" << ":" << options.incompatibleResourcePacks  << "\n";
        output << "lastServer" << ":" << options.lastServer  << "\n";
        output << "lang" << ":" << options.lang  << "\n";
        output << "chatVisibility" << ":" << BTS(options.chatVisibility) << "\n";
        output << "chatColors" << ":" << BTS(options.chatColors) << "\n";
        output << "chatLinks" << ":" << BTS(options.chatLinks) << "\n";
        output << "chatLinksPrompt" << ":" << BTS(options.chatLinksPrompt) << "\n";
        output << "chatOpacity" << ":" << options.chatOpacity  << "\n";
        output << "snooperEnabled" << ":" << BTS(options.snooperEnabled) << "\n";
        output << "fullscreen" << ":" << BTS(options.fullscreen) << "\n";
        output << "enableVsync" << ":" << BTS(options.enableVsync) << "\n";
        output << "useVbo" << ":" << BTS(options.useVbo) << "\n";
        output << "hideServerAddress" << ":" << BTS(options.hideServerAddress) << "\n";
        output << "advancedItemTooltips" << ":" << BTS(options.advancedItemTooltips) << "\n";
        output << "pauseOnLostFocus" << ":" << BTS(options.pauseOnLostFocus) << "\n";
        output << "touchscreen" << ":" << BTS(options.touchscreen) << "\n";
        output << "overrideWidth" << ":" << options.overrideWidth  << "\n";
        output << "overrideHeight" << ":" << options.overrideHeight  << "\n";
        output << "heldItemTooltips" << ":" << BTS(options.heldItemTooltips) << "\n";
        output << "chatHeightFocused" << ":" << options.chatHeightFocused  << "\n";
        output << "chatHeightUnfocused" << ":" << options.chatHeightUnfocused  << "\n";
        output << "chatScale" << ":" << options.chatScale  << "\n";
        output << "chatWidth" << ":" << options.chatWidth  << "\n";
        output << "mipmapLevels" << ":" << options.mipmapLevels  << "\n";
        output << "forceUnicodeFont" << ":" << BTS(options.forceUnicodeFont) << "\n";
        output << "reducedDebugInfo" << ":" << BTS(options.reducedDebugInfo) << "\n";
        output << "useNativeTransport" << ":" << BTS(options.useNativeTransport) << "\n";
        output << "entityShadows" << ":" << BTS(options.entityShadows) << "\n";
        output << "mainHand" << ":" << ((options.mainHand) ? "right": "left") << "\n";
        output << "attackIndicator" << ":" << options.attackIndicator  << "\n";
        output << "showSubtitles" << ":" << BTS(options.showSubtitles) << "\n";
        output << "realmsNotifications" << ":" << BTS(options.realmsNotifications) << "\n";
        output << "autoJump" << ":" << BTS(options.autoJump) << "\n";
        output << "narrator" << ":" << options.narrator  << "\n";
        output << "tutorialStep" << ":" << options.tutorialStep  << "\n";
        output << "autoSuggestions" << ":" << options.autoSuggestions  << "\n";
        output << "mouseWheelSensitivity" << ":" << options.mouseWheelSensitivity  << "\n";
        output << "soundCategory_master" << ":" << options.soundCategory_master  << "\n";
        output << "soundCategory_music" << ":" << options.soundCategory_music  << "\n";
        output << "soundCategory_record" << ":" << options.soundCategory_record  << "\n";
        output << "soundCategory_weather" << ":" << options.soundCategory_weather  << "\n";
        output << "soundCategory_block" << ":" << options.soundCategory_block  << "\n";
        output << "soundCategory_hostile" << ":" << options.soundCategory_hostile << "\n";
        output << "soundCategory_neutral" << ":" << options.soundCategory_neutral  << "\n";
        output << "soundCategory_player" << ":" << options.soundCategory_player << "\n";
        output << "soundCategory_ambient" << ":" << options.soundCategory_ambient  << "\n";
        output << "soundCategory_voice" << ":" << options.soundCategory_voice  << "\n";
        output << "modelPart_cape" << ":" << BTS(options.modelPart_cape) << "\n";
        output << "modelPart_jacket" << ":" << BTS(options.modelPart_jacket) << "\n";
        output << "modelPart_left_sleeve" << ":" << BTS(options.modelPart_left_sleeve) << "\n";
        output << "modelPart_right_sleeve" << ":" << BTS(options.modelPart_right_sleeve) << "\n";
        output << "modelPart_left_pants_leg" << ":" << BTS(options.modelPart_left_pants_leg) << "\n";
        output << "modelPart_right_pants_leg" << ":" << BTS(options.modelPart_right_pants_leg) << "\n";
        output << "modelPart_hat" << ":" << BTS(options.modelPart_hat) << "\n";
    }
    void OptionsManager::init(){
        open();
        close();
    }

    void OptionsManager::cleanup(){
        close(); //Make sure we're closed.
    }

    void OptionsManager::open(){
        std::ifstream file("options.txt");
        if(file.good()){

            std::string key, value;
            while(!file.eof()){
                std::getline(file, key, ':');
                file >> value;

                if(key.at(0) == '\n'){
                    key.erase(key.begin());
                }

                if("version" == key){
                    options.version = std::atoi(value.c_str());
                }else if("invertYMouse" == key){
                    options.invertYMouse = getBool(value);
                }else if("mouseSensitivity" == key){
                    options.mouseSensitivity = std::atof(value.c_str());
                }else if("fov" == key){
                    options.fov = std::atof(value.c_str());   
                }else if("gamma" == key) { 
                    options.gamma = std::atof(value.c_str());
                }else if("saturation" == key){
                    options.saturation = std::atof(value.c_str());
                }else if("renderDistance" == key) {
                    options.renderDistance = std::atoi(value.c_str());
                }else if("guiScale" == key) {
                    options.guiScale = std::atoi(value.c_str());
                }else if("particles" == key) {
                    options.particles = std::atoi(value.c_str());
                }else if("bobView" == key) {
                    options.bobView = getBool(value);
                }else if("maxFPS" == key) {
                    options.maxFPS = std::atoi(value.c_str());
                }else if("fboEnable" == key){
                    options.fboEnable = getBool(value);
                }else if("difficulty" == key) {
                    options.difficulty = std::atoi(value.c_str());
                }else if("fancyGraphics" == key){
                    options.fancyGraphics = getBool(value);
                }else if("ao" == key){
                    options.ao = std::atoi(value.c_str());
                }else if("biomeBlendRadius" == key) {
                    options.biomeBlendRadius = std::atoi(value.c_str());
                }else if("renderClouds" == key) {
                    options.renderClouds = getBool(value);
                }else if("resourcePacks" == key) {
                    options.resourcePacks = value;
                }else if("incompatibleResourcePacks" == key) {
                    options.incompatibleResourcePacks = value;
                }else if("lastServer" == key) {
                    options.lastServer = value;
                }else if("lang" == key) { 
                    options.lang = value;
                }else if("chatVisibility" == key) { 
                    options.chatVisibility = std::atoi(value.c_str());
                }else if("chatColors" == key){
                    options.chatColors = getBool(value);
                }else if("chatLinks" == key) {
                    options.chatLinks = getBool(value);
                }else if("chatLinksPrompt" == key) {
                    options.chatLinksPrompt = getBool(value);
                }else if("chatOpacity" == key) {
                    options.chatOpacity = std::atoi(value.c_str());
                }else if("snooperEnabled" == key) {
                    options.snooperEnabled = getBool(value);
                }else if("fullscreen" == key) {
                    options.fullscreen = getBool(value);
                }else if("enableVsync" == key) {
                    options.enableVsync = getBool(value);
                }else if("useVbo" == key) {
                    options.useVbo = getBool(value);
                }else if("hideServerAddress" == key){
                    options.hideServerAddress = getBool(value);
                }else if("advancedItemTooltips" == key) {
                    options.advancedItemTooltips = getBool(value);
                }else if("pauseOnLostFocus" == key) {
                    options.pauseOnLostFocus = getBool(value);
                }else if("touchscreen" == key) {
                    options.touchscreen = getBool(value);
                }else if("overrideWidth" == key) {
                    options.overrideWidth = std::atoi(value.c_str());
                }else if("overrideHeight" == key) {
                    options.overrideHeight = std::atoi(value.c_str());
                }else if("heldItemTooltips" == key) {
                    options.heldItemTooltips = getBool(value);
                }else if("chatHeightFocused" == key) {
                    options.chatHeightFocused = std::atof(value.c_str());
                }else if("chatHeightUnfocused" == key) {
                    options.chatHeightUnfocused = std::atof(value.c_str());
                }else if("chatScale" == key) {
                    options.chatScale = std::atof(value.c_str());
                }else if("chatWidth" == key) {
                    options.chatWidth = std::atof(value.c_str());
                }else if("mipmapLevels" == key){
                    options.mipmapLevels = std::atoi(value.c_str());
                }else if("forceUnicodeFont" == key) {
                    options.forceUnicodeFont = getBool(value);
                }else if("reducedDebugInfo" == key) {
                    options.reducedDebugInfo = getBool(value);
                }else if("useNativeTransport" == key) {
                    options.useNativeTransport = getBool(value);
                }else if("entityShadows" == key) {
                    options.entityShadows = getBool(value);
                }else if("mainHand" == key) {
                    options.mainHand = ( value == "right" ? true : false);
                }else if("attackIndicator" == key) {
                    options.attackIndicator = std::atoi(value.c_str());
                }else if("showSubtitles" == key) {
                    options.showSubtitles = getBool(value);
                }else if("realmsNotifications" == key) {
                    options.realmsNotifications = getBool(value);
                }else if("autoJump" == key) {
                    options.autoJump = getBool(value);
                }else if("narrator" == key) {
                    options.narrator = std::atoi(value.c_str());
                }else if("tutorialStep" == key){
                    options.tutorialStep = value;
                }else if("autoSuggestions" == key){
                    options.autoSuggestions = getBool(value);
                }else if("mouseWheelSensitivity" == key){
                    options.mouseWheelSensitivity = std::atof(value.c_str());
                }else if("soundCategory_master" == key){
                    options.soundCategory_master = std::atof(value.c_str());
                }else if("soundCategory_music" == key) {
                    options.soundCategory_music = std::atof(value.c_str());
                }else if("soundCategory_record" == key) {
                    options.soundCategory_record = std::atof(value.c_str());
                }else if("soundCategory_weather" == key) {
                    options.soundCategory_weather = std::atof(value.c_str());
                }else if("soundCategory_block" == key) {
                    options.soundCategory_block = std::atof(value.c_str());
                }else if("soundCategory_hostile" == key) {
                    options.soundCategory_hostile = std::atof(value.c_str());
                }else if("soundCategory_neutral" == key) {
                    options.soundCategory_neutral = std::atof(value.c_str());
                }else if("soundCategory_player" == key) {
                    options.soundCategory_player = std::atof(value.c_str());
                }else if("soundCategory_ambient" == key) {
                    options.soundCategory_ambient =std::atof(value.c_str());
                }else if("soundCategory_voice" == key) {
                    options.soundCategory_voice = std::atof(value.c_str());
                }else if("modelPart_cape" == key) {
                    options.modelPart_cape = getBool(value);
                }else if("modelPart_jacket" == key) {
                    options.modelPart_jacket = getBool(value);
                }else if("modelPart_left_sleeve" == key) {
                    options.modelPart_left_sleeve = getBool(value);
                }else if("modelPart_right_sleeve" == key) {
                    options.modelPart_right_sleeve = getBool(value);
                }else if("modelPart_left_pants_leg" == key) {
                    options.modelPart_left_pants_leg = getBool(value);
                }else if("modelPart_right_pants_leg" == key) {
                    options.modelPart_right_pants_leg = getBool(value);
                }else if("modelPart_hat" == key) {
                    options.modelPart_hat = getBool(value);
                }
            }
        }else{
            std::ofstream correct("options.txt");
            correct.close(); //Creates file
            //Write out the options
            writeFile(g_DefaultOptions);
            options = g_DefaultOptions;
        }
        
        //Write out the options
        remove("options.txt");
        writeFile(options);
    }

    void OptionsManager::close(){
        remove("options.txt");
        writeFile(options);
    }

    Options g_DefaultOptions = {1343, false, 0.5f, 0.0f, 0.0f, 0.0f, 4, 0, 0, true, 60, false, 2, true, 2, 2, true, "[]", "[]", "[]", "en_us", 0, true, true, true, 1.0f, true, false, false, false, false, false, true, false, 0, 0, true, 1.0f, 0.44366196f, 1.0f, 1.0f, 4, false, false, true, true, true, 1, false, true, true, 0, "movement", true, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, true, true, true, true, true, true, true};

    OptionsManager g_OptionsManager = OptionsManager();

}
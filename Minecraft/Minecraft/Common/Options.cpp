#include "Options.hpp"
#include <Aurealis/Utils/Logger.h>
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

    void writeFile(const Options& options, std::fstream& output){
        output << "version" << ":" << options.version << std::endl;
        output << "invertYMouse" << ":" << BTS(options.invertYMouse) << std::endl;
        output << "mouseSensitivity" << ":" << options.mouseSensitivity  << std::endl;
        output << "fov" << ":" << options.fov << std::endl;
        output << "gamma" << ":" << options.gamma << std::endl;
        output << "saturation" << ":" << options.saturation  << std::endl;
        output << "renderDistance" << ":" << options.renderDistance  << std::endl;
        output << "guiScale" << ":" << options.guiScale  << std::endl;
        output << "particles" << ":" << options.particles  << std::endl;
        output << "bobView" << ":" << BTS(options.bobView) << std::endl;
        output << "maxFPS" << ":" << options.maxFPS  << std::endl;
        output << "fboEnable" << ":" << BTS(options.fboEnable) << std::endl;
        output << "difficulty" << ":" << options.difficulty  << std::endl;
        output << "fancyGraphics" << ":" << BTS(options.fancyGraphics) << std::endl;
        output << "ao" << ":" << options.ao  << std::endl;
        output << "biomeBlendRadius" << ":" << options.biomeBlendRadius  << std::endl;
        output << "renderClouds" << ":" << BTS(options.renderClouds) << std::endl;
        output << "resourcePacks" << ":" << options.resourcePacks  << std::endl;
        output << "incompatibleResourcePacks" << ":" << options.incompatibleResourcePacks  << std::endl;
        output << "lastServer" << ":" << options.lastServer  << std::endl;
        output << "lang" << ":" << options.lang  << std::endl;
        output << "chatVisibility" << ":" << BTS(options.chatVisibility) << std::endl;
        output << "chatColors" << ":" << BTS(options.chatColors) << std::endl;
        output << "chatLinks" << ":" << BTS(options.chatLinks) << std::endl;
        output << "chatLinksPrompt" << ":" << BTS(options.chatLinksPrompt) << std::endl;
        output << "chatOpacity" << ":" << options.chatOpacity  << std::endl;
        output << "snooperEnabled" << ":" << BTS(options.snooperEnabled) << std::endl;
        output << "fullscreen" << ":" << BTS(options.fullscreen) << std::endl;
        output << "enableVsync" << ":" << BTS(options.enableVsync) << std::endl;
        output << "useVbo" << ":" << BTS(options.useVbo) << std::endl;
        output << "hideServerAddress" << ":" << BTS(options.hideServerAddress) << std::endl;
        output << "advancedItemTooltips" << ":" << BTS(options.advancedItemTooltips) << std::endl;
        output << "pauseOnLostFocus" << ":" << BTS(options.pauseOnLostFocus) << std::endl;
        output << "touchscreen" << ":" << BTS(options.touchscreen) << std::endl;
        output << "overrideWidth" << ":" << options.overrideWidth  << std::endl;
        output << "overrideHeight" << ":" << options.overrideHeight  << std::endl;
        output << "heldItemTooltips" << ":" << BTS(options.heldItemTooltips) << std::endl;
        output << "chatHeightFocused" << ":" << options.chatHeightFocused  << std::endl;
        output << "chatHeightUnfocused" << ":" << options.chatHeightUnfocused  << std::endl;
        output << "chatScale" << ":" << options.chatScale  << std::endl;
        output << "chatWidth" << ":" << options.chatWidth  << std::endl;
        output << "mipmapLevels" << ":" << options.mipmapLevels  << std::endl;
        output << "forceUnicodeFont" << ":" << BTS(options.forceUnicodeFont) << std::endl;
        output << "reducedDebugInfo" << ":" << BTS(options.reducedDebugInfo) << std::endl;
        output << "useNativeTransport" << ":" << BTS(options.useNativeTransport) << std::endl;
        output << "entityShadows" << ":" << BTS(options.entityShadows) << std::endl;
        output << "mainHand" << ":" << ((options.mainHand) ? "right": "left") << std::endl;
        output << "attackIndicator" << ":" << options.attackIndicator  << std::endl;
        output << "showSubtitles" << ":" << BTS(options.showSubtitles) << std::endl;
        output << "realmsNotifications" << ":" << BTS(options.realmsNotifications) << std::endl;
        output << "autoJump" << ":" << BTS(options.autoJump) << std::endl;
        output << "narrator" << ":" << options.narrator  << std::endl;
        output << "tutorialStep" << ":" << options.tutorialStep  << std::endl;
        output << "autoSuggestions" << ":" << options.autoSuggestions  << std::endl;
        output << "mouseWheelSensitivity" << ":" << options.mouseWheelSensitivity  << std::endl;
        output << "soundCategory_master" << ":" << options.soundCategory_master  << std::endl;
        output << "soundCategory_music" << ":" << options.soundCategory_music  << std::endl;
        output << "soundCategory_record" << ":" << options.soundCategory_record  << std::endl;
        output << "soundCategory_weather" << ":" << options.soundCategory_weather  << std::endl;
        output << "soundCategory_block" << ":" << options.soundCategory_block  << std::endl;
        output << "soundCategory_hostile" << ":" << options.soundCategory_hostile << std::endl;
        output << "soundCategory_neutral" << ":" << options.soundCategory_neutral  << std::endl;
        output << "soundCategory_player" << ":" << options.soundCategory_player << std::endl;
        output << "soundCategory_ambient" << ":" << options.soundCategory_ambient  << std::endl;
        output << "soundCategory_voice" << ":" << options.soundCategory_voice  << std::endl;
        output << "modelPart_cape" << ":" << BTS(options.modelPart_cape) << std::endl;
        output << "modelPart_jacket" << ":" << BTS(options.modelPart_jacket) << std::endl;
        output << "modelPart_left_sleeve" << ":" << BTS(options.modelPart_left_sleeve) << std::endl;
        output << "modelPart_right_sleeve" << ":" << BTS(options.modelPart_right_sleeve) << std::endl;
        output << "modelPart_left_pants_leg" << ":" << BTS(options.modelPart_left_pants_leg) << std::endl;
        output << "modelPart_right_pants_leg" << ":" << BTS(options.modelPart_right_pants_leg) << std::endl;
        output << "modelPart_hat" << ":" << BTS(options.modelPart_hat) << std::endl;
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
            option_file.open("options.txt");
            //Write out the options
            options = g_DefaultOptions;
            writeFile(options, option_file);
        }
    }

    void OptionsManager::close(){

        option_file.close();
        remove("options.txt");
        std::ofstream correct("options.txt");
        correct.close();

        option_file.open("options.txt");

        writeFile(options, option_file);
    }

    Options g_DefaultOptions = {1343, false, 0.5f, 0.0f, 0.0f, 0.0f, 4, 0, 0, true, 60, false, 2, true, 2, 2, true, "[]", "[]", "[]", "en_us", 0, true, true, true, 1.0f, true, false, false, false, false, false, true, false, 0, 0, true, 1.0f, 0.44366196f, 1.0f, 1.0f, 4, false, false, true, true, true, 1, false, true, true, 0, "movement", true, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, true, true, true, true, true, true, true};

    OptionsManager g_OptionsManager = OptionsManager();

}
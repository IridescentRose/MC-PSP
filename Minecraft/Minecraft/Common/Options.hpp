#pragma once 

#include <fstream>

namespace Minecraft::Common{
    //STRUCT OPTIONS

    struct Options{
        uint16_t version;
        bool invertYMouse;
        float mouseSensitivity;
        float fov;
        float gamma;
        float saturation;
        uint8_t renderDistance;
        uint8_t guiScale;
        uint8_t particles;
        bool bobView;
        uint8_t maxFPS;
        bool fboEnable;
        uint8_t difficulty;
        bool fancyGraphics;
        uint8_t ao;
        uint8_t biomeBlendRadius;
        uint8_t renderClouds;
        std::string resourcePacks;
        std::string incompatibleResourcePacks;
        std::string lastServer;
        std::string lang;
        uint8_t chatVisibility;
        bool chatColors;
        bool chatLinks;
        bool chatLinksPrompt;
        float chatOpacity;
        bool snooperEnabled;
        bool fullscreen;
        bool enableVsync;
        bool useVbo;
        bool hideServerAddress;
        bool advancedItemTooltips;
        bool pauseOnLostFocus;
        bool touchscreen;
        uint16_t overrideWidth;
        uint16_t overrideHeight;
        bool heldItemTooltips;
        float chatHeightFocused;
        float chatHeightUnfocused;
        float chatScale;
        float chatWidth;
        uint8_t mipmapLevels;
        bool forceUnicodeFont;
        bool reducedDebugInfo;
        bool useNativeTransport;
        bool entityShadows;
        bool mainHand;
        uint8_t attackIndicator;
        bool showSubtitles;
        bool realmsNotifications;
        bool autoJump;
        uint8_t narrator;
        std::string tutorialStep;
        bool autoSuggestions;
        float mouseWheelSensitivity;

        //SKIP CONTROLS!!!

        float soundCategory_master;
        float soundCategory_music;
        float soundCategory_record;
        float soundCategory_weather;
        float soundCategory_block;
        float soundCategory_hostile;
        float soundCategory_neutral;
        float soundCategory_player;
        float soundCategory_ambient;
        float soundCategory_voice;

        bool modelPart_cape; 	
        bool modelPart_jacket; //	Whether the "Jacket" skin layer is shown (true/false) 	true 	
        bool modelPart_left_sleeve; //	Whether the "Left Sleeve" skin layer is shown (true/false) 	true 	
        bool modelPart_right_sleeve; //	Whether the "Right Sleeve" skin layer is shown (true/false) 	true 	
        bool modelPart_left_pants_leg; // 	Whether the "Left Pants Leg" skin layer is shown (true/false) 	true 	
        bool modelPart_right_pants_leg; // 	Whether the "Right Pants Leg" skin lauer is shown (true/false) 	true 	
        bool modelPart_hat; // 	Whether the "Hat" skin layer is shown (true/false) 	true 	
    };

    class OptionsManager{
        public:

        OptionsManager();
        ~OptionsManager();

        void init();
        void cleanup();

        void open();
        void close();

        Options options;

        private:

        std::fstream option_file;
    };

    extern Options g_DefaultOptions;

    extern OptionsManager g_OptionsManager;
}
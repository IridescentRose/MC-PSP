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
        int renderDistance;
        int guiScale;
        int particles;
        bool bobView;
        int maxFPS;
        bool fboEnable;
        int difficulty;
        bool fancyGraphics;
        int ao;
        int biomeBlendRadius;
        int renderClouds;
        std::string resourcePacks;
        std::string incompatibleResourcePacks;
        std::string lastServer;
        std::string lang;
        int chatVisibility;
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
        int mipmapLevels;
        bool forceUnicodeFont;
        bool reducedDebugInfo;
        bool useNativeTransport;
        bool entityShadows;
        bool mainHand;
        int attackIndicator;
        bool showSubtitles;
        bool realmsNotifications;
        bool autoJump;
        int narrator;
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
        bool modelPart_jacket;
        bool modelPart_left_sleeve;
        bool modelPart_right_sleeve;
        bool modelPart_left_pants_leg;	
        bool modelPart_right_pants_leg; // 	Whether the "Right Pants Leg" skin lauer is shown (true/false) 	true 	
        bool modelPart_hat; 	
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
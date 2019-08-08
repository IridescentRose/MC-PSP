#pragma once 

#include <fstream>

namespace Minecraft::Common{
    //STRUCT OPTIONS

    struct Options{
        uint16_t data_version;
        bool invertY;
        float sensitivity;
        float fov;
        float gamma;
        uint8_t render_distance;
        uint8_t particles;
        bool bob_view;
        uint8_t difficulty;
        bool fancy_graphics;
        uint8_t ao;
        uint8_t biome_blend_radius;
        bool render_clouds;
        //std::string resource_packs- TODO: Discuss with Darth
        std::string last_server_ip;
        std::string lang;
        uint8_t chat_visibility;
        bool chat_colors;
        float chat_opacity;
        bool hide_server_address;
        bool held_item_tooltips;
        float chat_height_focused;
        float chat_height_unfocused;
        float chat_scale;
        float chat_width;
        uint8_t mipmap_levels; //USEFUL!
        bool unicode_font; //Look into this!
        bool reduced_debug_info;
        bool entity_shadows;
        uint8_t attack_indicator;
        bool auto_jump;
        bool auto_suggestions;
        /*
            CONTROLS ARE STILL SEPARATED!!!
        */

       //SOUND
       float sound_category_master; //GUI

       float sound_category_music; //MUSIC
       float sound_category_record; //RECORD
       float sound_category_weather; //WEATHER
       float sound_category_block; //BLOCK
       float sound_category_hostile; //MOB
       float sound_category_neutral; //MOB
       float sound_category_player; //PLAYER
       float sound_category_ambient; //MISC

       //SKIN CUSTOMIZATIONS

       bool model_part_cape;
       bool model_part_jacket;
       bool model_part_left_sleeve;
       bool model_part_right_sleeve;
       bool model_part_left_pants_leg;
       bool model_part_right_pants_leg;
       bool model_part_hat;
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

    extern OptionsManager g_OptionsManager;
}
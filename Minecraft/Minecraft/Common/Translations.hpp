#pragma once
#include <json/json.h>

namespace Minecraft::Common{

    struct TranslationInfo{
        std::string code;
        std::string region;
        std::string name;
    };

    class TranslationObj{
        public:
        TranslationObj();
        ~TranslationObj();

        void init();

        void setTranslation(std::string region_code);
        std::string getText(std::string key); //Find our text

        inline std::vector<TranslationInfo> availableTranslations(){
            return available;
        }

        private:

        Json::Value indexRoot;
        Json::Value en_US_Root;
        bool not_en;
        Json::Value translated_Root;
        std::vector<TranslationInfo> available;
    };

    extern TranslationObj g_TranslationOBJ;
}
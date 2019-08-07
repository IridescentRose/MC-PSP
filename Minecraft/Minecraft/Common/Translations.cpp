#include "Translations.hpp"
#include <fstream>
#include <dirent.h>
#include <pspkernel.h>
#include <algorithm>

namespace Minecraft::Common{
    TranslationObj::TranslationObj(){
        not_en = false;
    }

    TranslationObj::~TranslationObj(){

    }

    bool alphaSort(const TranslationInfo& a, const TranslationInfo& b){
        return a.code.at(0) < b.code.at(0);
    }

    void TranslationObj::init(){
        //Load index file
        std::ifstream indexLang("./assets/minecraft/lang/lang.json");
        indexLang >> indexRoot;
        indexLang.close();
        //Use this data in order to get the proper info.

        //Scan our options!

        std::vector<std::string> files;
        DIR *Dir;
        struct dirent *DirEntry;
        Dir = opendir("assets/minecraft/lang/");

        while((DirEntry = readdir(Dir)) != NULL){
            if ( DirEntry->d_stat.st_attr & FIO_SO_IFREG) // we found file
            {
                std::string name = DirEntry->d_name;
                files.push_back(name.substr(0, name.find_last_of(".")));
            }
        }

        closedir(Dir);
        
        for(unsigned int i = 0; i < files.size(); i++){
            Json::Value val1 = indexRoot["language"];
            Json::Value val2 = val1[files[i]];
            
            if(val2){
                TranslationInfo info;
                info.name = val2["name"].asString();
                info.region = val2["region"].asString();
                info.code = files[i];
                available.push_back(info);
            }
            
        }
            std::ifstream file("assets/minecraft/lang/en_us.json");
            file >> en_US_Root;
            file.close();

        std::sort(available.begin(), available.end(), alphaSort);
    }

    void TranslationObj::setTranslation(std::string region_code){
        if(region_code != "en_us" && region_code != "en_gb"){
            not_en = true;
            std::ifstream file("assets/minecraft/lang/" + region_code + ".json");
            file >> translated_Root;
            file.close();
        }else{
            not_en = false;
        }
    }

    std::string TranslationObj::getText(std::string key){
        if(not_en){ //TODO: And key exists!
            Json::Value string = translated_Root[key.c_str()]; //Get from key
            if(string){
                return string.asString(); //Return key if it exists
            }else{
                string = en_US_Root[key.c_str()];
                if(string){
                    return string.asString();
                }else{
                    return "ERROR!";
                }
            }
        }else{
            Json::Value string = en_US_Root[key.c_str()];
            if(string){
                return string.asString();
            }else{
                return "ERROR!";
            }
        }
    }

    TranslationObj g_TranslationOBJ;
}
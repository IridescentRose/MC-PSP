#pragma once
#include <vector>
#include <string>

template<class T>
class Registry{
public:
    Registry(){ 
        registryList.clear();
    }

    inline void addElement(T object){
        registryList.push_back(object);
    }

    inline T getElement(int i){
        if(i < registryList.size()){
            return registryList[i];
        }else{
            return nullptr;
        }
    }

    inline void resetElements(){
        registryList.clear();
    }

    inline std::vector<T> getList(){
        return registryList;
    }

private:
    std::vector<T> registryList;
};
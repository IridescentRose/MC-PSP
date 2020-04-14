#pragma once
#include "Registry.h"
#include "../Items/Item.h"

class ItemRegistry : public Registry<Item>{
    public:
    ItemRegistry(){}
};

extern ItemRegistry g_ItemRegistry;
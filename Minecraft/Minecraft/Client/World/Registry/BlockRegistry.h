#pragma once
#include "Registry.h"
#include "../Blocks/Block.h"

class BlockRegistry : public Registry<Block>{
    public:
    BlockRegistry(){}
};

extern BlockRegistry g_BlockRegistry;
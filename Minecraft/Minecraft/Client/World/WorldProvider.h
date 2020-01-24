#pragma once

#include "Perlin.h"
#include "Chunk.h"

namespace Minecraft::Terrain{
    class Chunk;
    class WorldProvider{
        public:

        static void generate(Chunk* chunk);

        static int seed;
        static PerlinNoise* noise;
    };


}
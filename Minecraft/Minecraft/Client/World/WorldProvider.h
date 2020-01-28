#pragma once

#include "Perlin.h"
#include "Chunk.h"

namespace Minecraft::Terrain{

    struct NoiseParameters{
        double octaves;
        double amplitude;
        double smoothness;
        double heightOffset;
        double roughness;
    };

    class Chunk;
    class WorldProvider{
        public:

        static void generate(Chunk* chunk);

        static int seed;
        static FastNoise* noise;
    };

    extern NoiseParameters defaultNoiseParams;

}
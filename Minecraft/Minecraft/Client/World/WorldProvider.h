#pragma once

#include "Perlin.h"
#include "Chunk.h"

namespace Minecraft::Terrain{

    struct NoiseParameters{
        int octaves;
        int amplitude;
        int smoothness;
        int heightOffset;
        double roughness;
    };

    class Chunk;
    class WorldProvider{
        public:

        static void generate(Chunk* chunk);

        static int seed;
        static PerlinNoise* noise;
    };

    extern NoiseParameters defaultNoiseParams;

}
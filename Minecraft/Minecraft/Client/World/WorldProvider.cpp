#include "WorldProvider.h"
#include <Shadow/Utils/Logger.h>

using namespace Shadow::Utils;

namespace Minecraft::Terrain{

    NoiseParameters defaultNoiseParams = {
		0, 8.7, 3.4, 63, 1.0
	};

    int WorldProvider::seed = 0;
    FastNoise* WorldProvider::noise = NULL;


	int getHeight(int x, int z, NoiseParameters noiseParams = defaultNoiseParams){

   		if (x < 0 || z < 0) {
        	return 64 - 1;
    	}

    	auto total = 0.0f;

		int frequency = 2;
		
		total += WorldProvider::noise->GetSimplex((float)(x) / (float)noiseParams.smoothness, (float)(z) / (float)noiseParams.smoothness) * (float) noiseParams.amplitude / noiseParams.roughness + noiseParams.heightOffset;;

		return total;
	}

    BiomeProfile defaultBiome = {BIOME_DEFAULT, defaultNoiseParams, {2, 0}, {3, 0}, {3, 0}};



    BiomeProfile oceanBiome = {BIOME_OCEAN,{0, 8.7, 3.4, 40, 1.0},{13, 0}, {13,0}, {13,0}};
    BiomeProfile riverBiome = {BIOME_RIVER,{0, 8.5, 1.5, 58, 1.0},{2, 0}, {2,0}, {3,0}};


    NoiseParameters forest = {
		0, 5.4, 2.7, 70, 1.0
	};
    NoiseParameters forestHills = {
		0, 6.5, 2.3, 70, 1.0
	};

	NoiseParameters plains = {
		0, 4.2, 4.2, 66, 1.0
	};
    NoiseParameters mountains = {
		0, 19.6, 4.2, 83, 1.0
	};

	NoiseParameters plateaus = {
		0, 4.2, 4.2, 75, 1.0
	};

	NoiseParameters lakes = {
		0, 4.2, 4.2, 62, 1.0
	};

    BiomeProfile forestBiome = {BIOME_FOREST, forest, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile woodlandBiomeHills = {BIOME_WOODLAND_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile flowerForestBiome = {BIOME_FLOWER_FOREST, forest, {2, 0}, {3, 0}, {3,0}, {0, 0}};
    BiomeProfile birchForestBiome= {BIOME_BIRCH_FOREST, forest, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile birchForestBiomeHills  = {BIOME_BIRCH_FOREST_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile tallBirchForestBiome = {BIOME_BIRCH_FOREST, forest, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile tallBirchForestBiomeHills = {BIOME_TALL_BIRCH_FOREST_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile darkForestBiome = {BIOME_DARK_FOREST_HILLS, forest, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile jungleBiome = {BIOME_JUNGLE, forest, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile jungleBiomeHills = {BIOME_JUNGLE_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile jungleEdgeBiome = {BIOME_JUNGLE_EDGE, plains, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile taigaBiome = {BIOME_TAIGA, forest, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile taigaBiomeHills = {BIOME_Taiga_Hills, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile taigaBiomeMountains = {BIOME_Taiga_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile taigaSnowyBiomeHills = {BIOME_Snowy_Taiga_Hills, forestHills, {2, 0}, {3, 0}, {3, 0}, {78, 0}};
    BiomeProfile taigaSnowyBiomeMountains = {BIOME_Snowy_Taiga_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {78, 0}};
    BiomeProfile giantTreeTaigaBiome = {BIOME_Giant_Tree_Taiga, forest, {3,2}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile giantTreeTaigaBiomeHills = {BIOME_WOODLAND_HILLS, forestHills, {3,2}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile giantSpruceTaigaBiome = {BIOME_Giant_Spruce_Taiga, forest, {3,1}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile giantSpruceTaigaBiomeHills = {BIOME_Giant_Spruce_Taiga_Hills, forestHills, {3, 1}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile mushroomBiome = {BIOME_Mushroom_Fields, forest, {110,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile mushroomShoreBiome = {BIOME_Mushroom_Fields_Shore, plains, {110,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile swampBiome = {BIOME_Swamp, lakes, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile swampHillsBiome = {BIOME_Swamp_Hills, forest, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile savannaBiome = {BIOME_Savanna, forest, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile savannaPlateauBiome = {BIOME_Savanna_Plateau, plateaus, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile savannaShatteredBiome = {BIOME_Shattered_Savanna, forestHills, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile savannaShatteredPlateauBiome = {BIOME_Shattered_Savanna_Plateau, plateaus, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile plainsBiome = {BIOME_Plains, plains, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile sunflowerPlainsBiome = {BIOME_Sunflower_Plains, plains, {2,0}, {3,0}, {3,0}, {0, 0}};
    BiomeProfile desertBiome = {BIOME_Desert, plains, {12,0}, {12,0}, {12,0}};
    BiomeProfile desertBiomeHills = {BIOME_Desert_Hills, forest, {12,0}, {12,0}, {12,0}, {0, 0}};
    BiomeProfile desertLakesBiome = {BIOME_Desert_Lakes, lakes, {12, 0}, {12, 0}, {12, 0}, {0, 0}};
    BiomeProfile snowyTundraBiome = {BIOME_Snowy_Tundra, plains, {2,0}, {3,0}, {3,0}, {78, 0}};
    BiomeProfile snowyMountainsBiome = {BIOME_Snow_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {78, 0}};
    BiomeProfile iceSpikesBiome = {BIOME_Ice_Spikes, plains, {2,0}, {3,0}, {3,0}, {78, 0}};
    BiomeProfile mountainsBiome = {BIOME_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile woodedMountainsBiome = {BIOME_Wooded_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile gravelMountainsBiome = {BIOME_Gravelly_Mountains, mountains, {13, 0}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile mesaBiome = {BIOME_Badlands, mountains, {3, 1}, {3, 0}, {3, 0}, {0, 0}};
    BiomeProfile mesaPlateauBiome = {BIOME_Badlands, plateaus, {3,1}, {3,0}, {3,0}, {0, 0}};


	void WorldProvider::generate(Chunk* c){

		int rX = c->chunk_x * CHUNK_SIZE;
		int rY = c->chunk_y * CHUNK_SIZE;
		int rZ = c->chunk_z * CHUNK_SIZE;

		if(rX >= 0 && rY >= 0 && rZ >= 0){

        	int heightMap[16][16];

        	for(int x = 0; x < CHUNK_SIZE; x++){
            	for(int z = 0; z < CHUNK_SIZE; z++){
					BiomeProfile thisBiome = desertLakesBiome;
                	heightMap[x][z] = getHeight(rX + x, rZ + z, thisBiome.params);
            	}
        	}


        	for(int x = 0; x < CHUNK_SIZE; x++){
		    	for(int y = 0; y < CHUNK_SIZE; y++){

					BiomeProfile thisBiome = desertLakesBiome;

				    for(int z = 0; z < CHUNK_SIZE; z++){
						
					    if(rY + y <= heightMap[x][z] && rY + y > 0){
						    c->blocks[x][y][z].ID = 1;
						    c->blocks[x][y][z].meta = 0;
				    	}else if(rY + y > heightMap[x][z] && rY + y < heightMap[x][z] + 2){
					    	c->blocks[x][y][z].ID = thisBiome.midBlock.ID;
					    	c->blocks[x][y][z].meta = thisBiome.midBlock.meta;
				    	}else if(rY + y == heightMap[x][z] + 2){
					    	c->blocks[x][y][z].ID = thisBiome.topBlock.ID;
					    	c->blocks[x][y][z].meta = thisBiome.topBlock.meta;
							if(rY + y < 63){
					    	c->blocks[x][y][z].ID = thisBiome.underBlock.ID;
					    	c->blocks[x][y][z].meta = thisBiome.underBlock.meta;
							}
				    	}
						else if(rY + y == heightMap[x][z] + 3){
					    	c->blocks[x][y][z].ID = thisBiome.aboveTop.ID;
					    	c->blocks[x][y][z].meta = thisBiome.aboveTop.meta;
				    	}else if(rY + y == 0){
							c->blocks[x][y][z].ID = 7;
							c->blocks[x][y][z].meta = 0;	
						}else{
					    	c->blocks[x][y][z].ID = 0;
					    	c->blocks[x][y][z].meta = 0;
				    	}

						if(rY + y <= 63 && c->blocks[x][y][z].ID == 0){
							c->blocks[x][y][z].ID = 8;
						}
			    	}
		    	}	
	    	}

		}
    }
}
#include "WorldProvider.h"
#include <Shadow/Utils/Logger.h>
#include <pspmath.h>
using namespace Shadow::Utils;
#include <cmath>
#include <iostream>

#define WATER_LEVEL 63

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


	std::map<int, BiomeProfile> bioMap;


    NoiseParameters forest = {
		0, 5.4, 2.7, 66, 1.0
	};
    NoiseParameters forestHills = {
		0, 6.5, 2.3, 66, 1.0
	};

	NoiseParameters plains = {
		0, 4.7, 4.2, 64, 1.0
	};
	NoiseParameters desert = {
		0, 4.7, 4.2, 66, 1.0
	};
    NoiseParameters mountains = {
		0, 12.6, 4.2, 68, 1.0
	};

	NoiseParameters plateaus = {
		0, 4.7, 4.2, 65, 1.0
	};

	NoiseParameters lakes = {
		0, 4.7, 4.2, 63, 1.0
	};

	glm::vec3 coldColor = {0.549, 0.71, 0.545};
	glm::vec3 hotColor = {0.686, 0.706, 0.333};
	glm::vec3 forestColor = {0.498f, 0.761f, 0.376f};
	glm::vec3 jungleColor = {0.498f, 0.861f, 0.376f};
	glm::vec3 plainsColor = {0.58, 0.737, 0.353};
	glm::vec3 savanna = {0.686, 0.806, 0.333};
	glm::vec3 defaultColor = {0.498f, 0.761f, 0.376f};
	glm::vec3 swampColor = {0.8f, 0.6f, 0.4f};

	//COLD

	//Rough
	BiomeProfile snowyMountainsBiome = {BIOME_Snow_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {78, 0}, coldColor};
    BiomeProfile taigaSnowyBiomeMountains = {BIOME_Snowy_Taiga_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {78, 0}, coldColor};
    BiomeProfile taigaBiomeMountains = {BIOME_Taiga_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {0, 0}, coldColor};
    
	//Hilly
	BiomeProfile taigaSnowyBiomeHills = {BIOME_Snowy_Taiga_Hills, forestHills, {2, 0}, {3, 0}, {3, 0}, {78, 0}, coldColor};
	BiomeProfile giantSpruceTaigaBiomeHills = {BIOME_Giant_Spruce_Taiga_Hills, forestHills, {3, 1}, {3, 0}, {3, 0}, {0, 0}, coldColor};
    BiomeProfile giantTreeTaigaBiomeHills = {BIOME_WOODLAND_HILLS, forestHills, {3,2}, {3, 0}, {3, 0}, {0, 0}, coldColor};
    BiomeProfile taigaBiomeHills = {BIOME_Taiga_Hills, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}, coldColor};
    
	//Smooth
	BiomeProfile giantTreeTaigaBiome = {BIOME_Giant_Tree_Taiga, forest, {3,2}, {3,0}, {3,0}, {0, 0}, coldColor};
    BiomeProfile giantSpruceTaigaBiome = {BIOME_Giant_Spruce_Taiga, forest, {3,1}, {3,0}, {3,0}, {0, 0}, coldColor};
	BiomeProfile taigaBiome = {BIOME_TAIGA, forest, {2,0}, {3,0}, {3,0}, {0, 0}, coldColor};
    
	//Flat
	BiomeProfile snowyTundraBiome = {BIOME_Snowy_Tundra, plains, {2,0}, {3,0}, {3,0}, {78, 0}, coldColor};
    BiomeProfile iceSpikesBiome = {BIOME_Ice_Spikes, plains, {2,0}, {3,0}, {3,0}, {78, 0}, coldColor};
    

	//TEMPERATE
	//Rough
    BiomeProfile mountainsBiome = {BIOME_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {0, 0}, coldColor};
    BiomeProfile woodedMountainsBiome = {BIOME_Wooded_Mountains, mountains, {2, 0}, {3, 0}, {3, 0}, {0, 0}, coldColor};
    BiomeProfile gravelMountainsBiome = {BIOME_Gravelly_Mountains, mountains, {13, 0}, {13, 0}, {13, 0}, {0, 0}, coldColor};
    BiomeProfile oceanBiome = {BIOME_OCEAN,{0, 8.7, 3.4, 40, 1.0},{13, 0}, {13,0}, {13,0}, {0, 0}, defaultColor};

	//Hills
	BiomeProfile woodlandBiomeHills = {BIOME_WOODLAND_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}, forestColor};
	BiomeProfile birchForestBiomeHills  = {BIOME_BIRCH_FOREST_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}, forestColor};
    BiomeProfile tallBirchForestBiomeHills = {BIOME_TALL_BIRCH_FOREST_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}, forestColor};
    BiomeProfile swampHillsBiome = {BIOME_Swamp_Hills, forest, {2,0}, {3,0}, {3,0}, {0, 0}, swampColor};
    
	//Smooth
    BiomeProfile riverBiome = {BIOME_RIVER,{0, 1, 1.5, 60, 1.0},{2, 0}, {3,0}, {3,0}, {0, 0}, defaultColor};
    BiomeProfile forestBiome = {BIOME_FOREST, forest, {2, 0}, {3, 0}, {3, 0}, {0, 0}, forestColor};
    BiomeProfile flowerForestBiome = {BIOME_FLOWER_FOREST, forest, {2, 0}, {3, 0}, {3,0}, {0, 0}, forestColor};
    BiomeProfile birchForestBiome= {BIOME_BIRCH_FOREST, forest, {2, 0}, {3, 0}, {3, 0}, {0, 0}, forestColor};
    BiomeProfile tallBirchForestBiome = {BIOME_BIRCH_FOREST, forest, {2,0}, {3,0}, {3,0}, {0, 0}, forestColor};
    BiomeProfile darkForestBiome = {BIOME_DARK_FOREST_HILLS, forest, {2,0}, {3,0}, {3,0}, {0, 0}, forestColor};
    BiomeProfile mushroomBiome = {BIOME_Mushroom_Fields, forest, {110,0}, {3,0}, {3,0}, {0, 0}, defaultColor};
    
	//Flat
	BiomeProfile mushroomShoreBiome = {BIOME_Mushroom_Fields_Shore, plains, {110,0}, {3,0}, {3,0}, {0, 0}, defaultColor};
    BiomeProfile swampBiome = {BIOME_Swamp, lakes, {2, 0}, {3, 0}, {3, 0}, {0, 0}, swampColor};
    BiomeProfile plainsBiome = {BIOME_Plains, plains, {2,0}, {3,0}, {3,0}, {0, 0}, plainsColor};
    BiomeProfile sunflowerPlainsBiome = {BIOME_Sunflower_Plains, plains, {2,0}, {3,0}, {3,0}, {0, 0}, plainsColor};
    
	//HOT

	//Rough
    BiomeProfile savannaPlateauBiome = {BIOME_Savanna_Plateau, plateaus, {2,0}, {3,0}, {3,0}, {0, 0}, savanna};
    BiomeProfile savannaShatteredPlateauBiome = {BIOME_Shattered_Savanna_Plateau, plateaus, {2,0}, {3,0}, {3,0}, {0, 0}, savanna};
	BiomeProfile mesaBiome = {BIOME_Badlands, mountains, {3, 1}, {3, 0}, {3, 0}, {0, 0}, hotColor};
    BiomeProfile mesaPlateauBiome = {BIOME_Badlands, plateaus, {3,1}, {3,0}, {3,0}, {0, 0}, hotColor};
	
	//Hills
	BiomeProfile desertBiomeHills = {BIOME_Desert_Hills, forest, {12,0}, {12,0}, {12,0}, {0, 0}, hotColor};
    BiomeProfile jungleBiomeHills = {BIOME_JUNGLE_HILLS, forestHills, {2, 0}, {3, 0}, {3, 0}, {0, 0}, jungleColor};
    BiomeProfile savannaShatteredBiome = {BIOME_Shattered_Savanna, forestHills, {2,0}, {3,0}, {3,0}, {0, 0}, savanna};
    
	//Smooth
    BiomeProfile savannaBiome = {BIOME_Savanna, forest, {2,0}, {3,0}, {3,0}, {0, 0}, savanna};
    BiomeProfile jungleBiome = {BIOME_JUNGLE, forest, {2,0}, {3,0}, {3,0}, {0, 0}, jungleColor};
    
	//Flat
	BiomeProfile desertBiome = {BIOME_Desert, desert, {12,0}, {12,0}, {12,0}, {0, 0}, hotColor};
	BiomeProfile desertLakesBiome = {BIOME_Desert_Lakes, plains, {12, 0}, {12, 0}, {12, 0}, {0, 0}, hotColor};
    BiomeProfile jungleEdgeBiome = {BIOME_JUNGLE_EDGE, plains, {2, 0}, {3, 0}, {3, 0}, {0, 0}, jungleColor};
    

	void WorldProvider::generate(Chunk* c){

		int rX = c->chunk_x * CHUNK_SIZE;
		int rY = c->chunk_y * CHUNK_SIZE;
		int rZ = c->chunk_z * CHUNK_SIZE;

		if(rX >= 0 && rY >= 0 && rZ >= 0){

        	int heightMap[16][16];

			int biomeMap[16][16];


			for(int x = 0; x < CHUNK_SIZE; x++){
				for(int z = 0; z < CHUNK_SIZE; z++){
					float temp = WorldProvider::noise->GetPerlin( (float)(rX + x)/256.f, (float)(rZ + z)/256.f);
					temp += 0.75f;
					temp /= 1.2f;

					if(temp < 0){
						temp = 0.05f;
					}
					if(temp > 1){
						temp = 0.95f;
					}

					temp = round(temp *40.f)/40.f;

					float roughness = WorldProvider::noise->GetSimplex( (float)(rX + x)/128.f, (float)(rZ + z)/128.f);
					roughness += 0.5f;
					temp /= 1.1f;

					if(roughness < 0){
						roughness = 0.05f;
					}
					if(roughness > 1){
						roughness = 0.95f;
					}

					roughness = round(roughness *40.f)/40.f;

					float river = WorldProvider::noise->GetPerlinFractal( (float)(rX + x) / 3.f, (float)(rZ + z) / 3.f);

					if(river > 0.175f && roughness < 0.7f && temp < 0.65f && !(temp >= 0.4f && temp < 0.45f && roughness >= 0.7f) ){
						biomeMap[x][z] = BIOME_RIVER;
						continue;
					}

					int bioRes = BIOME_FOREST;
					if(temp < 0.4){
						//COLD
						if(roughness < 0.3f){
							//FLAT
							if(temp < 0.05f){
								bioRes = BIOME_Ice_Spikes;
							}else{
								bioRes = BIOME_Snowy_Tundra;
							}
						}

						if(roughness >= 0.3f && roughness < 0.5f){
							//SMOOTH
							if(temp < 0.2f && temp > 0.16f){
								bioRes = BIOME_Giant_Spruce_Taiga;
							}else if(temp >= 0.2f && temp < 0.23f){
								bioRes = BIOME_Giant_Tree_Taiga;
							}else{
								bioRes = BIOME_TAIGA;
							}
						}

						if(roughness >= 0.5f && roughness < 0.7f){
							//HILLS
							if(temp < 0.2f){
								bioRes = BIOME_Snowy_Taiga_Hills;
							}else if(temp >= 0.2f && temp < 0.22f){
								bioRes = BIOME_Giant_Spruce_Taiga_Hills;
							}else if(temp >= 0.22f && temp <= 0.2f){
								bioRes = BIOME_Giant_Tree_Taiga_Hills;
							}else{
								bioRes = BIOME_Taiga_Hills;
							}
						}

						if(roughness >= 0.7f){
							//MOUNTAINS
							if(temp < 0.15f){
								bioRes = BIOME_Snow_Mountains;
							}else if(temp >= 0.15f && temp < 0.25f){
								bioRes = BIOME_Snowy_Taiga_Mountains;
							}else{
								bioRes = BIOME_Taiga_Mountains;
							}
						}


					}else if(temp > 0.4f && temp < 0.65f){
						//TEMPERATE
						if(roughness < 0.35f){
							//FLAT
							if(temp >= 0.4f && temp < 0.5f){
								bioRes = BIOME_Plains;
							}else if(temp >= 0.50f && temp < 0.55f){
								bioRes = BIOME_Swamp;
							}else if(temp >= 0.55f && temp < 0.675f){
								bioRes = BIOME_Plains;
							}else{
								bioRes = BIOME_Sunflower_Plains;
							}
						}

						if(roughness >= 0.35f && roughness < 0.5f){
							//SMOOTH

							if(temp >= 0.4f && temp < 0.45f){
								bioRes = BIOME_DARK_FOREST_HILLS;
							}else if(temp >= 0.45f && temp < 0.50f){
								bioRes = BIOME_FOREST;
							}else if(temp >= 0.5f && temp < 0.55f){
								bioRes = BIOME_FLOWER_FOREST;
							}else if(temp >= 0.55f && temp < 0.6f){
								bioRes = BIOME_BIRCH_FOREST;
							}else if(temp >= 0.6f && temp < 0.65f){
								bioRes = BIOME_TALL_BIRCH_FOREST;
							}
						}

						if(roughness >= 0.5f && roughness < 0.7f){
							//HILLS
							if(temp >= 0.4f && temp < 0.45f){
								bioRes = BIOME_WOODLAND_HILLS;
							}else if(temp >= 0.45f && temp < 0.50f){
								bioRes = BIOME_BIRCH_FOREST_HILLS;
							}else if(temp >= 0.50f && temp < 0.55f){
								bioRes = BIOME_TALL_BIRCH_FOREST_HILLS;
							}else if(temp >= 0.50f && temp < 0.55f){
								bioRes = BIOME_Swamp_Hills;
							}
						}

						if(roughness >= 0.7f){
							//MOUNTAINS
							if(temp >= 0.4f && temp < 0.45f){
								bioRes = BIOME_OCEAN;
							}else if(temp >= 0.45f && temp < 0.55f){
								bioRes = BIOME_Mountains;
							}else if(temp >= 0.5f && temp < 0.6f){
								bioRes = BIOME_Wooded_Mountains;
							}else{
								bioRes = BIOME_Gravelly_Mountains;
							}
						}
					}else{
						//HOT
						if(roughness < 0.67f){
							//FLAT
							if(temp >= 0.65f && temp < 0.7f){
								bioRes = BIOME_JUNGLE_EDGE;
							}else if(temp >= 0.7f && temp < 0.75f){
								bioRes = BIOME_Savanna;
							}else if(temp >= 0.75f && temp < 0.77f){
								bioRes = BIOME_Desert_Lakes;
							}else{
								bioRes = BIOME_Desert;
							}
						}

						if(roughness >= 0.3f && roughness < 0.5f){
							//SMOOTH
							if(temp < 0.7f){
								bioRes = BIOME_JUNGLE;
							}else{
								bioRes = BIOME_Desert;
							}
						}

						if(roughness >= 0.5f && roughness < 0.7f){
							//HILLS
							if(temp < 0.7f){
								bioRes = BIOME_JUNGLE_HILLS;
							}else if(temp >= 0.7f && temp < 0.75f){
								bioRes = BIOME_Shattered_Savanna;
							}else{
								bioRes = BIOME_Desert_Hills;
							}
						}

						if(roughness >= 0.7f){
							//MOUNTAINS
							if(temp < 0.7f){
								bioRes = BIOME_Savanna_Plateau;
							}else if(temp >= 0.7f && temp < 0.8f){
								bioRes = BIOME_Shattered_Savanna_Plateau;
							}else if(temp >= 0.8f && temp < 0.9f){
								bioRes = BIOME_Badlands;
							}else{
								bioRes = BIOME_Badlands_Plateau;
							}
						}
					}

					biomeMap[x][z] = bioRes;
				}
			}

        	for(int x = 0; x < CHUNK_SIZE; x++){
            	for(int z = 0; z < CHUNK_SIZE; z++){
					NoiseParameters profile = bioMap[biomeMap[x][z]].params;
                	heightMap[x][z] = getHeight(rX + x, rZ + z, profile);
            	}
        	}

        	for(int x = 0; x < CHUNK_SIZE; x++){


				    for(int z = 0; z < CHUNK_SIZE; z++){
						
					BiomeProfile thisBiome = bioMap[biomeMap[x][z]];
		    	for(int y = 0; y < CHUNK_SIZE; y++){
					    if(rY + y <= heightMap[x][z] && rY + y > 0){
						    c->blocks[x][y][z].ID = 1;
						    c->blocks[x][y][z].meta = 0;

							


				    	}else if(rY + y > heightMap[x][z] && rY + y < heightMap[x][z] + 2){
					    	c->blocks[x][y][z].ID = thisBiome.midBlock.ID;
					    	c->blocks[x][y][z].meta = thisBiome.midBlock.meta;
				    	}else if(rY + y == heightMap[x][z] + 2){
					    	c->blocks[x][y][z].ID = thisBiome.topBlock.ID;
					    	c->blocks[x][y][z].meta = thisBiome.topBlock.meta;
							if(rY + y < WATER_LEVEL){
					    	c->blocks[x][y][z].ID = thisBiome.underBlock.ID;
					    	c->blocks[x][y][z].meta = thisBiome.underBlock.meta;
							}
				    	}
						else if(rY + y == heightMap[x][z] + 3 && rY + y > WATER_LEVEL){
					    	c->blocks[x][y][z].ID = thisBiome.aboveTop.ID;
					    	c->blocks[x][y][z].meta = thisBiome.aboveTop.meta;

							vfpu_srand(seed + (rX + x - 1) * (rZ + z + 1));
							float rands = vfpu_randf(0, 1);

							if(rands > 0.65f && rY +y > WATER_LEVEL && (thisBiome.type == BIOME_Plains || thisBiome.type == BIOME_Sunflower_Plains || thisBiome.type == BIOME_Savanna_Plateau || thisBiome.type == BIOME_Savanna || thisBiome.type == BIOME_Shattered_Savanna || thisBiome.type == BIOME_FLOWER_FOREST)){
								if(thisBiome.type == BIOME_FLOWER_FOREST){
									c->blocks[x][y][z].ID = 38;
									c->blocks[x][y][z].meta = (int)vfpu_randf(0, 9);
									if(c->blocks[x][y][z].meta == 9){
										c->blocks[x][y][z].meta = 8;
									}
									if(c->blocks[x][y][z].meta == 1){
										c->blocks[x][y][z].meta = 0;
									}
								}else{
									int randomChoice = abs(noise->GetPerlin( (float)(rX + x)/3.f, (float)(rZ + z)/3.f  ) * 30.f);

										if(randomChoice >= 0 && randomChoice < 15){
											c->blocks[x][y][z].ID = 31;
											c->blocks[x][y][z].meta = 1;
										}else{
											c->blocks[x][y][z].ID = 37 + vfpu_randf(0, 1.2);
											if(c->blocks[x][y][z].ID == 38){
												c->blocks[x][y][z].meta = (int)vfpu_randf(0, 9);
												if(c->blocks[x][y][z].meta == 1){
													c->blocks[x][y][z].meta = 0;
													c->blocks[x][y][z].ID = 0;
												}
												if(c->blocks[x][y][z].meta == 2){
													c->blocks[x][y][z].meta = 0;
													c->blocks[x][y][z].ID = 0;
												}
												if(c->blocks[x][y][z].meta == 9){
													c->blocks[x][y][z].meta = 0;
													c->blocks[x][y][z].ID = 0;
												}
											}else{
												c->blocks[x][y][z].meta = 0;
											}
										}
								}
							}else if (rands > 0.875f && rY + y > WATER_LEVEL && thisBiome.type != BIOME_Gravelly_Mountains){
								
								if(thisBiome.type == BIOME_Desert || thisBiome.type == BIOME_Desert_Hills || thisBiome.type == BIOME_Desert_Lakes){
									int randomChoice = abs(noise->GetPerlin( (float)(rX + x)/3.f, (float)(rZ + z)/3.f  ) * 30.f);
										if(randomChoice >= 0 && randomChoice < 1){
											c->blocks[x][y][z].ID = 32;
											c->blocks[x][y][z].meta = 0;
										}
								}else{

									if(thisBiome.type == BIOME_TAIGA || thisBiome.type == BIOME_Taiga_Hills || thisBiome.type == BIOME_Taiga_Mountains || thisBiome.type == BIOME_Giant_Tree_Taiga || thisBiome.type == BIOME_Giant_Tree_Taiga_Hills || thisBiome.type == BIOME_Giant_Spruce_Taiga || thisBiome.type == BIOME_Giant_Spruce_Taiga_Hills){
										int randomChoice = vfpu_randf(0, 12);

										if(randomChoice >= 0 && randomChoice < 6){
											c->blocks[x][y][z].ID = 31;
											c->blocks[x][y][z].meta = 1;
										}else if(randomChoice >= 6 && randomChoice < 10){
											c->blocks[x][y][z].ID = 31;
											c->blocks[x][y][z].meta = 2;
										}else if(randomChoice == 10){
											c->blocks[x][y][z].ID = 39;
											c->blocks[x][y][z].meta = 0;
										}else if(randomChoice == 11){
											c->blocks[x][y][z].ID = 40;
											c->blocks[x][y][z].meta = 0;
										}else{
											c->blocks[x][y][z].ID = 38;
											c->blocks[x][y][z].meta = 1;
										}
									}else{
										int randomChoice = abs(noise->GetPerlin( (float)(rX + x)/3.f, (float)(rZ + z)/3.f  ) * 30.f);

										if(randomChoice >= 0 && randomChoice < 15){
											c->blocks[x][y][z].ID = 31;
											c->blocks[x][y][z].meta = 1;
										}else{
											c->blocks[x][y][z].ID = 37 + vfpu_randf(0, 1.2);
											c->blocks[x][y][z].meta = 0;
										}
									}
								}
							}



				    	}else if(rY + y == 0){
							c->blocks[x][y][z].ID = 7;
							c->blocks[x][y][z].meta = 0;	
						}else{
					    	c->blocks[x][y][z].ID = 0;
					    	c->blocks[x][y][z].meta = 0;
				    	}

						if(rY + y <= WATER_LEVEL && c->blocks[x][y][z].ID == 0){
							c->blocks[x][y][z].ID = 8;
						}

						float variance = noise->GetPerlin((float)(rX + x) * 1.3f, (float)(rY + y) * 1.56f, (float)(rZ+z) * 1.3f) * 1.5f + 0.99f;

						if(variance < 0.3f && c->blocks[x][y][z].ID != 8){
							c->blocks[x][y][z].ID = 0;
							c->blocks[x][y][z].meta = 0;	
						}



						c->blocks[x][y][z].biomeID = biomeMap[x][z];
			    	}
		    	}	
	    	}

		}
    }
}
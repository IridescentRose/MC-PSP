#include "WorldProvider.h"
#include <Shadow/Utils/Logger.h>

using namespace Shadow::Utils;

namespace Minecraft::Terrain{

    NoiseParameters defaultNoiseParams = {
		0, 20, 16, 35, 0.11
	};

    int WorldProvider::seed = 0;
    PerlinNoise* WorldProvider::noise = NULL;


	int getHeight(int x, int z, NoiseParameters noiseParams = defaultNoiseParams){

   		if (x < 0 || z < 0) {
        	return 64 - 1;
    	}

    	auto total = 0;

		int frequency = 2;
		
		total += WorldProvider::noise->noise((float)(x) / (float)defaultNoiseParams.smoothness, 0, (float)(z) / (float)defaultNoiseParams.smoothness) * (float) defaultNoiseParams.amplitude / defaultNoiseParams.roughness + defaultNoiseParams.heightOffset;;

		return total;
	}

    void WorldProvider::generate(Chunk* c){

		int rX = c->chunk_x * CHUNK_SIZE;
		int rY = c->chunk_y * CHUNK_SIZE;
		int rZ = c->chunk_z * CHUNK_SIZE;

		if(rX >= 0 && rY >= 0 && rZ >= 0){

        	int heightMap[16][16];

        	for(int x = 0; x < CHUNK_SIZE; x++){
            	for(int z = 0; z < CHUNK_SIZE; z++){
                	heightMap[x][z] = getHeight(rX + x, rZ + z);
            	}
        	}


        	for(int x = 0; x < CHUNK_SIZE; x++){
		    	for(int y = 0; y < CHUNK_SIZE; y++){
				    for(int z = 0; z < CHUNK_SIZE; z++){
						
						

					    if(rY + y <= heightMap[x][z] && rY + y > 0){
						    c->blocks[x][y][z].ID = 1;
						    c->blocks[x][y][z].meta = 0;
				    	}else if(rY + y > heightMap[x][z] && rY + y < heightMap[x][z] + 3){
					    	c->blocks[x][y][z].ID = 3;
					    	c->blocks[x][y][z].meta = 0;
				    	}else if(rY + y == heightMap[x][z] + 3){
					    	c->blocks[x][y][z].ID = 2;
							if(rY + y < 63){
								c->blocks[x][y][z].ID = 3;
							}
					    	c->blocks[x][y][z].meta = 0;
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
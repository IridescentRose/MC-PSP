#include "WorldProvider.h"
#include <Shadow/Utils/Logger.h>

using namespace Shadow::Utils;

namespace Minecraft::Terrain{

    NoiseParameters defaultNoiseParams = {
		2, 160, 16, -160, 0.11
	};

    int WorldProvider::seed = 0;
    PerlinNoise* WorldProvider::noise = NULL;


	int getHeight(int x, int z, NoiseParameters noiseParams = defaultNoiseParams){

   		if (x < 0 || z < 0) {
        	return 64 - 1;
    	}

    	auto totalValue = 0.0;

    	for (auto a = 0; a < noiseParams.octaves - 1; a++){
        	auto frequency = pow(2.0, a); // This increases the frequency with every loop of the octave.
        	auto amplitude = pow(noiseParams.roughness, a); // This decreases the amplitude with every loop of the octave.
        	totalValue += WorldProvider::noise->noise(((double)x) * frequency / noiseParams.smoothness, 0, ((double)z) * frequency / noiseParams.smoothness) * amplitude;
    	}

    	auto val = (((totalValue / 2.1) + 1.2) * noiseParams.amplitude) + noiseParams.heightOffset;

    	return val > 0 ? val : 1;
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
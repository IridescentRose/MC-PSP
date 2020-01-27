#include "WorldProvider.h"
#include <Shadow/Utils/Logger.h>

using namespace Shadow::Utils;

namespace Minecraft::Terrain{

    int WorldProvider::seed = 0;
    PerlinNoise* WorldProvider::noise = NULL;

    void WorldProvider::generate(Chunk* c){

		int rX = c->chunk_x * CHUNK_SIZE;
		int rY = c->chunk_y * CHUNK_SIZE;
		int rZ = c->chunk_z * CHUNK_SIZE;

		if(rX >= 0 && rY >= 0 && rZ >= 0){

        	int heightMap[16][16];

        	for(int x = 0; x < CHUNK_SIZE; x++){
            	for(int z = 0; z < CHUNK_SIZE; z++){
                	heightMap[x][z] = noise->noise((float)(rX + x) / 32.f, 0, (float)(rZ + z) / 32.f) * 35 + 42;
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
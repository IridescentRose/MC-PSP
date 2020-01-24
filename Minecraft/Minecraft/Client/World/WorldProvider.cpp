#include "WorldProvider.h"

namespace Minecraft::Terrain{

    int WorldProvider::seed = 0;

    void WorldProvider::generate(Chunk* c){
        for(int x = 0; x < CHUNK_SIZE; x++){
		    for(int y = 0; y < CHUNK_SIZE; y++){
			    for(int z = 0; z < CHUNK_SIZE; z++){

				    int rX = c->chunk_x * CHUNK_SIZE;
				    int rY = c->chunk_y * CHUNK_SIZE;
				    int rZ = c->chunk_z * CHUNK_SIZE;

				    if(rY + y <= 63){
					    c->blocks[x][y][z].ID = 1;
					    c->blocks[x][y][z].meta = 2;
			    	}else if(rY + y > 63 && rY + y < 67){
					    c->blocks[x][y][z].ID = 3;
					    c->blocks[x][y][z].meta = 0;
				    }else if(rY + y == 67){
					    c->blocks[x][y][z].ID = 2;
					    c->blocks[x][y][z].meta = 0;
				    }else{
					    c->blocks[x][y][z].ID = 0;
					    c->blocks[x][y][z].meta = 0;
				    }
			    }
		    }	
	    }
    }
}
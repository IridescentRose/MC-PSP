#include "BlockData.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

BlockData::BlockData()
{

}

void BlockData::loadBlockData()
{
	//AIR
	block_data.emplace(ChunkBlock(0, 0), new Block(-1, -1, -1, -1, -1, -1, 
												0, 0, true, false, false));

	//STONE
	block_data.emplace(ChunkBlock(1, 0), new Block(1, 1, 1, 1, 1, 1, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 0));
	//GRANITE
	block_data.emplace(ChunkBlock(1, 1), new Block(2, 2, 2, 2, 2, 2, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 1));
	//POLISHED GRANITE
	block_data.emplace(ChunkBlock(1, 2), new Block(3, 3, 3, 3, 3, 3, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 2));
	//DIORITE
	block_data.emplace(ChunkBlock(1, 3), new Block(4, 4, 4, 4, 4, 4, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 3));
	//POLISHED DIORITE
	block_data.emplace(ChunkBlock(1, 4), new Block(5, 5, 5, 5, 5, 5, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 4));
	//ANDESITE
	block_data.emplace(ChunkBlock(1, 5), new Block(6, 6, 6, 6, 6, 6, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 5));
	//POLISHED ANDESITE
	block_data.emplace(ChunkBlock(1, 6), new Block(7, 7, 7, 7, 7, 7, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(1, 6));
	//GRASS
	block_data.emplace(ChunkBlock(2, 0), new Block(8, 11, 9, 9, 9, 9, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(2, 0));
	//DIRT
	block_data.emplace(ChunkBlock(3, 0), new Block(11, 11, 11, 11, 11, 11, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(3, 0));
	//COARSE DIRT
	block_data.emplace(ChunkBlock(3, 1), new Block(12, 12, 12, 12, 12, 12, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(3, 1));
	//PODZOL
	block_data.emplace(ChunkBlock(3, 2), new Block(13, 11, 14, 14, 14, 14, 
												0, 0, false, false, false));
	registered_blocks.push_back(ChunkBlock(3, 2));

}
BlockData BlockData::instance;

BlockData *BlockData::InstancePointer()
{
	return &instance;
}
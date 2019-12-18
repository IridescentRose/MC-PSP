#include "BlockData.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

BlockData::BlockData()
{

}

void BlockData::loadBlockData()
{
	FILE* blockDatabase;
	blockDatabase = fopen("assets/blockData.dat", "r");
	if (blockDatabase == NULL) {
		//WE HAVE A PROBLEM... which cannot be detected.
		return;
	}
	fread(blockData, sizeof(struct Block), NUM_BLOCKS, blockDatabase);
	fclose(blockDatabase);
}
BlockData BlockData::instance;

BlockData *BlockData::InstancePointer()
{
	return &instance;
}
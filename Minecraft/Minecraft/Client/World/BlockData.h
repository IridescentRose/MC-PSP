#pragma once

struct Block {
	char ID, meta, topAtlas, bottomAtlas, frontAtlas, backAtlas, leftAtlas, rightAtlas, meshType;
	bool breakable, transparent, lightSource, special;
};

struct ChunkBlock {
	char ID; //We'll get some more stuff here later?
    char meta;
};

#define NUM_BLOCKS 4

class BlockData {
public:
	BlockData();
	void loadBlockData();
	static BlockData* InstancePointer();

	Block blockData[NUM_BLOCKS];

protected:
	static BlockData instance;
};
#pragma once
#include <unordered_map>
#include <map>
#include <vector>

class Block {
	public:

	Block(short tpa, short bta, short fra, short baa, short lta, short rta, short mT, short rT, bool tr, bool li, bool sp){
		topAtlas = tpa;
		bottomAtlas = bta;
		frontAtlas = fra;
		backAtlas = baa;
		leftAtlas = lta;
		rightAtlas = rta;

		meshType = mT;
		renderType = rT;

		transparent = tr;
		lightSource = li;
		special = sp;
	}

	short topAtlas, bottomAtlas, frontAtlas, backAtlas, leftAtlas, rightAtlas, meshType, renderType;
	bool transparent;
	bool lightSource;
	bool special;
};

class ChunkBlock {
	public:

	ChunkBlock(){
		ID = 0;
		meta = 0;
	}

	ChunkBlock(char i, char m){
		ID = i;
		meta = m;
	}

	inline bool operator==(const ChunkBlock& p) const{
		return p.ID == ID && p.meta == meta;
	}

	char ID; //We'll get some more stuff here later?
    char meta;
};

class ChunkBlockExtended : public ChunkBlock{
	public:

	char biomeID;

	ChunkBlockExtended(): ChunkBlock(0, 0){
		biomeID = 0;
	}
	ChunkBlockExtended(char i, char m) : ChunkBlock(i, m){
		biomeID = 0;
	}
};

class ChunkBlockHasher{
public:

	size_t operator() (const ChunkBlock& key) const {
        size_t hash = ((size_t)key.meta << 8) | key.ID;
        return hash;
    }
};


#define NUM_BLOCKS 4
using BlockRegistry = std::unordered_map<ChunkBlock, Block*, ChunkBlockHasher>;


class BlockData {
public:
	BlockData();
	void loadBlockData();
	static BlockData* InstancePointer();

	BlockRegistry block_data;
	std::vector<ChunkBlock> registered_blocks;

protected:
	static BlockData instance;
};
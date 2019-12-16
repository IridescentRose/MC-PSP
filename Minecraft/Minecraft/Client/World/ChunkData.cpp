#include "ChunkData.h"

Minecraft::Terrain::ChunkData::ChunkData() {
	relativeX = 0;
	relativeY = 0;
	relativeZ = 0;

	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				data[x][y][z] = { 0, 0 };
			}
		}
	}
}

Minecraft::Terrain::ChunkData::~ChunkData()
{
}

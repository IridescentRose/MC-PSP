#pragma once

#include <mclib/block/Block.h>

namespace Minecraft::Terrain {

	struct BlockData {
		int id;
		int meta;
	};
	
	class ChunkColumnData {
	private:
		int relativeX, relativeZ;
		BlockData data[16][256][16];

	public:
		ChunkColumnData();
		~ChunkColumnData();


		inline int getRelativeX() {
			return relativeX;
		}

		inline void setRelativeX(int x) {
			relativeX = x;
		}
		inline void setRelativeZ(int z) {
			relativeZ = z;
		}

		inline int getRelativeZ() {
			return relativeZ;
		}

		inline BlockData* getBlock(int x, int y, int z) {
			return &data[x][y][z];
		}

	};
}
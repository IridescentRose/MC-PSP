#pragma once

#include <mclib/block/Block.h>

namespace Minecraft::Terrain {

	struct BlockData {
		int id;
		int meta;
	};
	
	class ChunkData {
	private:
		int relativeX, relativeY, relativeZ;
		BlockData data[16][16][16];

	public:
		ChunkData();
		~ChunkData();


		inline int getRelativeX() {
			return relativeX;
		}
		inline int getRelativeY() {
			return relativeY;
		}
		inline int getRelativeZ() {
			return relativeZ;
		}

		inline void setRelativeX(int x) {
			relativeX = x;
		}
		inline void setRelativeY(int y) {
			relativeY = y;
		}
		inline void setRelativeZ(int z) {
			relativeZ = z;
		}


		inline BlockData* getBlock(int x, int y, int z) {
			return &data[x][y][z];
		}

	};
}
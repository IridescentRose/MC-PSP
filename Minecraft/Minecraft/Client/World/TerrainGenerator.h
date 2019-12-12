#pragma once
#include "ChunkData.h"

namespace Minecraft::Terrain {
	namespace SimpleGenerator {
		inline ChunkColumnData* generateTerrain(int relativeX, int relativeZ) {
			ChunkColumnData* res = new ChunkColumnData();
			res->setRelativeX(relativeX);
			res->setRelativeX(relativeZ);

			for (int y = 0; y < 256; y++) {
				for (int x = 0; x < 16; x++) {
					for (int z = 0; z < 16; z++) {
						if (y == 0)
							res->getBlock(x, y, z)->id = 1;
						else if (y <= 63 && y < 67)
							res->getBlock(x, y, z)->id = 3;
						else if (y == 67)
							res->getBlock(x, y, z)->id = 2;
					}
				}
			}

			return res;
		}

	}
}
#pragma once
#include "ChunkData.h"

namespace Minecraft::Terrain {
	namespace SimpleGenerator {
		inline ChunkData* generateTerrain(int relativeX, int relativeY, int relativeZ) {
			ChunkData* res = new ChunkData();
			res->setRelativeX(relativeX);
			res->setRelativeY(relativeY);
			res->setRelativeX(relativeZ);


			for (int y = 0; y < 16; y++) {
				for (int x = 0; x < 16; x++) {
					for (int z = 0; z < 16; z++) {
						int rY = relativeY*16 + y;

						if (rY == 0)
							res->getBlock(x, y, z)->id = 1;
						else if (rY <= 63 && rY < 67)
							res->getBlock(x, y, z)->id = 3;
						else if (rY == 67)
							res->getBlock(x, y, z)->id = 2;
					}
				}
			}

			return res;
		}

	}
}
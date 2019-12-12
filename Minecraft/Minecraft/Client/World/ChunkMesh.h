#pragma once

#include <array>
#include <vector>
#include <mclib/common/Vector.h>

namespace Minecraft::Terrain {
	class ChunkMesh {
	public:
		ChunkMesh();
		~ChunkMesh();

		void addFace(int faceType, const float blockFace[12], std::array<float, 8> texCoords,
			mc::Vector3i chunkPosition,
			mc::Vector3i blockPosition);

		void bufferMesh();

		int faces;
		std::vector<float> verticeData;

	};

	struct ChunkMeshCollection
	{
		ChunkMesh solidMesh;
		ChunkMesh waterMesh;
		ChunkMesh floraMesh;
	};
}
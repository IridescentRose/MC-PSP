#pragma once

#include "ChunkData.h"
#include "ChunkMesh.h"
#include <array>
namespace Minecraft::Terrain {
	class Chunk {
	public:
		Chunk();
		~Chunk();

		void generateData(int relX, int relZ, int relY);
		void generateMesh();
		void tryAddFaceToMesh(const short blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3i& blockFacing, int type);

		void Update();
		void Draw();

	private:
		ChunkData* data;
		ChunkMeshCollection meshes;
		ChunkMesh* mesh;

		
	};
}
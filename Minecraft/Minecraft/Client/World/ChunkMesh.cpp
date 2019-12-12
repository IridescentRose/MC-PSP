#include "ChunkMesh.h"

#define CHUNK_SIZE 16

namespace Minecraft::Terrain {
#include "ChunkMesh.h"

	ChunkMesh::ChunkMesh()
	{
		faces = 0;
	}

	ChunkMesh::~ChunkMesh()
	{
	}

	void ChunkMesh::addFace(int faceType, const float blockFace[12], std::array<float, 8> texCoords, mc::Vector3i chunkPosition, mc::Vector3i blockPosition)
	{
		//IMPLEMENT
	}

	void ChunkMesh::bufferMesh()
	{
		faces = 0;
		//CLEAR DATA
		verticeData.clear();
		//Proper Shrink To Fit for pre C++ 11
		std::vector<float>(verticeData).swap(verticeData);
	}
}
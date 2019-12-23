#pragma once
#include "ChunkMesh.h"
#include <array>
#include <mclib/common/Vector.h>
#include "BlockData.h"
#define CHUNK_SIZE 16

namespace Minecraft::Terrain{

class Chunk {
public:
	Chunk();
	~Chunk();

	ChunkBlock getBlockAtTranslatedLocation(unsigned int x, unsigned int y, unsigned int z);

	void generateData();

	void generateMesh();
	void updateMesh();
	void updateMeshLightingOnly();

	void Draw();
	void Update();

	void tryAddFaceToMesh(const short blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3f& blockFacing, int type);

	//MESH
	
	//Block Data organized by XYZ
	ChunkBlock blocks[16][16][16];
	ChunkMeshCollection meshes;
	ChunkMesh* mesh;
	//CHUNK COORDINATES
	int chunk_x, chunk_y, chunk_z;

	bool hasMesh;
};

}
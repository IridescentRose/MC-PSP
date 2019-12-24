#pragma once
#include "ChunkMesh.h"
#include <array>
#include <mclib/common/Vector.h>
#include "BlockData.h"
#include <map>
#define CHUNK_SIZE 16

namespace Minecraft::Terrain{

class ChunkManager;

class Chunk {
public:
	Chunk();
	~Chunk();

	ChunkBlock getBlockAtTranslatedLocation(unsigned int x, unsigned int y, unsigned int z);

	void generateData();

	void generateMesh(ChunkManager* man);
	void updateMesh();
	void updateMeshLightingOnly();

	void Draw();
	void Update();

	void tryAddFaceToMesh(const short blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3f& blockFacing, int type, ChunkManager* man);

	//MESH
	
	//Block Data organized by XYZ
	ChunkBlock blocks[16][16][16];
	ChunkMeshCollection meshes;
	ChunkMesh* mesh;
	//CHUNK COORDINATES
	int chunk_x, chunk_y, chunk_z;

	bool hasMesh;
};

using ChunkMap = std::map<mc::Vector3i, Chunk*>;
        class ChunkManager
        {
            public:
                ChunkManager();

                Chunk*      getChunk    (int x, int y, int z);
                ChunkMap&   getChunks   ();

                bool chunkExists(int x, int y, int z);

                void loadChunkData(int x, int y, int z);
                void loadChunkMesh(int x, int y, int z);
                void unloadChunk(int x, int y, int z);
        };
        extern ChunkMap m_chunks;

}
#pragma once
#include "ChunkMesh.h"
#include <array>
#include "BlockData.h"
#include <map>
#include "WorldProvider.h"
#define CHUNK_SIZE 16
#include <Math/AABB.h>
#include <mclib/common/Vector.h>
#include <fstream>
#include <Graphics/TextureUtil.h>

using namespace Stardust::Math;

namespace Minecraft::Terrain{

struct ChunkDataEntry{
	glm::vec3 position;
	ChunkBlock blk;
};

class ChunkManager;
class WorldProvider;
class Chunk {
public:
	Chunk();
	~Chunk();

	ChunkBlock getBlockAtTranslatedLocation(unsigned int x, unsigned int y, unsigned int z);

	void generateData();
	void generateStructures(ChunkManager* man);
	void loadCheck();

	void generateMesh(ChunkManager* man);
	void deleteMesh();
	void updateMesh(ChunkManager* man);
	void updateLighting(int level, int ll);

	void Draw();
	void DrawTrans();
	void Update(float dt);

	void tryAddFaceToMesh(const float blockFace[12], std::array<float, 8> texCoords, const glm::vec3& blockPosition, const glm::vec3& blockFacing, int type, ChunkManager* man, glm::vec3 colorOffsets);

	//MESH
	
	//Block Data organized by XYZ
	ChunkBlockExtended blocks[16][16][16];
	ChunkMeshCollection meshes;
	ChunkMesh* mesh;
	//CHUNK COORDINATES
	int chunk_x, chunk_y, chunk_z;

	float animPos;
	bool firstShow;

	AABB m_aabb;

	bool hasStruct;
	bool hasMesh;

	std::vector<ChunkDataEntry> delta;

	void save();

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
                void loadChunkData2(int x, int y, int z);
                void loadChunkData3(int x, int y, int z);
                void loadChunkMesh(int x, int y, int z);
                void unloadChunk(int x, int y, int z);
				void updateChunk(int x, int y, int z);
				void updateLightingAll(int level, int ll);

				ChunkBlock getBlock(int x, int y, int z);
				void setBlock(int x, int y, int z, ChunkBlock blk);
        };
        extern ChunkMap m_chunks;

}
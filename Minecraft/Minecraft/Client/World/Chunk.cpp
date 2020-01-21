#include "Chunk.h"
#include <mclib/common/Vector.h>
#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Utils/Logger.h>
#include <Shadow/System/Ram.h>
using namespace Shadow;

using namespace Shadow::Utils;

namespace Minecraft::Terrain{
ChunkMap m_chunks;
    ChunkManager::ChunkManager(){
        m_chunks.clear();
    }

    Chunk* ChunkManager::getChunk(int x, int y, int z){
        if (!chunkExists(x, y, z)){
            return NULL;
        }
        return m_chunks[mc::Vector3i(x, y, z)];
    }
    ChunkMap& ChunkManager::getChunks(){
        return m_chunks;
    }

    bool ChunkManager::chunkExists(int x, int y, int z){
        return m_chunks.find(mc::Vector3i(x, y, z)) != m_chunks.end();
    }

    void ChunkManager::loadChunkData(int x, int y, int z){
        Chunk* c = new Chunk();
        c->chunk_x = x;
        c->chunk_y = y;
        c->chunk_z = z;

        c->generateData();

        m_chunks.emplace(mc::Vector3i(x, y, z), std::move(c));
    }

    void ChunkManager::loadChunkMesh(int x, int y, int z){
        if(chunkExists(x, y, z)){
            m_chunks[mc::Vector3i(x,y,z)]->generateMesh(this);
        }
    }
    
    void ChunkManager::unloadChunk(int x, int y, int z){
        if(chunkExists(x, y, z)){
            delete m_chunks[mc::Vector3i(x, y, z)]; //Safety
            m_chunks.erase(mc::Vector3i(x, y, z));
        }
    }

	void ChunkManager::updateChunk(int x, int y, int z){
		if(chunkExists(x, y, z)){
			m_chunks[mc::Vector3i(x,y,z)]->updateMesh(this);
		}
	}
const short backFace[12] =
{
	0, 0, 0,
	0, 1, 0,
	1, 1, 0,
	1, 0, 0,
};

const short frontFace[12] =
{
	0, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 1, 1,
};

const short rightFace[12] =
{
	1, 0, 0,
	1, 1, 0,
	1, 1, 1,
	1, 0, 1,
};

const short leftFace[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 1, 1,
	0, 1, 0,
};

const short topFace[12] =
{
	0, 1, 0,
	0, 1, 1,
	1, 1, 1,
	1, 1, 0
};

const short bottomFace[12] =
{
	0, 0, 0,
	1, 0, 0,
	1, 0, 1,
	0, 0, 1,
};



const short crossPlane1[12] =
{
	0, 0, 0,
	1, 0, 1,
	1, 1, 1,
	0, 1, 0,
};

const short crossPlane2[12] =
{
	0, 0, 1,
	1, 0, 0,
	1, 1, 0,
	0, 1, 1,
};

struct LocalFaces{
	void update(int x, int y, int z)
	{
		up.x = x; up.y = y + 1; up.z = z;
		down.x = x; down.y = y - 1; down.z = z;
		left.x = x - 1; left.y = y; left.z = z;
		right.x = x + 1; right.y = y; right.z = z;
		front.x = x; front.y = y; front.z = z + 1;
		back.x = x; back.y = y; back.z = z - 1;
	}

	mc::Vector3f up;
	mc::Vector3f down;
	mc::Vector3f left;
	mc::Vector3f right;
	mc::Vector3f front;
	mc::Vector3f back;
};

Chunk::Chunk()
{
	struct ChunkBlock c;
	c.ID = 0;
	c.meta = 0;
	chunk_x = 0;
	chunk_y = 0;
	chunk_z = 0;
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				blocks[x][y][z] = c;
			}
		}
	}
	sceKernelDcacheWritebackInvalidateAll();
	hasMesh = false;
}

Chunk::~Chunk()
{
	
}

ChunkBlock Chunk::getBlockAtTranslatedLocation(unsigned int x, unsigned int y, unsigned int z)
{
	return blocks[x][y][z];
}


int numFaces;

std::array<float, 8> getTextureAtlasIndex(int idx){
	//Index is 32x32
	int rIDX = idx - 1;

	int row = rIDX / 32;
	int column = rIDX % 32;

	float size = 1.f / 32.f;
	float y = (float)row * size;
	float x = (float)column * size;
	float h = y + size;
	float w = x + size;

	return {
		w, h,
		x, h,
		x, y,
		w, y,
	};
}

void Chunk::generateMesh(ChunkManager* man)
{
	LocalFaces faces;
	numFaces = 0;
	for (char y = 0; y < CHUNK_SIZE; y++) {
		for (char z = 0; z < CHUNK_SIZE; z++) {
			for (char x = 0; x < CHUNK_SIZE; x++) {
				ChunkBlock temp = blocks[x][y][z];
				mc::Vector3i position;
				position.x = x; position.y = y; position.z = z;

				if (temp.ID == 0) { //DONT TRY TO GENERATE AIR!
					continue;
				}

				Block* blockData = BlockData::InstancePointer()->block_data[temp];
				//Multi mesh support (similar to gbuffers)

				switch(blockData->meshType){
					case 0:{
						mesh = &meshes.solidMesh;
						break;
					}
					case 1:{
						mesh = &meshes.floraMesh;
						break;
					}
					case 2:{
						mesh = &meshes.waterMesh;
						break;
					}
				}

				//TODO: ADD CROSS PLANE BLOCKS LATER (flowers, grass, etc)

				faces.update(x, y, z);

				tryAddFaceToMesh(bottomFace, getTextureAtlasIndex(blockData->bottomAtlas), position, faces.down, TYPE_BOTTOM, man);
				tryAddFaceToMesh(topFace, getTextureAtlasIndex(blockData->topAtlas), position, faces.up, TYPE_TOP, man);

				//Left/ Right
				tryAddFaceToMesh(leftFace, getTextureAtlasIndex(blockData->leftAtlas), position, faces.left, TYPE_LEFT, man);
				tryAddFaceToMesh(rightFace, getTextureAtlasIndex(blockData->rightAtlas), position, faces.right, TYPE_RIGHT, man);

				//Front/ Back
				tryAddFaceToMesh(frontFace, getTextureAtlasIndex(blockData->frontAtlas), position, faces.front, TYPE_FRONT, man);
				tryAddFaceToMesh(backFace, getTextureAtlasIndex(blockData->backAtlas), position, faces.back, TYPE_BACK, man);

			}
		}
	}
	hasMesh = true;
	Logging::debug("Mesh generated with " + std::to_string(numFaces) + " faces.");
}

void Chunk::deleteMesh(){
	meshes.solidMesh.clear();
	meshes.floraMesh.clear();
	meshes.waterMesh.clear();
}

void Chunk::updateMesh(ChunkManager* man)
{
	deleteMesh();
	generateMesh(man);
}

void Chunk::generateData(){
	for(int x = 0; x < CHUNK_SIZE; x++){
		for(int y = 0; y < CHUNK_SIZE; y++){
			for(int z = 0; z < CHUNK_SIZE; z++){

				int rX = chunk_x * CHUNK_SIZE;
				int rY = chunk_y * CHUNK_SIZE;
				int rZ = chunk_z * CHUNK_SIZE;

				if(rY + y <= 63){
					blocks[x][y][z].ID = 1;
					blocks[x][y][z].meta = 2;
				}else if(rY + y > 63 && rY + y < 67){
					blocks[x][y][z].ID = 3;
					blocks[x][y][z].meta = 0;
				}else if(rY + y == 67){
					blocks[x][y][z].ID = 2;
					blocks[x][y][z].meta = 0;
				}else{
					blocks[x][y][z].ID = 0;
					blocks[x][y][z].meta = 0;
				}
			}
		}	
	}
}

void Chunk::Draw()
{

	sceGumPushMatrix();
	ScePspFVector3 v = {chunk_x * 16, chunk_y * 16, chunk_z * 16};
	sceGumTranslate(&v);


	sceGuEnable(GU_TEXTURE_2D);
	sceGuEnable(GU_BLEND);
	sceGuEnable(GU_CULL_FACE);
	
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.topVertexData.size(), 0, meshes.solidMesh.topVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.bottomVertexData.size(), 0, meshes.solidMesh.bottomVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.frontVertexData.size(), 0, meshes.solidMesh.frontVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.backVertexData.size(), 0, meshes.solidMesh.backVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.leftVertexData.size(), 0, meshes.solidMesh.leftVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.rightVertexData.size(), 0, meshes.solidMesh.rightVertexData.data());
	

	sceGuDisable(GU_CULL_FACE);
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.floraMesh.topVertexData.size(), 0, meshes.floraMesh.topVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.floraMesh.bottomVertexData.size(), 0, meshes.floraMesh.bottomVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.floraMesh.frontVertexData.size(), 0, meshes.floraMesh.frontVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.floraMesh.backVertexData.size(), 0, meshes.floraMesh.backVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.floraMesh.leftVertexData.size(), 0, meshes.floraMesh.leftVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.floraMesh.rightVertexData.size(), 0, meshes.floraMesh.rightVertexData.data());
	
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.waterMesh.topVertexData.size(), 0, meshes.waterMesh.topVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.waterMesh.bottomVertexData.size(), 0, meshes.waterMesh.bottomVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.waterMesh.frontVertexData.size(), 0, meshes.waterMesh.frontVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.waterMesh.backVertexData.size(), 0, meshes.waterMesh.backVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.waterMesh.leftVertexData.size(), 0, meshes.waterMesh.leftVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.waterMesh.rightVertexData.size(), 0, meshes.waterMesh.rightVertexData.data());
	
	sceGuDisable(GU_BLEND);
	sceGuDisable(GU_TEXTURE_2D);
	sceGuDisable(GU_CULL_FACE);


	sceGumPopMatrix();
}

void Chunk::Update()
{
}


ChunkBlock ChunkManager::getBlock(int x, int y, int z){
	ChunkBlock res = {0, 0};
	
	if(chunkExists(x/16, y/16, z/16)){
		res = m_chunks[mc::Vector3i(x/16, y/16, z/16)]->blocks[x%16][y%16][z%16];
	}

	return res;
}

void ChunkManager::updateLightingAll(int level){
	for(const auto& [key, chnk] : m_chunks){
		chnk->updateLighting(level);
	}
}

void Chunk::updateLighting(int level){
	meshes.solidMesh.updateLighting(level);
	meshes.floraMesh.updateLighting(level);
	meshes.waterMesh.updateLighting(level);
}

void Chunk::tryAddFaceToMesh(const short blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3f& blockFacing, int type, ChunkManager* man)
{
	
	if ((blockFacing.x >= 0 && blockFacing.x < 16) && (blockFacing.y >= 0 && blockFacing.y < 16) && (blockFacing.z >= 0 && blockFacing.z < 16)) {
		ChunkBlock cblk = blocks[(int)blockFacing.x][(int)blockFacing.y][(int)blockFacing.z];
		Block* blk = BlockData::InstancePointer()->block_data[cblk];

		if(blk->transparent || cblk.ID == 0){
			numFaces++;
			mesh->addFace(type, blockFace, texCoords, {chunk_x, chunk_y, chunk_z}, blockPosition);
		}

	}
	else { //Default generate

		ChunkBlock cblk = man->getBlock(blockFacing.x + chunk_x * CHUNK_SIZE,blockFacing.y + chunk_y * CHUNK_SIZE, blockFacing.z + chunk_z * CHUNK_SIZE);
		Block* blk = BlockData::InstancePointer()->block_data[cblk];

		if(blk->transparent || cblk.ID == 0){
			numFaces++;
			mesh->addFace(type, blockFace, texCoords, {chunk_x, chunk_y, chunk_z}, blockPosition);
		}


		}
	}
	
}

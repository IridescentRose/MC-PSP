#include "Chunk.h"
#include <Graphics/RendererCore.h>
#include <Utilities/Logger.h>

using namespace Stardust;
#include <iostream>
using namespace Stardust::Utilities;


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

    void ChunkManager::loadChunkData2(int x, int y, int z){
		if(chunkExists(x, y, z)){
        	Chunk* c = m_chunks[mc::Vector3i(x, y, z)];
			c->generateStructures(this);
		}
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
const float backFace[12] =
{
	0, 0, 0,
	0, 1, 0,
	1, 1, 0,
	1, 0, 0,
};

const float frontFace[12] =
{
	0, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 1, 1,
};

const float rightFace[12] =
{
	1, 0, 0,
	1, 1, 0,
	1, 1, 1,
	1, 0, 1,
};

const float leftFace[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 1, 1,
	0, 1, 0,
};

const float backFaceOverlay[12] =
{
	0, 0, -0.010f,
	0, 1, -0.010f,
	1, 1, -0.010f,
	1, 0, -0.010f,
};

const float frontFaceOverlay[12] =
{
	0, 0, 1.010f,
	1, 0, 1.010f,
	1, 1, 1.010f,
	0, 1, 1.010f,
};

const float rightFaceOverlay[12] =
{
	1.010f, 0, 0,
	1.010f, 1, 0,
	1.010f, 1, 1,
	1.010f, 0, 1,
};

const float leftFaceOverlay[12] =
{

	-0.010f, 0, 0,
	-0.010f, 0, 1,
	-0.010f, 1, 1,
	-0.010f, 1, 0,
};

const float topFace[12] =
{
	0, 1, 0,
	0, 1, 1,
	1, 1, 1,
	1, 1, 0
};

const float bottomFace[12] =
{
	0, 0, 0,
	1, 0, 0,
	1, 0, 1,
	0, 0, 1,
};

const float wheatB[12] =
{
	0, 0, 0.25,
	0, 1, 0.25,
	1, 1, 0.25,
	1, 0, 0.25,
};

const float wheatF[12] =
{
	0, 0, 0.75,
	1, 0, 0.75,
	1, 1, 0.75,
	0, 1, 0.75,
};

const float wheatR[12] =
{
	0.75, 0, 0,
	0.75, 1, 0,
	0.75, 1, 1,
	0.75, 0, 1,
};

const float wheatL[12] =
{

	0.25, 0, 0,
	0.25, 0, 1,
	0.25, 1, 1,
	0.25, 1, 0,
};

const float xFace1[12]{
    0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0,
};

const float xFace2[12]{
    0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
};

const float ladder[12]{
	0.9375, 0, 0,
	0.9375, 0, 1,
	0.9375, 1, 1,
	0.9375, 1, 0,
};

const float carpetT[12]{
	0, 0.0625, 0,
	1, 0.0625, 0,
	1, 0.0625, 1,
	0, 0.0625, 1,
};

const float carpetB[12] =
{
	0, 0, 0,
	0, 0.0625, 0,
	1, 0.0625, 0,
	1, 0, 0,
};

const float carpetF[12] =
{
	0, 0, 1,
	1, 0, 1,
	1, 0.0625, 1,
	0, 0.0625, 1,
};

const float carpetR[12] =
{
	1, 0, 0,
	1, 0.0625, 0,
	1, 0.0625, 1,
	1, 0, 1,
};

const float carpetL[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 0.0625, 1,
	0, 0.0625, 0,
};

const float slabT[12]{
	0, 0.5, 0,
	1, 0.5, 0,
	1, 0.5, 1,
	0, 0.5, 1,
};

const float slabB[12] =
{
	0, 0, 0,
	0, 0.5, 0,
	1, 0.5, 0,
	1, 0, 0,
};

const float slabF[12] =
{
	0, 0, 1,
	1, 0, 1,
	1, 0.5, 1,
	0, 0.5, 1,
};

const float slabR[12] =
{
	1, 0, 0,
	1, 0.5, 0,
	1, 0.5, 1,
	1, 0, 1,
};

const float slabL[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 0.5, 1,
	0, 0.5, 0,
};

const float ppT[12]{
	0.0625, 0.125, 0.0625,
	0.9375, 0.125, 0.0625,
	0.9375, 0.125, 0.9375,
	0.0625, 0.125, 0.9375,
};

const float ppB[12] =
{
	0.0625, 0, 0.0625,
	0.0625, 0.125, 0.0625,
	0.9375, 0.125, 0.0625,
	0.9375, 0, 0.0625,
};

const float ppF[12] =
{
	0.0625, 0, 0.9375,
	0.9375, 0, 0.9375,
	0.9375, 0.125, 0.9375,
	0.0625, 0.125, 0.9375,
};

const float ppR[12] =
{
	0.9375, 0, 0.0625,
	0.9375, 0.125, 0.0625,
	0.9375, 0.125, 0.9375,
	0.9375, 0, 0.9375,
};

const float ppL[12] =
{

	0.0625, 0, 0.0625,
	0.0625, 0, 0.9375,
	0.0625, 0.125, 0.9375,
	0.0625, 0.125, 0.0625,
};

const float cacT[12]{
	0.0625, 1.0, 0.0625,
	0.9375, 1.0, 0.0625,
	0.9375, 1.0, 0.9375,
	0.0625, 1.0, 0.9375,
};
const float cacB[12]{
	0.0625, 0, 0.0625,
	0.9375, 0, 0.0625,
	0.9375, 0, 0.9375,
	0.0625, 0, 0.9375,
};
const float cacBa[12] =
{
	0.0625, 0, 0.125,
	0.0625, 1, 0.125,
	0.9375, 1, 0.125,
	0.9375, 0, 0.125,
};

const float cacF[12] =
{
	0.0625, 0, 0.875,
	0.9375, 0, 0.875,
	0.9375, 1, 0.875,
	0.0625, 1, 0.875,
};

const float cacR[12] =
{
	0.875, 0, 0.0625,
	0.875, 1, 0.0625,
	0.875, 1, 0.9375,
	0.875, 0, 0.9375,
};

const float cacL[12] =
{

	0.125, 0, 0.0625,
	0.125, 0, 0.9375,
	0.125, 1, 0.9375,
	0.125, 1, 0.0625,
};

const float farmT[12]{
	0, 0.9375, 0,
	1, 0.9375, 0,
	1, 0.9375, 1,
	0, 0.9375, 1,
};

const float farmB[12] =
{
	0, 0, 0,
	0, 0.9375, 0,
	1, 0.9375, 0,
	1, 0, 0,
};

const float farmF[12] =
{
	0, 0, 1,
	1, 0, 1,
	1, 0.9375, 1,
	0, 0.9375, 1,
};

const float farmR[12] =
{
	1, 0, 0,
	1, 0.9375, 0,
	1, 0.9375, 1,
	1, 0, 1,
};

const float farmL[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 0.9375, 1,
	0, 0.9375, 0,
};

const float paneL[12] = 
{
	0.5, 0, 0,
	0.5, 1, 0,
	0.5, 1, 1,
	0.5, 0, 1,
};

const float torT[12]{
	0.4375, 0.625, 0.4375,
	0.5625, 0.625, 0.4375,
	0.5625, 0.625, 0.5625,
	0.4375, 0.625, 0.5625,
};
const float torB[12]{
	0.4375, 0, 0.4375,
	0.5625, 0, 0.4375,
	0.5625, 0, 0.5625,
	0.4375, 0, 0.5625,
};
const float torBa[12] =
{
	0, 0, 0.4375,
	0, 1, 0.4375,
	1, 1, 0.4375,
	1, 0, 0.4375,
};

const float torF[12] =
{
	0, 0, 0.5625,
	1, 0, 0.5625,
	1, 1, 0.5625,
	0, 1, 0.5625,
};

const float torR[12] =
{
	0.5625, 0, 0,
	0.5625, 1, 0,
	0.5625, 1, 1,
	0.5625, 0, 1,
};

const float torL[12] =
{

	0.4375, 0, 0,
	0.4375, 0, 1,
	0.4375, 1, 1,
	0.4375, 1, 0,
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

	glm::vec3 up;
	glm::vec3 down;
	glm::vec3 left;
	glm::vec3 right;
	glm::vec3 front;
	glm::vec3 back;
};

Chunk::Chunk()
{
	struct ChunkBlockExtended c;
	c.ID = 0;
	c.biomeID = 0;
	c.meta = 0;
	chunk_x = 0;
	chunk_y = 0;
	chunk_z = 0;

	#ifndef ME_ENABLED
	for (int x = 0; x < 16; x++) {
		for (int y = 0; y < 16; y++) {
			for (int z = 0; z < 16; z++) {
				blocks[x][y][z] = c;
			}
		}
	}
	sceKernelDcacheWritebackInvalidateAll();
	#endif
	hasMesh = false;
	animPos = -8.0f;
	firstShow = true;
	hasStruct = false;
	m_aabb.extent = glm::vec3(CHUNK_SIZE, CHUNK_SIZE, CHUNK_SIZE);

	delta.clear();
}

Chunk::~Chunk()
{
	save();
	deleteMesh();
}

void Chunk::save(){
	if(delta.size() > 0 ){
		//Write data to save
		std::ofstream file("saves/" +  Terrain::WorldProvider::worldName + "/" + std::to_string(chunk_x) + " " + std::to_string(chunk_y) + " " + std::to_string(chunk_z) + ".chnk");

		for(int i = 0; i < delta.size(); i++){
			file << delta[i].position.x << " " << delta[i].position.y << " " << delta[i].position.z << " "; //Prints position
			file << (int)delta[i].blk.ID << " " << (int)delta[i].blk.meta << std::endl;
		}
	}
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

glm::vec3 getColorOffsets(ChunkBlockExtended cblk, int side){

	glm::vec3 v = Terrain::bioMap[cblk.biomeID].color;

	if(cblk.ID == 2 && side == TYPE_TOP){
		return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
	}

	if(cblk.ID == 31 && (cblk.meta == 1 || cblk.meta == 2)  ){
		return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
	}else if (cblk.ID == 18 || cblk.ID == 161){
		if(cblk.ID == 18){
			if(cblk.meta == 1){
				return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
			}else if(cblk.meta == 2){
				return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
			}else{
				return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
			}
		}else{
			return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
		}
	}else if(cblk.ID == 104 || cblk.ID == 105 || cblk.ID == 106 || cblk.ID == 111){
		return {1.06f * v.x, 1.07f * v.y, 1.06f * v.z};
	}else{
		return {1.0f, 1.0f, 1.0f};
	}
}

void Chunk::generateMesh(ChunkManager* man)
{
	LocalFaces faces;
	numFaces = 0;
	for (char y = 0; y < CHUNK_SIZE; y++) {
		for (char z = 0; z < CHUNK_SIZE; z++) {
			for (char x = 0; x < CHUNK_SIZE; x++) {
				ChunkBlockExtended temp = blocks[x][y][z];
				glm::vec3 position;
				position.x = x; position.y = y; position.z = z;

				if (temp.ID == 0) { //DONT TRY TO GENERATE AIR!
					continue;
				}

				Block* blockData = BlockData::InstancePointer()->block_data[temp];
				//Multi mesh support (similar to gbuffers)

				glm::vec3 cOff = getColorOffsets(temp, 0);

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

				//CROSS PLANE
				if(blockData->renderType == 1){
					mesh->addFace(0, xFace1, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z} , position,cOff);
					mesh->addFace(0, xFace2, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z} , position,cOff);
					continue;
				}

				//CARPET
				if(blockData->renderType == 3){
					std::array<float, 8> coords = getTextureAtlasIndex(blockData->topAtlas);
					
					coords[5] = (coords[5] - coords[1]) / 16.f + coords[1];
					coords[7] = (coords[5] - coords[1]) / 16.f + coords[1];


					tryAddFaceToMesh(carpetL, coords, position, faces.left, TYPE_LEFT, man, cOff);
					tryAddFaceToMesh(carpetR, coords, position, faces.right, TYPE_RIGHT, man, cOff);
					tryAddFaceToMesh(carpetF, coords, position, faces.front, TYPE_FRONT, man, cOff);
					tryAddFaceToMesh(carpetB, coords, position, faces.back, TYPE_BACK, man, cOff);
					mesh->addFace(TYPE_TOP, carpetT, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);

					continue;
				}

				//LADDER
				if(blockData->renderType == 4){
					mesh->addFace(TYPE_LEFT, ladder, getTextureAtlasIndex(blockData->rightAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					continue;
				}

				//PANE

				if(blockData->renderType == 5){
					mesh->addFace(TYPE_RIGHT, paneL, getTextureAtlasIndex(blockData->rightAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					continue;
				}

				if(blockData->renderType == 6){					
					
					std::array<float, 8> coords = getTextureAtlasIndex(blockData->leftAtlas);
					
					coords[5] = (coords[5] - coords[1]) / 2.f + coords[1];
					coords[7] = (coords[7] - coords[3]) / 2.f + coords[1];

					mesh->addFace(TYPE_LEFT, slabL, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					mesh->addFace(TYPE_RIGHT, slabR, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					mesh->addFace(TYPE_FRONT, slabF, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					mesh->addFace(TYPE_BACK, slabB, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					mesh->addFace(TYPE_TOP, slabT, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);

					mesh->addFace(TYPE_BOTTOM, bottomFace, getTextureAtlasIndex(blockData->bottomAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position,cOff);
					continue;
				}

				if(blockData->renderType == 7){					
					
					std::array<float, 8> coords = getTextureAtlasIndex(blockData->leftAtlas);
					
					coords[5] = (coords[5] - coords[1]) / 16.f * 15.f + coords[1];
					coords[7] = (coords[7] - coords[3]) / 16.f * 15.f + coords[1];

					mesh->addFace(TYPE_LEFT, farmL, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_RIGHT, farmR, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_FRONT, farmF, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_BACK, farmB, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_TOP, farmT, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);

					mesh->addFace(TYPE_BOTTOM, bottomFace, getTextureAtlasIndex(blockData->bottomAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					continue;
				}

				if(blockData->renderType == 8){					
					

					mesh->addFace(TYPE_LEFT, wheatL, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_RIGHT, wheatR, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_FRONT, wheatF, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_BACK, wheatB, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					continue;
				}

				if(blockData->renderType == 10){					
					

					mesh->addFace(TYPE_LEFT, cacL, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_RIGHT, cacR, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_FRONT, cacF, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_BACK, cacBa, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_BOTTOM, cacB, getTextureAtlasIndex(blockData->bottomAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_TOP, cacT, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					continue;
				}

				if(blockData->renderType == 11){					
					

					mesh->addFace(TYPE_LEFT, torL, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_RIGHT, torR, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_FRONT, torF, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_BACK, torBa, getTextureAtlasIndex(blockData->leftAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);


					mesh->addFace(TYPE_BOTTOM, torB,getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_TOP, torT, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					continue;
				}

				//Pressure Plate
				if(blockData->renderType == 9){
					std::array<float, 8> coords = getTextureAtlasIndex(blockData->topAtlas);
					
					coords[5] = (coords[5] - coords[1]) / 8.f + coords[1];
					coords[7] = (coords[7] - coords[3]) / 8.f + coords[1];

					mesh->addFace(TYPE_LEFT, ppL, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_RIGHT, ppR, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_FRONT, ppF, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_BACK, ppB, coords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);
					mesh->addFace(TYPE_TOP, ppT, getTextureAtlasIndex(blockData->topAtlas), {(float)chunk_x, (float)chunk_y, (float)chunk_z}, position, cOff);

					continue;
				}

				faces.update(x, y, z);

				cOff = getColorOffsets(temp, 4);
				tryAddFaceToMesh(topFace, getTextureAtlasIndex(blockData->topAtlas), position, faces.up, TYPE_TOP, man, cOff);

				if(temp.ID == 2){
					mesh = &meshes.floraMesh;
					//Left/ Right
					tryAddFaceToMesh(leftFaceOverlay, getTextureAtlasIndex(445), position, faces.left, TYPE_LEFT, man, cOff);
					tryAddFaceToMesh(rightFaceOverlay, getTextureAtlasIndex(445), position, faces.right, TYPE_RIGHT, man, cOff);

					//Front/ Back
					tryAddFaceToMesh(frontFaceOverlay, getTextureAtlasIndex(445), position, faces.front, TYPE_FRONT, man, cOff);
					tryAddFaceToMesh(backFaceOverlay, getTextureAtlasIndex(445), position, faces.back, TYPE_BACK, man, cOff);
					mesh = &meshes.solidMesh;
				}

				cOff = getColorOffsets(temp, 0);
				
				tryAddFaceToMesh(bottomFace, getTextureAtlasIndex(blockData->bottomAtlas), position, faces.down, TYPE_BOTTOM, man, cOff);

				//Left/ Right
				tryAddFaceToMesh(leftFace, getTextureAtlasIndex(blockData->leftAtlas), position, faces.left, TYPE_LEFT, man, cOff);
				tryAddFaceToMesh(rightFace, getTextureAtlasIndex(blockData->rightAtlas), position, faces.right, TYPE_RIGHT, man, cOff);

				//Front/ Back
				tryAddFaceToMesh(frontFace, getTextureAtlasIndex(blockData->frontAtlas), position, faces.front, TYPE_FRONT, man, cOff);
				tryAddFaceToMesh(backFace, getTextureAtlasIndex(blockData->backAtlas), position, faces.back, TYPE_BACK, man, cOff);

			}
		}
	}
	hasMesh = true;
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
	m_aabb.offset = {chunk_x * CHUNK_SIZE, chunk_y * CHUNK_SIZE, chunk_z * CHUNK_SIZE};
	WorldProvider::generate(this);

}
void Chunk::generateStructures(ChunkManager* man){
	if(!hasStruct){
	WorldProvider::generateStructures(this, man);
	hasStruct = true;
	}
}
#include <sys/stat.h>
void Chunk::loadCheck(){

	std::ifstream file("saves/" +  Terrain::WorldProvider::worldName + "/" + std::to_string(chunk_x) + " " + std::to_string(chunk_y) + " " + std::to_string(chunk_z) + ".chnk");

	if(file.is_open()){
		std::string line;
		while(std::getline(file, line)){
			std::stringstream str(line);

			ChunkDataEntry temp = {glm::vec3(0, 0, 0), {0, 0}};

			int ID, meta;
			str >> temp.position.x >> temp.position.y >> temp.position.z >> ID >> meta;

			
			if(temp.position.x >= 0 && temp.position.x < 16 && temp.position.y >= 0 && temp.position.y < 16 && temp.position.z >= 0 && temp.position.z < 16 ){
				blocks[(int)temp.position.x][(int)temp.position.y][(int)temp.position.z].ID = ID;
				blocks[(int)temp.position.x][(int)temp.position.y][(int)temp.position.z].meta = meta;
			}

			delta.push_back(temp);

		}

		file.close();
	}else{
		file.close();
	}
	
}

void Chunk::Draw()
{

	sceGumPushMatrix();
	ScePspFVector3 v = {chunk_x * 16, chunk_y * 16 + animPos, chunk_z * 16};
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
	
	sceGuDisable(GU_ALPHA_TEST);
	sceGuDisable(GU_BLEND);
	sceGuDisable(GU_TEXTURE_2D);
	sceGuDisable(GU_CULL_FACE);


	sceGumPopMatrix();
}

void Chunk::DrawTrans()
{

	sceGumPushMatrix();
	ScePspFVector3 v = {chunk_x * 16, chunk_y * 16 + animPos, chunk_z * 16};
	sceGumTranslate(&v);


	sceGuEnable(GU_TEXTURE_2D);
	sceGuEnable(GU_BLEND);
	sceGuEnable(GU_CULL_FACE);

	sceGuDisable(GU_CULL_FACE);
	sceGuEnable(GU_ALPHA_TEST);
	sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
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
	
	sceGuDisable(GU_ALPHA_TEST);
	sceGuDisable(GU_BLEND);
	sceGuDisable(GU_TEXTURE_2D);
	sceGuDisable(GU_CULL_FACE);


	sceGumPopMatrix();
}

void Chunk::Update(float dt)
{
	if(firstShow && hasMesh){
		animPos += 24 * dt;
		if(animPos > 0){
			animPos = 0;
			firstShow = false;
		}
	}
}


ChunkBlock ChunkManager::getBlock(int x, int y, int z){
	ChunkBlock res = {0, 1};
	if(x >= 0 && y >= 0 && z >= 0){
		if(chunkExists(x/16, y/16, z/16)){
			res = m_chunks[mc::Vector3i(x/16, y/16, z/16)]->blocks[x%16][y%16][z%16];
		}
	}
	return res;
}
void ChunkManager::setBlock(int x, int y, int z, ChunkBlock blk){
	ChunkBlock res = {0, 0};
	if(x > 0 && y > 0 && z > 0){
		if(chunkExists(x/16, y/16, z/16)){
			m_chunks[mc::Vector3i(x/16, y/16, z/16)]->blocks[x%16][y%16][z%16].ID = blk.ID;
			m_chunks[mc::Vector3i(x/16, y/16, z/16)]->blocks[x%16][y%16][z%16].meta = blk.meta;
		}
	}
}

void ChunkManager::loadChunkData3(int x, int y, int z){
	m_chunks[mc::Vector3i(x, y, z)]->loadCheck();
}

void ChunkManager::updateLightingAll(int level, int ll){
	for(const auto& [key, chnk] : m_chunks){
		chnk->updateLighting(level, ll);
	}
}

void Chunk::updateLighting(int level, int ll){
	meshes.solidMesh.updateLighting(level, ll);
	meshes.floraMesh.updateLighting(level, ll);
	meshes.waterMesh.updateLighting(level, ll);
}

void Chunk::tryAddFaceToMesh(const float blockFace[12], std::array<float, 8> texCoords, const glm::vec3& blockPosition, const glm::vec3& blockFacing, int type, ChunkManager* man, glm::vec3 colorOffsets)
{
	
	if ((blockFacing.x >= 0 && blockFacing.x < 16) && (blockFacing.y >= 0 && blockFacing.y < 16) && (blockFacing.z >= 0 && blockFacing.z < 16)) {
		ChunkBlock cblk = blocks[(int)blockFacing.x][(int)blockFacing.y][(int)blockFacing.z];
		Block* blk = BlockData::InstancePointer()->block_data[cblk];

		

		if( blk->transparent || cblk.ID == 0){
			if(mesh == &meshes.waterMesh){
				if(cblk.ID != blocks[(int)blockPosition.x][(int)blockPosition.y][(int)blockPosition.z].ID){
			numFaces++;
			mesh->addFace(type, blockFace, texCoords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, blockPosition, colorOffsets);

				}
			}else{
			numFaces++;
			mesh->addFace(type, blockFace, texCoords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, blockPosition, colorOffsets);

			}
		}

	}
	else { //Default generate

		ChunkBlock cblk = man->getBlock(blockFacing.x + chunk_x * CHUNK_SIZE,blockFacing.y + chunk_y * CHUNK_SIZE, blockFacing.z + chunk_z * CHUNK_SIZE);

		if(cblk.meta == 1){
			cblk.meta = 0;
		}

		Block* blk = BlockData::InstancePointer()->block_data[cblk];

		if( (blk->transparent && cblk.ID != blocks[(int)blockPosition.x][(int)blockPosition.y][(int)blockPosition.z].ID) || cblk.ID == 0){
			numFaces++;
			mesh->addFace(type, blockFace, texCoords, {(float)chunk_x, (float)chunk_y, (float)chunk_z}, blockPosition, colorOffsets);
		}


		}
	}
	
}
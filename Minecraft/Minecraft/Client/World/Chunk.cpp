#include "Chunk.h"
#include <mclib/common/Vector.h>
#include <Shadow/Graphics/RenderManager.h>

namespace Minecraft::Terrain{

const short frontFace[12] =
{
	0, 0, 0,
	0, 1, 0,
	1, 1, 0,
	1, 0, 0,
};

const short backFace[12] =
{
	0, 0, 1,
	1, 0, 1,
	1, 1, 1,
	0, 1, 1,
};

const short leftFace[12] =
{
	1, 0, 0,
	1, 1, 0,
	1, 1, 1,
	1, 0, 1,
};

const short rightFace[12] =
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
		right.x = x + 1; left.y = y; left.z = z;
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
	struct Block c;
	c.id = 0;
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
}

Chunk::~Chunk()
{
}

Block Chunk::getBlockAtTranslatedLocation(unsigned int x, unsigned int y, unsigned int z)
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

void Chunk::generateMesh()
{
	LocalFaces faces;
	numFaces = 0;
	for (char y = 0; y < CHUNK_SIZE; y++) {
		for (char z = 0; z < CHUNK_SIZE; z++) {
			for (char x = 0; x < CHUNK_SIZE; x++) {
				Block temp = blocks[x][y][z];
				mc::Vector3i position;
				position.x = x; position.y = y; position.z = z;

				if (temp.id == 0) { //DONT TRY TO GENERATE AIR!
					continue;
				}

				mesh = &meshes.solidMesh;
				//Block blockData = BlockData::InstancePointer()->blockData[temp.ID];
				/*
				if (blockData.meshType == -1) {
					continue;
				}
				else {
					switch (blockData.meshType) {
					case 0:
						mesh = &meshes.solidMesh;
						break;
					case 1:
						mesh = &meshes.waterMesh;
						break;
					case 2:
						mesh = &meshes.floraMesh;
						break;
					}
				}*/
				//ADDITIONALLY CROSS PLANE BLOCKS LATER

				faces.update(x, y, z);

				tryAddFaceToMesh(bottomFace, getTextureAtlasIndex(3), position, faces.down, TYPE_BOTTOM);
				tryAddFaceToMesh(topFace, getTextureAtlasIndex(3), position, faces.up, TYPE_TOP);

				//Left/ Right
				tryAddFaceToMesh(leftFace, getTextureAtlasIndex(3), position, faces.left, TYPE_LEFT);
				tryAddFaceToMesh(rightFace, getTextureAtlasIndex(3), position, faces.right, TYPE_RIGHT);

				//Front/ Back
				tryAddFaceToMesh(frontFace, getTextureAtlasIndex(3), position, faces.front, TYPE_FRONT);
				tryAddFaceToMesh(backFace, getTextureAtlasIndex(3), position, faces.back, TYPE_BACK);

			}
		}
	}
}

void Chunk::updateMesh()
{
	
}

void Chunk::updateMeshLightingOnly()
{
}

void Chunk::generateData(){
	for(int x = 0; x < CHUNK_SIZE; x++){
		for(int y = 0; y < CHUNK_SIZE; y++){
			for(int z = 0; z < CHUNK_SIZE; z++){
				blocks[x][y][z].id = 1;
				blocks[x][y][z].meta = 0;
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
	
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.topVertexData.size(), 0, meshes.solidMesh.topVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.bottomVertexData.size(), 0, meshes.solidMesh.bottomVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.frontVertexData.size(), 0, meshes.solidMesh.frontVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.backVertexData.size(), 0, meshes.solidMesh.backVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.leftVertexData.size(), 0, meshes.solidMesh.leftVertexData.data());
	sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.rightVertexData.size(), 0, meshes.solidMesh.rightVertexData.data());
	
	sceGuDisable(GU_BLEND);
	sceGuDisable(GU_TEXTURE_2D);
	sceGuDisable(GU_CULL_FACE);


	sceGumPopMatrix();
}

void Chunk::Update()
{
}

void Chunk::tryAddFaceToMesh(const short blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3f& blockFacing, int type)
{

	if ((blockFacing.x >= 0 && blockFacing.x < 16) && (blockFacing.y >= 0 && blockFacing.y < 16) && (blockFacing.z >= 0 && blockFacing.z < 16)) {
		//No out of bound data accessses. If it will be, we will generate the faces by default... Note... change this if we have a world based system.
		Block cblk = blocks[(int)blockFacing.x][(int)blockFacing.y][(int)blockFacing.z];
		//BlockData blk = BlockData::InstancePointer()->blockData[cblk.ID];

		
		numFaces++;
		mesh->addFace(type, blockFace, texCoords, {chunk_x, chunk_y, chunk_z}, blockPosition);
		

	}
	else { //Default generate
		numFaces++;
		mesh->addFace(type, blockFace, texCoords, {chunk_x, chunk_y, chunk_z}, blockPosition);
	}
	
}
}
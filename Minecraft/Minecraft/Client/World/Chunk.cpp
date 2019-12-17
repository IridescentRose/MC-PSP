#include "Chunk.h"
#include "TerrainGenerator.h"
#include <Shadow/Graphics/RenderManager.h>

const short frontFace[12] =
{
	0, 0, 0,
	0, 1, 0,
	1, 0, 0,
	1, 1, 0,
};

const short backFace[12] =
{
	0, 0, 1,
	1, 0, 1,
	0, 1, 1,
	1, 1, 1,
};

const short leftFace[12] =
{
	1, 0, 0,
	1, 1, 0,
	1, 0, 1,
	1, 1, 1,
};

const short rightFace[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 1, 0,
	0, 1, 1,
};

const short topFace[12] =
{
	0, 1, 0,
	0, 1, 1,
	1, 1, 0,
	1, 1, 1
};

const short bottomFace[12] =
{
	0, 0, 0,
	1, 0, 0,
	0, 0, 1,
	1, 0, 1,
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

struct LocalFaces {
	void update(int x, int y, int z)
	{
		up.x = x; up.y = y + 1; up.z = z;
		down.x = x; down.y = y - 1; down.z = z;
		left.x = x - 1; left.y = y; left.z = z;
		right.x = x + 1; left.y = y; left.z = z;
		front.x = x; front.y = y; front.z = z + 1;
		back.x = x; back.y = y; back.z = z - 1;
	}

	mc::Vector3i up;
	mc::Vector3i down;
	mc::Vector3i left;
	mc::Vector3i right;
	mc::Vector3i front;
	mc::Vector3i back;
};


namespace Minecraft::Terrain {
	Chunk::Chunk()
	{
		data = 0;
		mesh = 0;
	}

	Chunk::~Chunk()
	{
	}

	void Chunk::generateData(int relX, int relY, int relZ)
	{
		data = SimpleGenerator::generateTerrain(relX, relY, relZ);
	}


	void Chunk::generateMesh()
	{

		LocalFaces faces = LocalFaces();
		
		//Gen Mesh
		for (short y = 0; y < 16; y++) {
			for (short z = 0; z < 16; z++) {
				for (short x = 0; x < 16; x++) {
					
					BlockData* temp = data->getBlock(x, y, z);
					mc::Vector3i position = { x, y, z };

					if (temp->id == 0) { //DONT TRY TO GENERATE AIR!
						continue;
					}

					//TODO: MULTI MESH
					mesh = &meshes.solidMesh;
					//ADDITIONALLY CROSS PLANE BLOCKS LATER

					faces.update(x, y, z);

					tryAddFaceToMesh(bottomFace, { 0 , 0, 0 , 8, 8 , 8 , 8 , 0 }, position, faces.down, TYPE_BOTTOM);
					tryAddFaceToMesh(topFace, { 0 , 0, 0 ,8, 8 , 8 , 8 , 0 }, position, faces.up, TYPE_TOP);

					//Left/ Right
					tryAddFaceToMesh(leftFace, { 0 , 0, 0 ,8, 8 , 8 , 8 , 0 }, position, faces.left, TYPE_LEFT);
					tryAddFaceToMesh(rightFace, { 0 , 0, 0 ,8, 8 , 8 , 8 , 0 }, position, faces.right, TYPE_RIGHT);

					//Front/ Back
					tryAddFaceToMesh(frontFace, { 0 , 0, 0 ,8, 8 , 8 , 8 , 0 }, position, faces.front, TYPE_FRONT);
					tryAddFaceToMesh(backFace, { 0 , 0, 0 ,8, 8 , 8 , 8 , 0 }, position, faces.back, TYPE_BACK);
				}
			}
		}
	}


	void Chunk::tryAddFaceToMesh(const short blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3i& blockFacing, int type)
	{
		//Attempt Mesh Addition
		if ((blockFacing.x >= 0 && blockFacing.x < 16) && (blockFacing.y >= 0 && blockFacing.y < 16) && (blockFacing.z >= 0 && blockFacing.z < 16)) {
			//No out of bound data accessses. If it will be, we will generate the faces by default... Note... change this if we have a world based system.
			BlockData* cblk = data->getBlock(blockFacing.x, blockFacing.y, blockFacing.z);
			
			//TODO: Handle transparent blocks

			mesh->addFace(type, blockFace, texCoords, { data->getRelativeX(), 0, data->getRelativeZ() }, blockPosition);

		}
		else { //Default generate
			mesh->addFace(type, blockFace, texCoords, { data->getRelativeX(), 0, data->getRelativeZ() }, blockPosition);
		}
	}

	void Chunk::Update()
	{
		//Data Update
		//Mesh Update
	}

	void Chunk::Draw()
	{
		//Mesh Draw
		//sceGuEnable(GU_TEXTURE_2D);
		sceGuColor(0xFFFFFFFF);

		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.topVertexData.size(), 0, meshes.solidMesh.topVertexData.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.bottomVertexData.size(), 0, meshes.solidMesh.bottomVertexData.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.leftVertexData.size(), 0, meshes.solidMesh.leftVertexData.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.rightVertexData.size(), 0, meshes.solidMesh.rightVertexData.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.frontVertexData.size(), 0, meshes.solidMesh.frontVertexData.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.backVertexData.size(), 0, meshes.solidMesh.backVertexData.data());

		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.topVertexData2.size(), 0, meshes.solidMesh.topVertexData2.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.bottomVertexData2.size(), 0, meshes.solidMesh.bottomVertexData2.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.leftVertexData2.size(), 0, meshes.solidMesh.leftVertexData2.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.rightVertexData2.size(), 0, meshes.solidMesh.rightVertexData2.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.frontVertexData2.size(), 0, meshes.solidMesh.frontVertexData2.data());
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_8BIT | GU_VERTEX_16BIT | GU_TRANSFORM_3D, meshes.solidMesh.backVertexData2.size(), 0, meshes.solidMesh.backVertexData2.data());
		//sceGuDisable(GU_TEXTURE_2D);
	}
}
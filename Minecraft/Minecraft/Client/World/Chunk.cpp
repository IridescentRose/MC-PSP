#include "Chunk.h"
#include "TerrainGenerator.h"
#include <Shadow/Graphics/RenderManager.h>

const float frontFace[12] =
{
	0, 0, 0,
	0, 1, 0,
	1, 0, 0,
	1, 1, 0,
};

const float backFace[12] =
{
	0, 0, 1,
	1, 0, 1,
	0, 1, 1,
	1, 1, 1,
};

const float leftFace[12] =
{
	1.001, 0, 0,
	1.001, 1, 0,
	1.001, 0, 1,
	1.001, 1, 1,
};

const float rightFace[12] =
{

	0, 0, 0,
	0, 0, 1,
	0, 1, 0,
	0, 1, 1,
};

const float topFace[12] =
{
	0, 1, 0,
	0, 1, 1,
	1, 1, 0,
	1, 1, 1
};

const float bottomFace[12] =
{
	0, 0, 0,
	1, 0, 0,
	0, 0, 1,
	1, 0, 1,
};



const float crossPlane1[12] =
{
	0, 0, 0,
	1, 0, 1,
	1, 1, 1,
	0, 1, 0,
};

const float crossPlane2[12] =
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

	void Chunk::generateData(int relX, int relZ)
	{
		data = SimpleGenerator::generateTerrain(relX, relZ);
	}


	void Chunk::generateMesh()
	{

		LocalFaces faces = LocalFaces();
		
		//Gen Mesh
		for (short y = 0; y < 256; y++) {
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

					tryAddFaceToMesh(bottomFace, { 0 , 0, 0 ,1.f / 24.0f, 1.f / 24.0f , 1.f / 24.0f , 1.f / 24.0f , 0 }, position, faces.down, 0);
					tryAddFaceToMesh(topFace, { 0 , 0, 0 ,1.f / 24.0f, 1.f / 24.0f , 1.f / 24.0f , 1.f / 24.0f , 0 }, position, faces.up, 0);

					//Left/ Right
					tryAddFaceToMesh(leftFace, { 0 , 0, 0 ,1.f / 24.0f, 1.f / 24.0f , 1.f / 24.0f , 1.f / 24.0f , 0 }, position, faces.left, 0);
					tryAddFaceToMesh(rightFace, { 0 , 0, 0 ,1.f / 24.0f, 1.f / 24.0f , 1.f / 24.0f , 1.f / 24.0f , 0 }, position, faces.right, 1);

					//Front/ Back
					tryAddFaceToMesh(frontFace, { 0 , 0, 0 ,1.f / 24.0f, 1.f / 24.0f , 1.f / 24.0f , 1.f / 24.0f , 0 }, position, faces.front, 0);
					tryAddFaceToMesh(backFace, { 0 , 0, 0 ,1.f / 24.0f, 1.f / 24.0f , 1.f / 24.0f , 1.f / 24.0f , 0 }, position, faces.back, 1);

					
				}
			}
		}
	}


	void Chunk::tryAddFaceToMesh(const float blockFace[12], std::array<float, 8> texCoords, const mc::Vector3i& blockPosition, const mc::Vector3i& blockFacing, int type)
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
		sceGuEnable(GU_TEXTURE_2D);
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, meshes.solidMesh.faces * 6, 0, meshes.solidMesh.verticeData.data());
		sceGuDisable(GU_TEXTURE_2D);
	}
}
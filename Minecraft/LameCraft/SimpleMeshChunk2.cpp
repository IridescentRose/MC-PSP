#include "SimpleMeshChunk2.h"
#include <Aurora/Graphics/RenderManager.h>

template <typename T>
void FreeAll( T & t ) {
	T tmp;
	t.swap( tmp );
}


SimpleMeshChunk::SimpleMeshChunk()
{
	trienglesCount = 0;
	fTrienglesCount = 0;
	created = true;
	needUpdate = false;
	periodicallyUpadted = false;

	inFrustum = false;
	t = Timer();
	elapsed = 0;

	meshVertices = NULL;
	floraVertices = NULL;
}

SimpleMeshChunk::SimpleMeshChunk(int _chunkSize)
{
	trienglesCount = 0;
	fTrienglesCount = 0;
	created = true;
	needUpdate = false;
	periodicallyUpadted = false;

	inFrustum = false;
	t = Timer();
	elapsed = 0;

	meshVertices = NULL;
	floraVertices = NULL;
}

SimpleMeshChunk::~SimpleMeshChunk()
{
	if(trienglesCount > 0)
	{
		free(meshVertices);
	}

	if (fTrienglesCount > 0)
	{
		free(floraVertices);
	}
}


void SimpleMeshChunk::vert(float x,float y,float z,float u,float v,float r,float g,float b, block_t id)
{
    CraftPSPVertex vertex;

	vertex.u = u;
	vertex.v = v;
	vertex.color = GU_COLOR(r,g,b,1);
	vertex.x = x;
	vertex.y = y;
	vertex.z = z;

	mVertices.push_back(vertex);
	blockIDs.push_back(id);
}

void SimpleMeshChunk::position(float x,float y,float z, block_t id)
{
	CraftPSPVertex vertex;

	vertex.x = x;
	vertex.y = y;
	vertex.z = z;

	mVertices.push_back(vertex);
	blockIDs.push_back(id);
}

void SimpleMeshChunk::textureCoord(float u,float v)
{
	mVertices[mVertices.size()-1].u = u;
	mVertices[mVertices.size()-1].v = v;
}

void SimpleMeshChunk::colour(float x,float y,float z)
{
	mVertices[mVertices.size()-1].color = GU_COLOR(x,y,z,1);
}

void SimpleMeshChunk::triangle(int x,int y,int z)
{
    Vector3 triangle;
    triangle.x = x;
    triangle.y = y;
    triangle.z = z;

	mTriangle.push_back(triangle);
}

void SimpleMeshChunk::end()
{
	if(mTriangle.size() > 0)
	{
		//Now we need the # of vertices for flora
		int mVertCount = 0;
		int fVertCount = 0;
		for (int i = 0; i < mTriangle.size() * 3; i++) {
			//FOR NOW
			if (blockIDs[i] == LeavesBlock::getID() || blockIDs[i] == SpruceLeaves::getID() || blockIDs[i] == BirchLeaves::getID()) {
				fVertCount++;
			}
			else {
				mVertCount++;
			}
		}

		//optimize here
		meshVertices = (CraftPSPVertex*)memalign(16,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
		//floraVertices = (CraftPSPVertex*)memalign(16, (fVertCount) * sizeof(CraftPSPVertex));

		//vertices
		int vert = 0;
		//int fVert = 0;

		unsigned int size0 =  mTriangle.size();
		for(unsigned int i = 0;i < size0;i++)
		{
				meshVertices[vert].u = mVertices[mTriangle[i].x].u;
				meshVertices[vert].v = mVertices[mTriangle[i].x].v;
				meshVertices[vert].color = mVertices[mTriangle[i].x].color;
				meshVertices[vert].x = mVertices[mTriangle[i].x].x;
				meshVertices[vert].y = mVertices[mTriangle[i].x].y;
				meshVertices[vert].z = mVertices[mTriangle[i].x].z;
				vert++;

				meshVertices[vert].u = mVertices[mTriangle[i].y].u;
				meshVertices[vert].v = mVertices[mTriangle[i].y].v;
				meshVertices[vert].color = mVertices[mTriangle[i].y].color;
				meshVertices[vert].x = mVertices[mTriangle[i].y].x;
				meshVertices[vert].y = mVertices[mTriangle[i].y].y;
				meshVertices[vert].z = mVertices[mTriangle[i].y].z;
				vert++;

				meshVertices[vert].u = mVertices[mTriangle[i].z].u;
				meshVertices[vert].v = mVertices[mTriangle[i].z].v;
				meshVertices[vert].color = mVertices[mTriangle[i].z].color;
				meshVertices[vert].x = mVertices[mTriangle[i].z].x;
				meshVertices[vert].y = mVertices[mTriangle[i].z].y;
				meshVertices[vert].z = mVertices[mTriangle[i].z].z;
				vert++;
		}

		//clear the cache or there will be some errors
		sceKernelDcacheWritebackInvalidateRange(meshVertices,( mTriangle.size() * 3) * sizeof(CraftPSPVertex));
		//sceKernelDcacheWritebackInvalidateRange(floraVertices, (fVertCount) * sizeof(CraftPSPVertex));
		//sceKernelDcacheWritebackInvalidateAll();


		trienglesCount = size0 * 3;

		//clean buffers
		FreeAll(mVertices);
		FreeAll(mTriangle);
	}else
	{
		trienglesCount = 0;
		fTrienglesCount = 0;
	}

	created = true;
	needUpdate = false;
}

unsigned int FastDistance2d(unsigned int dx, unsigned int dy)
{
	unsigned int w;
	if (dy < dx) {
		w = dy >> 2;
		return (dx + w + (w >> 1));
	}
	else {
		w = dx >> 2;
		return (dy + w + (w >> 1));
	}
}

void SimpleMeshChunk::drawChunk(Vector3 camPos, bool transparent)
{
	if(trienglesCount > 0 && meshVertices != NULL)
    {
		if (!transparent) {
			sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, trienglesCount, 0, meshVertices);
		}
		else {
			if (FastDistance2d(abs(chunkStartX + 7 - camPos.x), abs(chunkStartZ + 7 - camPos.z) + abs(chunkStartY + 7 - camPos.y) * 0.85f) < 16) {
				sceGumMatrixMode(GU_MODEL);
				elapsed += t.GetDeltaTime();

				for (int i = 0; i < trienglesCount; i++) {
					//PER VERTEX;
					float sinX = vfpu_sinf(elapsed*1.2f + meshVertices[i].x + meshVertices[i].y)/2.23f;
					float sinZ = vfpu_cosf(elapsed*0.8f + meshVertices[i].z + meshVertices[i].y)/2.34f;

					oldXZ.push_back(meshVertices[i].x);
					oldXZ.push_back(meshVertices[i].z);

					meshVertices[i].x += sinX*sinX*sinX;
					meshVertices[i].z += sinZ*sinZ*sinZ;
				}

				sceKernelDcacheWritebackInvalidateRange(meshVertices, (trienglesCount) * sizeof(CraftPSPVertex));
				sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, trienglesCount, 0, meshVertices);
				

				/*
				sceGumPushMatrix();
				float sin = vfpu_sinf(elapsed / 1.4f) / 6.28f;
				float cos = vfpu_cosf(elapsed / 0.9f) / 6.21f;


				ScePspFVector3 vec = { (20 * sin * sin * sin * sin * sin + 10 * cos * cos) , (10 * sin * cos * sin + 5 * cos * sin * cos), (16 * cos * cos * cos + 8 * sin * sin) };
				sceGumTranslate(&vec);

				sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, trienglesCount, 0, meshVertices);
				sceGumPopMatrix();*/
			}
			else {
				sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, trienglesCount, 0, meshVertices);
			}
		}


		/*
		if (FastDistance2d( abs(chunkStartX + 7 - camPos.x), abs(chunkStartZ + 7 - camPos.z) + abs(chunkStartY + 7 - camPos.y)*0.85f) < 24) {
			sceGumMatrixMode(GU_MODEL);
			elapsed += t.GetDeltaTime();
			sceGumPushMatrix();
			float sin = vfpu_sinf(elapsed / 1.4f) / 6.28f;
			float cos = vfpu_cosf(elapsed / 0.9f) / 6.21f;


			ScePspFVector3 vec = { (20 * sin * sin * sin * sin * sin + 10 * cos * cos) , (10 * sin * cos * sin + 5 * cos * sin * cos), (16 * cos * cos * cos + 8 * sin * sin) };
			sceGumTranslate(&vec);

			//sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, trienglesCount, 0, meshVertices);
			//sceGumPopMatrix();
		}
		else {
			//sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_COLOR_8888 | GU_VERTEX_32BITF | GU_TRANSFORM_3D, trienglesCount, 0, meshVertices);
		}
		*/
    }
}

void SimpleMeshChunk::endDrawChunk() {
	if (oldXZ.size() > 0) {
		for (int i = 0; i < trienglesCount; i++) {
			meshVertices[i].x = oldXZ[i * 2];
			meshVertices[i].z = oldXZ[i * 2 + 1];
		}
		oldXZ.clear();
	}

	sceKernelDcacheWritebackInvalidateRange(meshVertices, (trienglesCount) * sizeof(CraftPSPVertex));
}

void SimpleMeshChunk::reset()
{
	if(trienglesCount > 0 && meshVertices != NULL)
	{
		free(meshVertices);
		trienglesCount = 0;
	}
	created = false;
}

#include "ChunkMesh.h"
#include <Shadow/Utils/Logger.h>
#include <sstream>
#include "World.h"


using namespace Shadow::Utils;

#define CHUNK_SIZE 16


	int lighting(float time){
		float res = 0.25f;

		if (time < 2000) { //6am - 9am sun gets brighter
			res = 0.625f + time / 2000.f * 0.375f;
		}
		if (time >= 2000 && time < 10000) { //9am - 3pm sun is brightest
			res = 0.98f;
		}
		if (time >= 10000 && time < 14000) { //3pm - 6pm sun gets dimmer
			res = 1.0f - (time - 10000.f) / 4000.f * 0.75f;
		}
		if (time >= 14000 && time < 22000) {//9pm - 3am is night
			res = 0.25f;
		}
		if (time >= 22000 && time < 24000) {
			res = (time - 22000.f) / 2000.f * 0.375f + 0.25f;
		}

		float fp = res * 16; //15 max, 0 min, 4 at night time

		return (int)fp;
	}

namespace Minecraft::Terrain {
#include "ChunkMesh.h"

	ChunkMesh::ChunkMesh()
	{
		faces = 0;
		frontVertexData.clear();
		backVertexData.clear();
		leftVertexData.clear();
		rightVertexData.clear();
		topVertexData.clear();
		bottomVertexData.clear();
	}

	void ChunkMesh::clear(){
		faces = 0;
		frontVertexData.clear();
		backVertexData.clear();
		leftVertexData.clear();
		rightVertexData.clear();
		topVertexData.clear();
		bottomVertexData.clear();
	}

	ChunkMesh::~ChunkMesh()
	{ 
	}



	void ChunkMesh::updateLighting(int level){

		float light = (float) level / 16.0f;

		for(ChunkVertex16& v : frontVertexData){
			v.color = GU_COLOR(light, light, light, 1.0f);
		}
		for(ChunkVertex16& v : backVertexData){
			v.color = GU_COLOR(light, light, light, 1.0f);
		}
		for(ChunkVertex16& v : rightVertexData){
			v.color = GU_COLOR(light, light, light, 1.0f);
		}
		for(ChunkVertex16& v : leftVertexData){
			v.color = GU_COLOR(light, light, light, 1.0f);
		}
		for(ChunkVertex16& v : topVertexData){
			v.color = GU_COLOR(light, light, light, 1.0f);
		}
		for(ChunkVertex16& v : bottomVertexData){
			v.color = GU_COLOR(light, light, light, 1.0f);
		}
	}

	void ChunkMesh::addFace(int faceType, const float blockFace[12], std::array<float, 8> texCoords, mc::Vector3i chunkPosition, mc::Vector3i blockPosition)
	{
		ChunkVertex16 v1, v2, v3, v4, v5, v6;

		int l = lighting(Client::g_World->timeData->time % 24000);
		float light = (float) l / 16.0f;

		if(faceType != TYPE_BACK && faceType != TYPE_RIGHT){
			v1 = {texCoords[0], texCoords[1], GU_COLOR(light, light, light, 1.0f), blockFace[0 * 3 + 0] + blockPosition.x, blockFace[0 * 3 + 1] + blockPosition.y, blockFace[0 * 3 + 2] + blockPosition.z};
			v2 = {texCoords[2], texCoords[3], GU_COLOR(light, light, light, 1.0f), blockFace[1 * 3 + 0] + blockPosition.x, blockFace[1 * 3 + 1] + blockPosition.y, blockFace[1 * 3 + 2] + blockPosition.z};
			v3 = {texCoords[4], texCoords[5], GU_COLOR(light, light, light, 1.0f), blockFace[2 * 3 + 0] + blockPosition.x, blockFace[2 * 3 + 1] + blockPosition.y, blockFace[2 * 3 + 2] + blockPosition.z};
			v4 = {texCoords[4], texCoords[5], GU_COLOR(light, light, light, 1.0f), blockFace[2 * 3 + 0] + blockPosition.x, blockFace[2 * 3 + 1] + blockPosition.y, blockFace[2 * 3 + 2] + blockPosition.z};
			v5 = {texCoords[6], texCoords[7], GU_COLOR(light, light, light, 1.0f), blockFace[3 * 3 + 0] + blockPosition.x, blockFace[3 * 3 + 1] + blockPosition.y, blockFace[3 * 3 + 2] + blockPosition.z};
			v6 = {texCoords[0], texCoords[1], GU_COLOR(light, light, light, 1.0f), blockFace[0 * 3 + 0] + blockPosition.x, blockFace[0 * 3 + 1] + blockPosition.y, blockFace[0 * 3 + 2] + blockPosition.z};}else{
			v1 = {texCoords[2], texCoords[3], GU_COLOR(light, light, light, 1.0f), blockFace[0 * 3 + 0] + blockPosition.x, blockFace[0 * 3 + 1] + blockPosition.y, blockFace[0 * 3 + 2] + blockPosition.z};
			v2 = {texCoords[4], texCoords[5], GU_COLOR(light, light, light, 1.0f), blockFace[1 * 3 + 0] + blockPosition.x, blockFace[1 * 3 + 1] + blockPosition.y, blockFace[1 * 3 + 2] + blockPosition.z};
			v3 = {texCoords[6], texCoords[7], GU_COLOR(light, light, light, 1.0f), blockFace[2 * 3 + 0] + blockPosition.x, blockFace[2 * 3 + 1] + blockPosition.y, blockFace[2 * 3 + 2] + blockPosition.z};
			v4 = {texCoords[6], texCoords[7], GU_COLOR(light, light, light, 1.0f), blockFace[2 * 3 + 0] + blockPosition.x, blockFace[2 * 3 + 1] + blockPosition.y, blockFace[2 * 3 + 2] + blockPosition.z};
			v5 = {texCoords[0], texCoords[1], GU_COLOR(light, light, light, 1.0f), blockFace[3 * 3 + 0] + blockPosition.x, blockFace[3 * 3 + 1] + blockPosition.y, blockFace[3 * 3 + 2] + blockPosition.z};
			v6 = {texCoords[2], texCoords[3], GU_COLOR(light, light, light, 1.0f), blockFace[0 * 3 + 0] + blockPosition.x, blockFace[0 * 3 + 1] + blockPosition.y, blockFace[0 * 3 + 2] + blockPosition.z};
		}


		switch(faceType){
			case TYPE_TOP:{
				topVertexData.push_back(v1);
				topVertexData.push_back(v2);
				topVertexData.push_back(v3);
				topVertexData.push_back(v4);
				topVertexData.push_back(v5);
				topVertexData.push_back(v6);
				break;
			}

			case TYPE_BOTTOM:{
				bottomVertexData.push_back(v1);
				bottomVertexData.push_back(v2);
				bottomVertexData.push_back(v3);
				bottomVertexData.push_back(v4);
				bottomVertexData.push_back(v5);
				bottomVertexData.push_back(v6);
				break;
			}

			case TYPE_FRONT:{
				frontVertexData.push_back(v1);
				frontVertexData.push_back(v2);
				frontVertexData.push_back(v3);
				frontVertexData.push_back(v4);
				frontVertexData.push_back(v5);
				frontVertexData.push_back(v6);
				break;
			}


			case TYPE_BACK:{
				backVertexData.push_back(v1);
				backVertexData.push_back(v2);
				backVertexData.push_back(v3);
				backVertexData.push_back(v4);
				backVertexData.push_back(v5);
				backVertexData.push_back(v6);
				break;
			}

			case TYPE_LEFT:{
				leftVertexData.push_back(v1);
				leftVertexData.push_back(v2);
				leftVertexData.push_back(v3);
				leftVertexData.push_back(v4);
				leftVertexData.push_back(v5);
				leftVertexData.push_back(v6);
				break;
			}

			case TYPE_RIGHT:{
				rightVertexData.push_back(v1);
				rightVertexData.push_back(v2);
				rightVertexData.push_back(v3);
				rightVertexData.push_back(v4);
				rightVertexData.push_back(v5);
				rightVertexData.push_back(v6);
				break;
			}
		}
		
	}
}
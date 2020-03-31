#include "Clouds.h"
#include "../../Common/Options.hpp"
#include <glm/glm.hpp>
#include <stdlib.h>

namespace Minecraft::Rendering {
	Clouds::Clouds()
	{
		tex = TextureUtil::LoadPng("assets/minecraft/textures/environment/clouds.png");
		Update();
		count = 0;
	}
	Clouds::~Clouds()
	{
		free(cloudVerts);
		delete tex;
	}

	void Clouds::Update()
	{
		std::vector<glm::vec3*> mPosition;
		std::vector<glm::vec2*> mtextures;
		std::vector<glm::vec3*> mTriangle;

		int iVertex = 0;
		int points = 0;

		float x = 0;
		float y = 0;
		float z = 0;

		iVertex = 0;
		points = 0;

		for (float l = 1; l <= 10; l += 1)
		{
			for (float j = 1; j <= 10; j += 1)//0-|-
			{
				mPosition.push_back(new glm::vec3(x + ((l - 1) * 48), y, z + ((j - 1) * 48)));
				mtextures.push_back(new glm::vec2(0 + (l - 1) / 40, 0 + (j - 1) / 10));
				mPosition.push_back(new glm::vec3(x + (l * 48), y, z + ((j - 1) * 48)));
				mtextures.push_back(new glm::vec2(l / 40, 0 + (j - 1) / 10));
				mPosition.push_back(new glm::vec3(x + (l * 48), y, z + (j * 48)));
				mtextures.push_back(new glm::vec2(l / 40, j / 10));
				mPosition.push_back(new glm::vec3(x + ((l - 1) * 48), y, z + (j * 48)));
				mtextures.push_back(new glm::vec2(0 + (l - 1) / 40, j / 10));

				mTriangle.push_back(new glm::vec3(iVertex, iVertex + 1, iVertex + 2));
				mTriangle.push_back(new glm::vec3(iVertex + 2, iVertex + 3, iVertex));

				iVertex += 4;
				points += 6;
			}
		}

		cloudVerts = (TextureVertex*)memalign(16, (mTriangle.size() * 3) * sizeof(TextureVertex));
		count = points;
		
		//build verts
		//vertices
		int vert = 0;
		unsigned int size = mTriangle.size();
		for (unsigned int j = 0; j < size; j++)
		{
			cloudVerts[vert].u = mtextures[mTriangle[j]->x]->x;
			cloudVerts[vert].v = mtextures[mTriangle[j]->x]->y;
			cloudVerts[vert].x = mPosition[mTriangle[j]->x]->x;
			cloudVerts[vert].y = mPosition[mTriangle[j]->x]->y;
			cloudVerts[vert].z = mPosition[mTriangle[j]->x]->z;
			vert++;

			cloudVerts[vert].u = mtextures[mTriangle[j]->y]->x;
			cloudVerts[vert].v = mtextures[mTriangle[j]->y]->y;
			cloudVerts[vert].x = mPosition[mTriangle[j]->y]->x;
			cloudVerts[vert].y = mPosition[mTriangle[j]->y]->y;
			cloudVerts[vert].z = mPosition[mTriangle[j]->y]->z;
			vert++;

			cloudVerts[vert].u = mtextures[mTriangle[j]->z]->x;
			cloudVerts[vert].v = mtextures[mTriangle[j]->z]->y;
			cloudVerts[vert].x = mPosition[mTriangle[j]->z]->x;
			cloudVerts[vert].y = mPosition[mTriangle[j]->z]->y;
			cloudVerts[vert].z = mPosition[mTriangle[j]->z]->z;
			vert++;
		}

		//clear the cache or there will be some errors
		sceKernelDcacheWritebackInvalidateRange(cloudVerts, (mTriangle.size() * 3) * sizeof(TextureVertex));
		//sceKernelDcacheWritebackInvalidateAll();

		for (unsigned int aa = 0; aa < mPosition.size(); aa++)
		{
			delete mPosition[aa];
			delete mtextures[aa];
		}
		mPosition.clear();
		mtextures.clear();

		for (unsigned int aa = 0; aa < mTriangle.size(); aa++)
		{
			delete 	mTriangle[aa];
		}
		mTriangle.clear();

	}

	void Clouds::Draw(glm::vec3 pos, s64 dt)
	{
		sceGuEnable(GU_TEXTURE_2D);
		sceGuEnable(GU_BLEND);
		sceGuFrontFace(GU_CW);
		sceGuDisable(GU_DEPTH_TEST);		
		
		tex->bindTexture(0, 0, true);

		float alpha = 0.7f;

		if (dt < 2000) { //6am - 9am sun gets brighter
			alpha = 0.5f + 0.2f * ((float)dt / 2000.f);
		}
		if (dt >= 2000 && dt < 10000) { //9am - 3pm sun is brightest
			alpha = 0.7f;
		}
		if (dt >= 10000 && dt < 12000) { //3pm - 6pm sun gets dimmer
			alpha = 0.7f - 0.2f * (((float)dt - 10000.f) / 2000.f);
		}
		if (dt >= 12000 && dt < 14000) { //6pm - 9pm sun light fades
			alpha = 0.5f - 0.2f * (((float)dt - 12000.f) / 2000.f);
		}
		if (dt >= 14000 && dt < 22000) {//9pm - 3am is night
			alpha = 0.3f;
		}
		if (dt >= 22000 && dt < 24000) {
			alpha = 0.3f + 0.2f * (((float)dt - 22000) / 2000);
		}

		ScePspFVector3 v = { -256.0f - pos.x , 128.0f , -256.0f - pos.z};
		sceGumPushMatrix();
		sceGumTranslate(&v);

		sceGuColor(GU_COLOR(1.0f, 1.0f, 1.0f, alpha * 0.25f));
		sceGuTexScale(1.0f, 0.25f);
		sceGuTexOffset( (float)((int)dt % 9600) / 9600.0f, 0.0f);
		sceGuDisable(GU_CULL_FACE);

		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, 600, 0, cloudVerts);
		sceGuFrontFace(GU_CCW);
		sceGumDrawArray(GU_TRIANGLES, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, 600, 0, cloudVerts);

		sceGuTexScale(1.0f, 1.0f);
		sceGuTexOffset(0.0f, 0.0f);
		sceGumPopMatrix();

		sceGuColor(GU_COLOR(1.0f, 1.0f, 1.0f, 1.0f));
		sceGuDisable(GU_TEXTURE_2D);
		sceGuDisable(GU_BLEND);
		sceGuEnable(GU_DEPTH_TEST);
	}
}
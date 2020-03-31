#include "Moon.h"
#include <pspmath.h>
#define PI 3.14159

namespace Minecraft::Rendering {
	Moon::Moon()
	{
		skyVertices = (TextureVertex*)memalign(16, 4 * sizeof(TextureVertex));
		tex = TextureUtil::LoadPng("assets/minecraft/textures/environment/moon_phases.png");
	}
	Moon::~Moon()
	{
		free(skyVertices);
		delete tex;
	}


	void Moon::Update(float moon_angle, s64 worldAge)
	{
		moon_angle += 120.0f + 180.0f;
		float r = 670.0f;
		float shift = 325;
		//float textureScale = 1.0f / stepScale;

		int phaseX = (worldAge / 24000) % 4;
		int phaseY = (worldAge / (24000 * 4)) % 2;

		int i = 0;

		skyVertices[i].x = vfpu_sinf((moon_angle / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf(((moon_angle) / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = -250 * 0.9f;// * stepScale;
		skyVertices[i].u = 0.25f * phaseX;// * textureScale;
		skyVertices[i].v = 0.5f * phaseY;// * textureScale;
		i++;

		// (x, y - 1, z)
		skyVertices[i].x = vfpu_sinf(((moon_angle - 45 * 0.9f) / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf(((moon_angle - 45 * 0.9f) / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = -250 * 0.9f;// * stepScale;
		skyVertices[i].u = 0.25f * phaseX;// * textureScale;
		skyVertices[i].v = 0.5f + phaseY*0.5f;// * textureScale;
		i++;

		// (x + 1, y, z)
		skyVertices[i].x = vfpu_sinf((moon_angle / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf((moon_angle / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = 250 * 0.9f;// * stepScale;
		skyVertices[i].u = 0.25f + phaseX * 0.25f;// * textureScale;
		skyVertices[i].v = 0.5f * phaseY;// * textureScale;
		i++;

		// (x + 1, y - 1, z)
		skyVertices[i].x = vfpu_sinf(((moon_angle - 45 * 0.9f) / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf(((moon_angle - 45 * 0.9f) / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = 250 * 0.9f;// * stepScale;
		skyVertices[i].u = 0.25f + phaseX*0.25f;// * textureScale;
		skyVertices[i].v = 0.5f + phaseY * 0.5f;// * textureScale;

		sceKernelDcacheWritebackInvalidateRange(skyVertices, 4 * sizeof(TextureVertex));
	}

	void Moon::Draw()
	{
		sceGuEnable(GU_TEXTURE_2D);
		sceGuEnable(GU_BLEND);
		sceGuDisable(GU_CULL_FACE);
		sceGuDisable(GU_DEPTH_TEST);
		tex->bindTexture();

		sceGuBlendFunc(GU_ADD, GU_FIX, GU_FIX, 0xFFFFFFFF, 0xFFFFFFFF);
		sceGumDrawArray(GU_TRIANGLE_STRIP, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, 4, 0, skyVertices);

		sceGuDisable(GU_TEXTURE_2D);
		sceGuDisable(GU_BLEND);
		sceGuEnable(GU_DEPTH_TEST);
		sceGuEnable(GU_CULL_FACE);

		//make default blend function
		sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
	}
}
#include "Sun.h"
#include <pspmath.h>
#define PI 3.14159

namespace Minecraft::Rendering {
	Sun::Sun()
	{
		skyVertices = (TextureVertex*)memalign(16, 4 * sizeof(TextureVertex));
		tex = TextureUtil::LoadPng("assets/minecraft/textures/environment/sun.png");

		Update(0.0f);
	}
	Sun::~Sun()
	{
		free(skyVertices);
		delete tex;
	}


	void Sun::Update(float sun_angle)
	{
		sun_angle += 120.0f;
		float r = 670.0f;
		float shift = 325;
		//float textureScale = 1.0f / stepScale;

		int i = 0;

		skyVertices[i].x = vfpu_sinf((sun_angle / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf(((sun_angle) / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = -250 * 0.9f;// * stepScale;
		skyVertices[i].u = 0.f;// * textureScale;
		skyVertices[i].v = 0.f;// * textureScale;
		i++;

		// (x, y - 1, z)
		skyVertices[i].x = vfpu_sinf(((sun_angle - 45 * 0.9f) / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf(((sun_angle - 45 * 0.9f) / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = -250 * 0.9f;// * stepScale;
		skyVertices[i].u = 0.f;// * textureScale;
		skyVertices[i].v = 1.f;// * textureScale;
		i++;

		// (x + 1, y, z)
		skyVertices[i].x = vfpu_sinf((sun_angle / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf((sun_angle / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = 250 * 0.9f;// * stepScale;
		skyVertices[i].u = 1.f;// * textureScale;
		skyVertices[i].v = 0.f;// * textureScale;
		i++;

		// (x + 1, y - 1, z)
		skyVertices[i].x = vfpu_sinf(((sun_angle - 45 * 0.9f) / 180) * PI) * r;// * stepScale;
		skyVertices[i].y = vfpu_cosf(((sun_angle - 45 * 0.9f) / 180) * PI) * -r;// * stepScale;
		skyVertices[i].z = 250 * 0.9f;// * stepScale;
		skyVertices[i].u = 1.f;// * textureScale;
		skyVertices[i].v = 1.f;// * textureScale;

		sceKernelDcacheWritebackInvalidateRange(skyVertices, 4 * sizeof(TextureVertex));
	}

	void Sun::Draw()
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
		sceGuEnable(GU_CULL_FACE);
		sceGuEnable(GU_DEPTH_TEST);

		//make default blend function
		sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
	}
}
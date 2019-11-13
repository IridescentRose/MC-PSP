#include "Clouds.h"
#include "../../Common/Options.hpp"

namespace Minecraft::Rendering {
	Clouds::Clouds()
	{
		cloudVerts = (TexturedVertex*)memalign(16, 4 * sizeof(TexturedVertex));
		tex = TextureUtil::LoadPngTexturePack("environment/clouds.png");

		Update();
	}
	Clouds::~Clouds()
	{
		free(cloudVerts);
		delete tex;
	}

	void Clouds::Update()
	{
		int i = 0;

		cloudVerts[i].x = -256*2*3;
		cloudVerts[i].y =  128;
		cloudVerts[i].z = -256*2*3;
		cloudVerts[i].u = 0.f;
		cloudVerts[i].v = 0.f;
		i++;

		// (x, y - 1, z)
		cloudVerts[i].x = -256*2*3;
		cloudVerts[i].y = 128;
		cloudVerts[i].z = 256*2*3;
		cloudVerts[i].u = 0.f;
		cloudVerts[i].v = 3.f;
		i++;


		// (x + 1, y, z)
		cloudVerts[i].x = 256*2*3;
		cloudVerts[i].y = 128;
		cloudVerts[i].z = -256*2*3;
		cloudVerts[i].u = 3.f;
		cloudVerts[i].v = 0.f;
		i++;

		// (x + 1, y - 1, z)
		cloudVerts[i].x = 256*2*3;
		cloudVerts[i].y = 128;
		cloudVerts[i].z = 256*2*3;
		cloudVerts[i].u = 3.f;
		cloudVerts[i].v = 3.f;
		i++;

		sceKernelDcacheWritebackInvalidateRange(cloudVerts, 4 * sizeof(TexturedVertex));
	}

	void Clouds::Draw(mc::Vector3d pos, s64 dt)
	{
		sceGuEnable(GU_TEXTURE_2D);
		sceGuEnable(GU_BLEND);
		sceGuDisable(GU_CULL_FACE);
		sceGuDisable(GU_DEPTH_TEST);
		sceGuDisable(GU_CLIP_PLANES);
		
		sceGumPushMatrix();
		ScePspFVector3 v = { pos.x + 0.0f, 0.0f, pos.z + (dt % 5460) * 2400.0f / 25600.0f };
		sceGumTranslate(&v);

		
		sceGuTexScale(0.25f, 0.25f);
		tex->bindTextureRepeat(0, 0, true);

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

		sceGuColor(GU_COLOR(1.0f, 1.0f, 1.0f, alpha));

		sceGumDrawArray(GU_TRIANGLE_STRIP, GU_TEXTURE_32BITF | GU_VERTEX_32BITF | GU_TRANSFORM_3D, 4, 0, cloudVerts);

		sceGuTexScale(1.0f, 1.0f);
		sceGuColor(GU_COLOR(1.0f, 1.0f, 1.0f, 1.0f));


		sceGumPopMatrix();

		sceGuEnable(GU_CLIP_PLANES);
		sceGuDisable(GU_TEXTURE_2D);
		sceGuDisable(GU_BLEND);
		sceGuEnable(GU_CULL_FACE);
		sceGuEnable(GU_DEPTH_TEST);
	}
}
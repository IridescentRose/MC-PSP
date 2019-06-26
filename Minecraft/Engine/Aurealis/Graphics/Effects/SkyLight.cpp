#include <Aurealis/Graphics/Effects/SkyLight.h>
#include <Aurealis/Graphics/RenderManager.h>

#define PI 3.1415926535897f
#define DEG_TO_RAD (PI / 180.0f)

namespace Aurealis
{
	namespace Graphics
	{
		SkyLight::SkyLight()
		{
			skyVertices = (TexturedVertex*)memalign(16,4 * sizeof(TexturedVertex));
			isMoon = false;
		}

		SkyLight::~SkyLight()
		{
			free(skyVertices);
		}

		void  SkyLight::UpdateLightSource(float sun_angle, int day, bool moon)
		{
			isMoon = moon;
			float xMin, yMin, xMax, yMax;
			xMin = yMin = xMax = yMax = 0;
			if (moon) {
				int phase = day % 8;

				int xpos = day % 4;
				int ypos = 0;
				if (day < 4) {
					ypos = 0;
				}
				else {
					ypos = 1;
				}

				xMin = 0.25f * xpos;
				yMin = 0.5f * ypos;

				xMax = 0.25f * xpos + 0.25f;
				yMax = 0.5f * ypos + 0.5f;
			}
			else {
				xMin = 0.f;
				yMin = 0.f;
				xMax = 1.f;
				yMax = 1.f;
			}

			float r = 0.0f;
			
			if (moon) {
				r = 670.0f*2;
			}
			else {
				r = 670.0f*2;
			}
			float shift = 325;
			//float textureScale = 1.0f / stepScale;

			int i = 0;

			skyVertices[i].x = vfpu_sinf((sun_angle / 180) * PI) * r;// * stepScale;
			skyVertices[i].y = vfpu_cosf(((sun_angle) / 180) * PI) * -r;// * stepScale;
			skyVertices[i].z = -500 * 0.9f;// * stepScale;
			skyVertices[i].u = xMin;// * textureScale;
			skyVertices[i].v = yMin;// * textureScale;
			i++;

			// (x, y - 1, z)
			skyVertices[i].x = vfpu_sinf(((sun_angle - 45 * 0.9f) / 180) * PI) * r;// * stepScale;
			skyVertices[i].y = vfpu_cosf(((sun_angle - 45 * 0.9f) / 180) * PI) * -r;// * stepScale;
			skyVertices[i].z = -500 * 0.9f;// * stepScale;
			skyVertices[i].u = xMin;// * textureScale;
			skyVertices[i].v = yMax;// * textureScale;
			i++;

			// (x + 1, y, z)
			skyVertices[i].x = vfpu_sinf((sun_angle / 180) * PI) * r;// * stepScale;
			skyVertices[i].y = vfpu_cosf((sun_angle / 180) * PI) * -r;// * stepScale;
			skyVertices[i].z = 500 * 0.9f;// * stepScale;
			skyVertices[i].u = xMax;// * textureScale;
			skyVertices[i].v = yMin;// * textureScale;
			i++;

			// (x + 1, y - 1, z)
			skyVertices[i].x = vfpu_sinf(((sun_angle - 45 * 0.9f) / 180) * PI) * r;// * stepScale;
			skyVertices[i].y = vfpu_cosf(((sun_angle - 45 * 0.9f) / 180) * PI) * -r;// * stepScale;
			skyVertices[i].z = 500 * 0.9f;// * stepScale;
			skyVertices[i].u = xMax;// * textureScale;
			skyVertices[i].v = yMax;// * textureScale;

			sceKernelDcacheWritebackInvalidateRange(skyVertices, 4 * sizeof(TexturedVertex));
		}

		void SkyLight::Render()
		{
			sceGumPushMatrix();
			sceGumRotateX(40.0f / 180.0f * 3.14159f);
			
			sceGuEnable(GU_TEXTURE_2D);
			sceGuEnable(GU_BLEND);

			sceGuBlendFunc(GU_ADD, GU_FIX,GU_FIX, 0xFFFFFFFF, 0xFFFFFFFF);
			sceGumDrawArray(GU_TRIANGLE_STRIP, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, skyVertices);

			sceGuDisable(GU_TEXTURE_2D);
			sceGuDisable(GU_BLEND);

			//make default blend function
			sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
			sceGumPopMatrix();
		}
	}
}


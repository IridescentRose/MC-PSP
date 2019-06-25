#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Graphics/Vertex.h>
#include <pspmath.h>
#include <pspgu.h>
#include <pspgum.h>
#include <pspkernel.h>
#include <stdlib.h>
#include <pspdebug.h>
#include <cstdlib>
#include <pspsysmem.h>
#include <memory>
namespace Aurealis
{
	namespace Graphics
	{
		class SkyLight
		{
		public:
			SkyLight();
			~SkyLight();

			void UpdateLightSource(float sun_angle, int day = -1, bool moon = false);
			void Render();

		private:

			TexturedVertex *skyVertices;
			bool isMoon;
			float sun_angle;
		};
	}
}

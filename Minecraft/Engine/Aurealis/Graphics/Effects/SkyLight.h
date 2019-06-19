#pragma once

#include <Aurealis/Math/Vector3.h>
#include <Aurealis/Graphics/Vertex.h>
#include <pspmath.h>

namespace Aurealis
{
	namespace Graphics
	{
		class SkyLight
		{
		public:
			SkyLight();
			~SkyLight();

			void UpdateLightSource(float sun_angle);
			void Render();

		private:

			TexturedVertex *skyVertices;

			float sun_angle;
		};
	}
}

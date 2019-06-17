#ifndef SKYLIGHT_H_
#define SKYLIGHT_H_

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

			TexturesPSPVertex *skyVertices;

			float sun_angle;
		};
	}
}

#endif


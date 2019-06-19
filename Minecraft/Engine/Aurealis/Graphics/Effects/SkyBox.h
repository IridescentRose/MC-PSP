#pragma once

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <Aurealis/Math/Frustum.h>

namespace Aurealis
{
	namespace Graphics
	{
		class SkyBox
		{
		public:
			SkyBox();
			~SkyBox();

            void BuildVertexObject();
			void Update();
			void Render(Vector3 color, Vector3 playerPos, float camAngle);

		private:

			ColoredVertex2 *skyBoxVertices;

			float size;
			int vertsNum;
		};
	}
}

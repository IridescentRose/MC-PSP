#ifndef DESTROYER_H_
#define DESTROYER_H_

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <Aurealis/Math/Frustum.h>
#include <LameCraft/CraftWorld2.h>
#include <Aurealis/Math/BoundingBox.h>

namespace Aurealis
{
	namespace Graphics
	{
		class Destroyer
		{
		public:
			Destroyer();
			~Destroyer();

			void Update(float stad, CraftWorld* crft, int blockId);
			void Render(float stad);

		private:

			TexturesPSPVertex *boxVertices;
			TexturesPSPVertex *boxVertices2;
			TexturesPSPVertex *boxVertices3;
			TexturesPSPVertex *boxVertices4;
			TexturesPSPVertex *boxVertices5;
			TexturesPSPVertex *boxVertices6;

			SimplePSPVertex2 *boxVertices11;
			SimplePSPVertex2 *boxVertices12;
			SimplePSPVertex2 *boxVertices13;
			SimplePSPVertex2 *boxVertices14;
			SimplePSPVertex2 *boxVertices15;
			SimplePSPVertex2 *boxVertices16;

			float size;
		};
	}
}

#endif


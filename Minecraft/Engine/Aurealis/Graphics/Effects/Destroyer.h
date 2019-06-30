#pragma once

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <Aurealis/Math/Frustum.h>
#include <LameCraft/World/CraftWorld2.h>
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

			TexturedVertex *boxVertices;
			TexturedVertex *boxVertices2;
			TexturedVertex *boxVertices3;
			TexturedVertex *boxVertices4;
			TexturedVertex *boxVertices5;
			TexturedVertex *boxVertices6;

			ColoredVertex2 *boxVertices11;
			ColoredVertex2 *boxVertices12;
			ColoredVertex2 *boxVertices13;
			ColoredVertex2 *boxVertices14;
			ColoredVertex2 *boxVertices15;
			ColoredVertex2 *boxVertices16;

			float size;
		};
	}
}

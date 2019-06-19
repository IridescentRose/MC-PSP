#pragma once

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/RenderManager.h>
#include <pspmath.h>
#include <Aurealis/Math/Frustum.h>

namespace Aurealis
{
	namespace Graphics
	{
		class StarsBox
		{
		public:
			StarsBox();
			~StarsBox();

            void Build();
			void Update();
			void Render(float alpha);

		private:

			TexturedVertex *boxVertices;
			TexturedVertex *boxVertices2;
			TexturedVertex *boxVertices3;
			TexturedVertex *boxVertices4;
			TexturedVertex *boxVertices5;
			TexturedVertex *boxVertices6;

			float size;
		};
	}
}

#pragma once

#include <glm/glm.hpp>
#include <Shadow/Graphics/RenderManager.h>

using namespace Shadow::Graphics;

namespace Minecraft::Rendering {
	class Sky {
	public:
		Sky();
		~Sky();

		void Update(s64 timeOfDay);
		void Draw();

	private:
		ColoredVertex* skyBoxVertices;

		float size;
		int vertsNum;

	};
}
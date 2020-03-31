#pragma once

#include <glm/glm.hpp>
#include <Graphics/RendererCore.h>

using namespace Stardust::Graphics;

namespace Minecraft::Rendering {
	class Sky {
	public:
		Sky();
		~Sky();

		void Update(s64 timeOfDay);
		void Draw();

	private:
		ColorVertex* skyBoxVertices;

		float size;
		int vertsNum;

	};
}
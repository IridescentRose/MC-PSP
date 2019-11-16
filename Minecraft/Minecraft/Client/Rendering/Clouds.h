#pragma once

#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Vertex.h>
#include <mclib/common/Vector.h>

using namespace Shadow::Graphics;

namespace Minecraft::Rendering {
	class Clouds {
	public:
		Clouds();
		~Clouds();

		void Update();
		void Draw(mc::Vector3d pos, s64 timeOfDay);


	private:
		Texture* tex;
		TexturedVertex* cloudVerts;
		int count;
	};
}
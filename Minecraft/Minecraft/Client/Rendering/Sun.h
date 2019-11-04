#pragma once

#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Vertex.h>

using namespace Shadow::Graphics;

namespace Minecraft::Rendering {
	class Sun
	{
	public:
		Sun();
		~Sun();

		void Update(float sun_angle);
		void Draw();

	private:
		Texture* tex;
		TexturedVertex* skyVertices;

		float sun_angle;
	};
}
#pragma once

#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Vertex.h>

using namespace Shadow::Graphics;

namespace Minecraft::Rendering {
	class Moon
	{
	public:
		Moon();
		~Moon();

		void Update(float moon_angle, s64 worldAge);
		void Draw();

	private:
		Texture* tex;
		TexturedVertex* skyVertices;

		float moon_angle;
	};
}
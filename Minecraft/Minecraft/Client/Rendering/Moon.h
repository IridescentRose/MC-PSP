#pragma once

#include <Graphics/RendererCore.h>
#include <Graphics/TextureUtil.h>

using namespace Stardust::Graphics;

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
		TextureVertex* skyVertices;

		float moon_angle;
	};
}
#pragma once

#include <Graphics/RendererCore.h>
#include <Graphics/RenderTypes.h>
#include <Graphics/TextureUtil.h>

using namespace Stardust::Graphics;

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
		TextureVertex* skyVertices;

		float sun_angle;
	};
}
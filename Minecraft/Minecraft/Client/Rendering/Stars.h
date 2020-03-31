#pragma once

#include <Graphics/RendererCore.h>

using namespace Stardust::Graphics;

namespace Minecraft::Rendering {
	class Stars {
	public:
		Stars();
		~Stars();

		void Build();
		void Draw(float alpha);

	private:
		TextureVertex* boxVertices;
		TextureVertex* boxVertices2;
		TextureVertex* boxVertices3;
		TextureVertex* boxVertices4;
		TextureVertex* boxVertices5;
		TextureVertex* boxVertices6;
		float size;

		Texture* tex;

	};
}
#pragma once

#include <Shadow/Graphics/RenderManager.h>

using namespace Shadow::Graphics;

namespace Minecraft::Rendering {
	class Stars {
	public:
		Stars();
		~Stars();

		void Build();
		void Draw(float alpha);

	private:
		TexturedVertex* boxVertices;
		TexturedVertex* boxVertices2;
		TexturedVertex* boxVertices3;
		TexturedVertex* boxVertices4;
		TexturedVertex* boxVertices5;
		TexturedVertex* boxVertices6;
		float size;

		Texture* tex;

	};
}
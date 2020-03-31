#pragma once

#include <Graphics/RendererCore.h>
#include <Graphics/TextureUtil.h>
#include <glm/glm.hpp>
using namespace Stardust::Graphics;

namespace Minecraft::Rendering {
	class Clouds {
	public:
		Clouds();
		~Clouds();

		void Update();
		void Draw(glm::vec3 pos, s64 timeOfDay);


	private:
		Texture* tex;
		TextureVertex* cloudVerts;
		int count;
	};
}
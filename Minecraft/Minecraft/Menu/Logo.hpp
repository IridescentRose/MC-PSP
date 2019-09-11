#pragma once
#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Sprite.h>
#include <Shadow/Utils/Timer.hpp>
#include <Shadow/Graphics/Texture.h>

using namespace Shadow::Graphics;
using namespace Shadow::Utils;

namespace Minecraft::Menus{
    class Logo{
        public:
        Logo();
        ~Logo();

        void render(Texture* tex, unsigned int backgroundColor, float t);

        private:

        Timer time;
        Sprite* sprite;
    };
}
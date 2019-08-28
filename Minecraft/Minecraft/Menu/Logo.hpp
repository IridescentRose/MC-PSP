#pragma once
#include <Aurealis/Graphics/RenderManager.h>
#include <Aurealis/Graphics/Sprite.h>
#include <Shadow/Utils/Timer.hpp>
#include <Aurealis/Graphics/Texture.h>

using namespace Aurealis::Graphics;
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
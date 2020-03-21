#pragma once
#include <Shadow/Graphics/RenderManager.h>
#include <Shadow/Graphics/Sprite.h>
#include <Utilities/Timer.h>
#include <Shadow/Graphics/Texture.h>

using namespace Shadow::Graphics;

namespace Minecraft::Menus{
    class Logo{
        public:
        Logo();
        ~Logo();

        void render(Texture* tex, unsigned int backgroundColor, float t);

        private:

        Stardust::Utilities::Timer time;
        Sprite* sprite;
    };
}
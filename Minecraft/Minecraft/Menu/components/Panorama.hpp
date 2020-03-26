#pragma once
#include <Graphics/RenderTypes.h>
#include <Graphics/TextureUtil.h>
#include <pspmath.h>

namespace Minecraft::Menus{

using namespace Stardust;
using namespace Stardust::Graphics;

    class Panorama{
        public:

        Panorama();
        ~Panorama();

        void render();
        void update(float dt);

        private:

        float angleX, angleY;
        float size;
        int vertCount;

        TextureVertex* box0;
        TextureVertex* box1;
        TextureVertex* box2;
        TextureVertex* box3;
        TextureVertex* box4;
        TextureVertex* box5;

        Texture* tex0;
        Texture* tex1;
        Texture* tex2;
        Texture* tex3;
        Texture* tex4;
        Texture* tex5;
    };
}
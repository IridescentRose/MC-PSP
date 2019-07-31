#pragma once
#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/TextureUtil.h>


namespace Minecraft::Menus{

using namespace Aurealis::Graphics;
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

        TexturedVertex* box0;
        TexturedVertex* box1;
        TexturedVertex* box2;
        TexturedVertex* box3;
        TexturedVertex* box4;
        TexturedVertex* box5;

        Texture* tex0;
        Texture* tex1;
        Texture* tex2;
        Texture* tex3;
        Texture* tex4;
        Texture* tex5;
    };
}
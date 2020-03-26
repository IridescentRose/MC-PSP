#include "Panorama.hpp"

namespace Minecraft::Menus{
    Panorama::Panorama(){
        vertCount = 0;

        //BUILD VERTICES
        box0 = (TextureVertex*)memalign(16,4 * sizeof(TextureVertex));
		box1 = (TextureVertex*)memalign(16,4 * sizeof(TextureVertex));
		box2 = (TextureVertex*)memalign(16,4 * sizeof(TextureVertex));
		box3 = (TextureVertex*)memalign(16,4 * sizeof(TextureVertex));
		box4 = (TextureVertex*)memalign(16,4 * sizeof(TextureVertex));
		box5 = (TextureVertex*)memalign(16,4 * sizeof(TextureVertex));

        tex0 = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/background/panorama_1.png");
        tex1 = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/background/panorama_3.png");
        tex2 = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/background/panorama_2.png");
        tex3 = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/background/panorama_0.png");
        tex4 = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/background/panorama_4.png");
        tex5 = TextureUtil::LoadPng("./assets/minecraft/textures/gui/title/background/panorama_5.png");

        size = 1.0f;

        int i = 0;

			box0[i].x = size;
			box0[i].y = -size;
			box0[i].z = size;
			box0[i].u = 1;
			box0[i].v = 1;
			i++;

			box0[i].x = size;
			box0[i].y = size;
			box0[i].z = size;
            box0[i].u = 1;
			box0[i].v = 0;
			i++;

			box0[i].x = size;
			box0[i].y = size;
			box0[i].z = -size;
            box0[i].u = 0;
			box0[i].v = 0;
			i++;

			box0[i].x = size;
			box0[i].y = -size;
			box0[i].z = -size;
			box0[i].u = 0;
			box0[i].v = 1;
			i++;

			sceKernelDcacheWritebackInvalidateRange(box0,4 * sizeof(TextureVertex));

            i = 0;

			box1[i].x = -size;
			box1[i].y = -size;
			box1[i].z = -size;
			box1[i].u = 1;
			box1[i].v = 1;
			i++;

			box1[i].x = -size;
			box1[i].y = size;
			box1[i].z = -size;
            box1[i].u = 1;
			box1[i].v = 0;
			i++;

			box1[i].x = -size;
			box1[i].y = size;
			box1[i].z = size;
            box1[i].u = 0;
			box1[i].v = 0;
			i++;

			box1[i].x = -size;
			box1[i].y = -size;
			box1[i].z = size;
			box1[i].u = 0;
			box1[i].v = 1;
			i++;

			sceKernelDcacheWritebackInvalidateRange(box1,4 * sizeof(TextureVertex));

            i = 0;

			box2[i].x = -size;
			box2[i].y = size;
			box2[i].z = size;
			box2[i].u = 1;
			box2[i].v = 0;
			i++;

			box2[i].x = size;
			box2[i].y = size;
			box2[i].z = size;
			box2[i].u = 0;
			box2[i].v = 0;
			i++;

			box2[i].x = size;
			box2[i].y = -size;
			box2[i].z = size;
			box2[i].u = 0;
			box2[i].v = 1;
			i++;

			box2[i].x = -size;
			box2[i].y = -size;
			box2[i].z = size;
			box2[i].u = 1;
			box2[i].v = 1;
			i++;

			sceKernelDcacheWritebackInvalidateRange(box2,4 * sizeof(TextureVertex));

            i = 0;

			box3[i].x = -size;
			box3[i].y = -size;
			box3[i].z = -size;
			box3[i].u = 0;
			box3[i].v = 1;
			i++;

			box3[i].x = size;
			box3[i].y = -size;
			box3[i].z = -size;
            box3[i].u = 1;
			box3[i].v = 1;
			i++;

			box3[i].x = size;
			box3[i].y = size;
			box3[i].z = -size;
            box3[i].u = 1;
			box3[i].v = 0;
			i++;

			box3[i].x = -size;
			box3[i].y = size;
			box3[i].z = -size;
			box3[i].u = 0;
			box3[i].v = 0;
			i++;

			sceKernelDcacheWritebackInvalidateRange(box3,4 * sizeof(TextureVertex));

            i = 0;

			box4[i].x = -size;
			box4[i].y = size;
			box4[i].z = -size;
			box4[i].u = 0;
			box4[i].v = 0;
			i++;

			box4[i].x = size;
			box4[i].y = size;
			box4[i].z = -size;
			box4[i].u = 1;
			box4[i].v = 0;
			i++;

			box4[i].x = size;
			box4[i].y = size;
			box4[i].z = size;
			box4[i].u = 1;
			box4[i].v = 1;
			i++;

			box4[i].x = -size;
			box4[i].y = size;
			box4[i].z = size;
			box4[i].u = 0;
			box4[i].v = 1;
			i++;

			sceKernelDcacheWritebackInvalidateRange(box4,4 * sizeof(TextureVertex));

            i = 0;

			box5[i].x = -size;
			box5[i].y = -size;
			box5[i].z = size;
			box5[i].u = 0;
			box5[i].v = 0;
			i++;

			box5[i].x = size;
			box5[i].y = -size;
			box5[i].z = size;
			box5[i].u = 1;
			box5[i].v = 0;
			i++;

			box5[i].x = size;
			box5[i].y = -size;
			box5[i].z = -size;
			box5[i].u = 1;
			box5[i].v = 1;
			i++;

			box5[i].x = -size;
			box5[i].y = -size;
			box5[i].z = -size;
			box5[i].u = 0;
			box5[i].v = 1;
			i++;

			sceKernelDcacheWritebackInvalidateRange(box5,4 * sizeof(TextureVertex));
    }

    Panorama::~Panorama(){
        free(box0);
        free(box1);
        free(box2);
        free(box3);
        free(box4);
        free(box5);

        delete tex0;
        delete tex1;
        delete tex2;
        delete tex3;
        delete tex4;
        delete tex5;
    }

    void Panorama::update(float dt){
        angleX += dt * (360.0f / 180.0f);
        angleY = vfpu_sinf( (angleX + 90) / 180 * 3.14159)*30.0f+5.0f;
    }

    void Panorama::render(){
        sceGumMatrixMode(GU_VIEW);
        sceGumPushMatrix();
        sceGumLoadIdentity();

        sceGumRotateX(angleY/180 * 3.14159);
        sceGumRotateY(angleX/180 * 3.14159);
        sceGumRotateZ(0.0f);

        sceGuEnable(GU_TEXTURE_2D);
		sceGuEnable(GU_BLEND);
		sceGuDisable(GU_DEPTH_TEST);
        sceGuDisable(GU_CULL_FACE);
		sceGuDepthMask(GU_TRUE);
        
		
        tex0->bindTexture(GU_LINEAR_MIPMAP_LINEAR, GU_LINEAR_MIPMAP_LINEAR);
		sceGumDrawArray(GU_TRIANGLE_FAN, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, box0);
		
        tex1->bindTexture(GU_LINEAR_MIPMAP_LINEAR, GU_LINEAR_MIPMAP_LINEAR);
        sceGumDrawArray(GU_TRIANGLE_FAN, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, box1);
		
        tex2->bindTexture(GU_LINEAR_MIPMAP_LINEAR, GU_LINEAR_MIPMAP_LINEAR);
        sceGumDrawArray(GU_TRIANGLE_FAN, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, box2);
		
        tex3->bindTexture(GU_LINEAR_MIPMAP_LINEAR, GU_LINEAR_MIPMAP_LINEAR);
        sceGumDrawArray(GU_TRIANGLE_FAN, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, box3);
		
        tex4->bindTexture(GU_LINEAR_MIPMAP_LINEAR, GU_LINEAR_MIPMAP_LINEAR);
        sceGumDrawArray(GU_TRIANGLE_FAN, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, box4);
		
        tex5->bindTexture(GU_LINEAR_MIPMAP_LINEAR, GU_LINEAR_MIPMAP_LINEAR);
        sceGumDrawArray(GU_TRIANGLE_FAN, GU_TEXTURE_32BITF|GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, box5);

        sceGuEnable(GU_DEPTH_TEST);

        sceGuEnable(GU_CULL_FACE);
		sceGuDepthMask(GU_FALSE);

        sceGumPopMatrix();
    }
}
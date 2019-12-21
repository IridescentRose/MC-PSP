#pragma once

#include <stdarg.h>

#include <Shadow/Utils/vram.h>
#include <Shadow/Utils/vram.h>
#include <Shadow/Utils/common.h>

#include <Shadow/Graphics/Vertex.h>
#include <Shadow/Graphics/TextureUtil.h>

#include <intraFont.h>

//psp headers
#include <pspgu.h>
#include <pspgum.h>
#include <pspctrl.h>
#include <pspkernel.h>
#include <pspdisplay.h>
#include <pspdebug.h>
#include <psppower.h>
#include <psptypes.h>
#include <pspge.h>
#include <psputils.h>

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


#define BUF_WIDTH (512)
#define SCR_WIDTH (480)
#define SCR_HEIGHT (272)

namespace Shadow
{
	namespace Graphics
	{
		class RenderManager
		{
		public:

			
			float fovv;

			void Init();
			void InitDebugFont();
			
			void SetFontStyle(float size, unsigned int color, unsigned int shadowColor, unsigned int options, float angle);
			void DebugPrint(int x,int y, const char *message, ...);
			void Start();
			void CleanBuffers();
			void DrawCube(float x, float y, float z);


			void StartFrame(float a, float b, float c);
			void EndFrame();

			//dialogs rendering
			void StartDialog();
			void EndDialog();

			void UseVerticalSync(bool Enabled);
			void SetClearColor(float r,float g,float b,float a);

			void SetOrtho();
			void SetPerspective(float _fov,float _aspect,float _znear,float _zfar);
			
			void DrawToTexture(Texture* offscreenTexture );
			void SetRTT();


			void UpdateFrustumMatrix();

			void SetClearColour(unsigned int color);

			int GetCpuUsage() {return g_cpu_load;}
			int GetGpuUsage() {return g_gpu_load;}
			void CollectPerformance(bool state){performanceCounter = state; }

			
			int defaultFontType;


			protected:
				



		private:
			unsigned int cleanColor;

            void* _fbp0;
			void* _fbp1;
			void* _zbp;
			void* _frameBuffer;

			char list[0x20000] __attribute__((aligned(64)));//__attribute__((aligned(16))) list[262144]
			int listNum;

			bool mVerticalSync;

			ScePspFMatrix4 proj;
			ScePspFMatrix4 view;
			ScePspFMatrix4 projection_view_matrix;

			//debug font
			intraFont* debugFont;
			intraFont* numFont;
			intraFont* engFont;
			intraFont* rusFont;
			intraFont* jpn0;
			intraFont* kr0; 
			intraFont* arib;
			intraFont* chn; 
			float fontVerticalShift;
			int fontType;

			float fov,aspect,znear,zfar;

			int screenNumber;

		private:

			//cpu and gpu timing
			int g_vbl_count;	// previous vblank count
			int g_vbl_step;		// previous vblank step
			int g_vbl_time;		// previous vblank time
			int g_cpu_load;		// current cpu load
			int g_gpu_load;		// current gpu load
			int g_frame_count;
			bool performanceCounter;

		};

		extern RenderManager g_RenderManager;
	}

}

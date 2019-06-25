#pragma once

#include <stdarg.h>

#include <Aurealis/Graphics/vram.h>
#include <Aurealis/Graphics/vram.h>
#include <Aurealis/Graphics/common.h>

#include <Aurealis/Graphics/Vertex.h>
#include <Aurealis/Graphics/Camera.h>
#include <Aurealis/Graphics/TextureUtil.h>

#include <Aurealis/Graphics/intraFont/intraFont.h>

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
#define PIXEL_SIZE (4) /* change this if you change to another screenmode */
#define FRAME_SIZE (BUF_WIDTH * SCR_HEIGHT * PIXEL_SIZE)
#define ZBUF_SIZE (BUF_WIDTH SCR_HEIGHT * 2) /* zbuffer seems to be 16-bit? */

#define	FRAME_BUFFER_WIDTH 		512
#define FRAME_BUFFER_SIZE		FRAME_BUFFER_WIDTH*SCR_HEIGHT*PIXEL_SIZE

#define	BUFFER_FORMAT		  GU_PSM_8888
#define SCEGU_SCR_WIDTH       480
#define SCEGU_SCR_HEIGHT      272
#define SCEGU_SCR_ASPECT      ((float)SCEGU_SCR_WIDTH / (float)SCEGU_SCR_HEIGHT)
#define SCEGU_SCR_OFFSETX     ((4096 - SCEGU_SCR_WIDTH) / 2)
#define SCEGU_SCR_OFFSETY     ((4096 - SCEGU_SCR_HEIGHT) / 2)

/* Frame buffer */
#define SCEGU_VRAM_TOP        0x00000000
#define SCEGU_VRAM_WIDTH      512
/* 16bit mode */
#define SCEGU_VRAM_BUFSIZE    (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*2)
#define SCEGU_VRAM_BP_0       (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP_1       (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE)
#define SCEGU_VRAM_BP_2       (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE*2))
/* 32bit mode */
#define SCEGU_VRAM_BUFSIZE32  (SCEGU_VRAM_WIDTH*SCEGU_SCR_HEIGHT*4)
#define SCEGU_VRAM_BP32_0     (void *)(SCEGU_VRAM_TOP)
#define SCEGU_VRAM_BP32_1     (void *)(SCEGU_VRAM_TOP+SCEGU_VRAM_BUFSIZE32)
#define SCEGU_VRAM_BP32_2     (void *)(SCEGU_VRAM_TOP+(SCEGU_VRAM_BUFSIZE32*2))

namespace Aurealis
{
	namespace Graphics
	{
		class RenderManager
		{
		public:

			enum FontColor
			{
				RED =	0xFF0000FF,
				YELLOW = 0xFFFF00FF,
				GREEN =	0xFF00FF00,
				BLUE =	0xFFFF0000,
				WHITE =	0xFFFFFFFF,
				LITEGRAY = 0xFFBFBFBF,
				GRAY =  0xFF7F7F7F,
				DARKGRAY = 0xFF3F3F3F,
				BLACK = 0xFF000000
			};

			float fovv;

			void Init();

			void InitDebugFont();
			void SetFontStyle(float size, unsigned int color, unsigned int shadowColor, unsigned int options);
			void SetFont(int type);
			void SetDefaultFont();
			int GetFontLanguage();

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

			void SetOrtho(float left, float right, float bottom, float top, float zNear, float zFar);
			void SetOrtho2(float left, float right, float bottom, float top, float zNear, float zFar);
			void SetPerspective(float _fov,float _aspect,float _znear,float _zfar);
			void LookAt();

			void DrawToTexture(Texture* offscreenTexture );
			void SetRTT();


			void SetActiveCamera(Camera *camera);
			void UpdateFrustumMatrix();

			void SetClearColour(unsigned int color);

			int GetCpuUsage() {return g_cpu_load;}
			int GetGpuUsage() {return g_gpu_load;}
			void CollectPerformance(bool state){performanceCounter = state; }

			
			int defaultFontType;

			Camera *mCam;

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

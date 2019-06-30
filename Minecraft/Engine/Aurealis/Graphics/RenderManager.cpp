#include <Aurealis/Graphics/RenderManager.h>

namespace Aurealis
{
	namespace Graphics
	{
        float cubeSize = 0.5075f;
        ColoredVertex2 __attribute__((aligned(16))) top[4] =
		{
			{-cubeSize,-cubeSize,cubeSize},	// Top
			{cubeSize,-cubeSize,cubeSize},
			{ cubeSize,-cubeSize,-cubeSize},
			{ -cubeSize,-cubeSize, -cubeSize}
		};
		ColoredVertex2 __attribute__((aligned(16))) bottom[4] =
		{
			{-cubeSize, cubeSize, -cubeSize},	// Bottom
			{ cubeSize, cubeSize, -cubeSize},
			{ cubeSize, cubeSize, cubeSize},
			{-cubeSize, cubeSize, cubeSize}
		};
		ColoredVertex2 __attribute__((aligned(16))) front[4] =
		{
			{-cubeSize,-cubeSize, cubeSize},	// Front
			{ cubeSize,-cubeSize, cubeSize},
			{ cubeSize, cubeSize, cubeSize},
			{-cubeSize, cubeSize, cubeSize}
		};
		ColoredVertex2 __attribute__((aligned(16))) back[4] =
		{
			{- cubeSize,cubeSize, -cubeSize},	// Back
			{ cubeSize,cubeSize,-cubeSize},
			{ cubeSize, -cubeSize,-cubeSize},
			{ -cubeSize, -cubeSize, -cubeSize}
		};
		ColoredVertex2 __attribute__((aligned(16))) left[4] =
		{
			{ -cubeSize,-cubeSize,cubeSize},	// Left
			{-cubeSize,cubeSize,cubeSize},
			{-cubeSize, cubeSize,-cubeSize},
			{ -cubeSize, -cubeSize,-cubeSize}
		};
		ColoredVertex2 __attribute__((aligned(16))) right[4] =
		{
			{cubeSize,-cubeSize,-cubeSize},	// Right
			{cubeSize,cubeSize, -cubeSize},
			{cubeSize, cubeSize, cubeSize},
			{cubeSize, -cubeSize,cubeSize}
		};

        void RenderManager::DrawCube(float x, float y, float z)
        {
           /* sceGumPushMatrix();
			ScePspFVector3 move = {x,y,z};
			sceGumTranslate(&move);
			sceGuColor(GU_COLOR(0,0,0,1));
			sceGuDisable(GU_TEXTURE_2D);
			sceGuShadeModel(GU_FLAT);
			sceGumDrawArray( GU_LINE_STRIP, GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, top);
			sceGumDrawArray( GU_LINE_STRIP, GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, bottom);
			sceGumDrawArray( GU_LINE_STRIP, GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, front);
			sceGumDrawArray( GU_LINE_STRIP, GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, back);
			sceGumDrawArray( GU_LINE_STRIP, GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, left);
			sceGumDrawArray( GU_LINE_STRIP, GU_VERTEX_32BITF|GU_TRANSFORM_3D, 4, 0, right);
			sceGuShadeModel(GU_SMOOTH);
			sceGumPopMatrix();*/
        }

		void RenderManager::Init()
		{
		    fontVerticalShift = 0;
		    fontType = 0;
		    defaultFontType = 1;

		    SetFont(1);
			mVerticalSync = false;
			listNum = 0;
			cleanColor = 0xFF00FF00; //0xFFF5B783
			fov = 65.0f;//54
			fovv = 65.0f;
			aspect =  480.0f / 272.0f;
			znear = 0.1f;
			zfar = 200.0f;
			screenNumber = 0;

			//initialize GU engine
			sceGuInit();

			sceGuStart(GU_DIRECT,list);


            sceGuDrawBuffer( GU_PSM_8888, SCEGU_VRAM_BP32_0, BUF_WIDTH );
			sceGuDispBuffer( SCR_WIDTH, SCR_HEIGHT, SCEGU_VRAM_BP32_1, BUF_WIDTH);
			sceGuDepthBuffer( SCEGU_VRAM_BP32_2, BUF_WIDTH);

			sceGuOffset(2048 - (SCR_WIDTH/2),2048 - (SCR_HEIGHT/2));
			sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);

            sceGuDepthRange(50000, 10000);

			sceGuEnable(GU_SCISSOR_TEST);
			sceGuScissor(0,0,SCR_WIDTH,SCR_HEIGHT);
			sceGuEnable(GU_SCISSOR_TEST);
			sceGuDepthFunc(GU_GEQUAL);
			sceGuEnable(GU_DEPTH_TEST);

			sceGuDisable(GU_TEXTURE_2D);
			sceGuEnable(GU_CLIP_PLANES);

			sceGuEnable(GU_CULL_FACE);
            sceGuFrontFace(GU_CCW);

			sceGuEnable(GU_BLEND);
            sceGuBlendFunc(GU_ADD, GU_SRC_ALPHA, GU_ONE_MINUS_SRC_ALPHA, 0, 0);
			sceGuAlphaFunc(GU_GREATER, 0.0f, 0xff );

			sceGuStencilFunc(GU_ALWAYS, 1, 1); // always set 1 bit in 1 bit mask
			sceGuStencilOp(GU_KEEP, GU_KEEP, GU_REPLACE); // keep value on failed test (fail and zfail) and replace on pass

			sceGuTexFilter(GU_LINEAR,GU_LINEAR);
			sceGuFinish();
			sceGuSync(0,0);

			sceDisplayWaitVblankStart();
			sceGuDisplay(GU_TRUE);

			sceCtrlSetSamplingCycle(0);
			sceCtrlSetSamplingMode(PSP_CTRL_MODE_ANALOG);

			//initialize variables
			mCam = 0;

			g_vbl_count = -1;
			g_vbl_step = 1;
			g_vbl_time = 0;
			g_cpu_load = 0;
			g_gpu_load = 0;
			g_frame_count = 0;
			performanceCounter = false;
			sceGuShadeModel(GU_SMOOTH);
		}

		void RenderManager::InitDebugFont()
		{
			intraFontInit();

			numFont = intraFontLoad("Assets/Fonts/numerals.pgf",INTRAFONT_CACHE_ASCII);
			engFont = intraFontLoad("Assets/Fonts/eng_letters.pgf",INTRAFONT_CACHE_ASCII);
			rusFont = intraFontLoad("Assets/Fonts/rus_letters.pgf",INTRAFONT_CACHE_ASCII);

			intraFontSetStyle(numFont,0.5f,WHITE,BLACK,INTRAFONT_ALIGN_CENTER);
			intraFontSetStyle(engFont,0.5f,WHITE,BLACK,INTRAFONT_ALIGN_CENTER);
			intraFontSetStyle(rusFont,0.5f,WHITE,BLACK,INTRAFONT_ALIGN_CENTER);

			debugFont = engFont;
		}

		void RenderManager::SetFontStyle(float size, unsigned int color, unsigned int shadowColor, unsigned int options)
		{
		    if(fontType != 0)
		    {
		        if(shadowColor == 999)
                {
                    intraFontSetStyle(debugFont, size, color, 0, options);
                }
                else
                {
                    intraFontSetStyle(debugFont, size, color, BLACK, options);
                }
		    }
		    else
            {
                intraFontSetStyle(debugFont, size, color, shadowColor, options);
            }
		}

        void RenderManager::SetFont(int type)
		{
		    fontType = type;
			switch(type)
			{
			    case 0: debugFont = numFont; fontVerticalShift = 0; break;
			    case 1: debugFont = engFont; fontVerticalShift = -4; break;
			    case 2: debugFont = rusFont; fontVerticalShift = -4; break;
			}
		}

        void RenderManager::SetDefaultFont()
		{
		    SetFont(defaultFontType);
		}


        int RenderManager::GetFontLanguage()
		{
		    return fontType;
		}

		void RenderManager::DebugPrint(int x,int y, const char *message, ...)
		{
			va_list argList;
			char cbuffer[512];
			va_start(argList, message);
			vsnprintf(cbuffer, 512, message, argList);
			va_end(argList);

			sceGuEnable(GU_BLEND);
			sceGuEnable(GU_TEXTURE_2D);

			intraFontPrint(debugFont, x, y+fontVerticalShift, cbuffer);
			sceGuDisable(GU_BLEND);
			sceGuDisable(GU_TEXTURE_2D);
		}

		void RenderManager::Start()
		{
			sceGuStart(GU_DIRECT,list);
		}

		void RenderManager::CleanBuffers()
		{
			sceGuClearColor(cleanColor);
			sceGuClearStencil(0);
			sceGuClearDepth(0);
			sceGuClear(GU_COLOR_BUFFER_BIT | GU_STENCIL_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);
		}

		void RenderManager::StartFrame(float a, float b, float c)
		{
			sceGuStart(GU_DIRECT,list);

            if(a > 1.0f)
            {
                a = 1.0f;
            }
            if(b > 1.0f)
            {
                b = 1.0f;
            }
            if(c > 1.0f)
            {
                c = 1.0f;
            }

            sceGuClearColor(GU_COLOR(a,b,c,1.0));
			sceGuClearStencil(0);
			sceGuClearDepth(0);
			sceGuClear(GU_COLOR_BUFFER_BIT | GU_STENCIL_BUFFER_BIT | GU_DEPTH_BUFFER_BIT);

			//set camera look at -- later maybe i will move this code somewhere else
			if(mCam != NULL)
			{
				sceGumMatrixMode(GU_PROJECTION);
				sceGumLoadIdentity();
				sceGumLoadMatrix(&proj);

				sceGumMatrixMode(GU_VIEW);
				sceGumLoadIdentity();

				ScePspFVector3 pos = {mCam->m_vPosition.x + mCam->m_vOffset.x,mCam->m_vPosition.y + mCam->m_vOffset.y + mCam->bobY,mCam->m_vPosition.z + mCam->m_vOffset.z};
				ScePspFVector3 eye = {mCam->m_vView.x,mCam->m_vView.y,mCam->m_vView.z};
				ScePspFVector3 up = {mCam->m_vUpVector.x,mCam->m_vUpVector.y,mCam->m_vUpVector.z};

				ScePspFVector3 rotVec = { mCam->offAngleX, mCam->offAngleY, mCam->tiltAngle };
				sceGumRotateXYZ(&rotVec);

				sceGumLookAt(&pos, &eye, &up);
				sceGumStoreMatrix(&view);

				sceGumMatrixMode(GU_MODEL);
				sceGumLoadIdentity();

				if(mCam->needUpdate)
				{
					UpdateFrustumMatrix();
					mCam->mFrustum.ExtractPlanes(projection_view_matrix);
					mCam->needUpdate = false;
				}
			}

			sceGuShadeModel(GU_SMOOTH);
		}

		void RenderManager::LookAt()
		{
			//set camera look at -- later maybe i will move this code somewhere else
			if(mCam != NULL)
			{
				sceGumMatrixMode(GU_PROJECTION);
				sceGumLoadIdentity();
				sceGumLoadMatrix(&proj);

				sceGumMatrixMode(GU_VIEW);
				sceGumLoadIdentity();

				ScePspFVector3 pos = {mCam->m_vPosition.x + mCam->m_vOffset.x,mCam->m_vPosition.y + mCam->m_vOffset.y,mCam->m_vPosition.z + mCam->m_vOffset.z};
				ScePspFVector3 eye = {mCam->m_vView.x,mCam->m_vView.y,mCam->m_vView.z};
				ScePspFVector3 up = {mCam->m_vUpVector.x,mCam->m_vUpVector.y,mCam->m_vUpVector.z};

				sceGumLookAt(&pos, &eye, &up);
				sceGumUpdateMatrix();

				sceGumStoreMatrix(&view);

				sceGumMatrixMode(GU_MODEL);
				sceGumLoadIdentity();

				if(mCam->needUpdate)
				{
					UpdateFrustumMatrix();
					mCam->mFrustum.ExtractPlanes(projection_view_matrix);
					mCam->needUpdate = false;
				}
			}
		}

		void RenderManager::EndFrame()
		{
			if(!performanceCounter)
			{
				sceGuFinish();
				sceGuSync(0,0);

				sceDisplayWaitVblankStart();
				sceGuSwapBuffers();
			}else
			{
				sceGuFinish();
				int cpu_time = sceKernelGetSystemTimeLow();
				sceGuSync(0,0);
				int gpu_time = sceKernelGetSystemTimeLow();
				sceDisplayWaitVblankStart();
				sceGuSwapBuffers();

				g_frame_count ++ ;

				//performance
				int vbl_time = sceKernelGetSystemTimeLow();
				int vbl_count = sceDisplayGetVcount();

				if ( g_vbl_count >= 0 )
				{
					g_vbl_step = vbl_count - g_vbl_count ;
					if ( g_frame_count % 6 == 0 )
					{
						g_cpu_load = ( cpu_time - g_vbl_time ) * 100 / 16667 ;
						g_gpu_load = ( gpu_time - g_vbl_time ) * 100 / 16667 ;
					}
				}
				g_vbl_time = vbl_time ;
				g_vbl_count = vbl_count ;
			}
		}

		void RenderManager::StartDialog()
		{
			sceGuStart(GU_DIRECT,list);
			sceGuClear(GU_COLOR_BUFFER_BIT|GU_DEPTH_BUFFER_BIT);
			sceGuFinish();
			sceGuSync(0,0);
		}

		void RenderManager::EndDialog()
		{
			sceDisplayWaitVblankStart();
			sceGuSwapBuffers();
		}
		
		void RenderManager::UseVerticalSync(bool Enabled)
		{
			mVerticalSync = Enabled;
		}

		void RenderManager::SetClearColor(float r,float g,float b,float a)
		{
			cleanColor = GU_COLOR(r,g,b,a);
			//GU_RGBA();
		}

		void RenderManager::SetOrtho(float left, float right, float bottom, float top, float zNear, float zFar)
		{
			//some lame stuff XD
			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();
			sceGumOrtho(0, 480, 272, 0, -30, 30);

			sceGumMatrixMode(GU_VIEW);
			sceGumLoadIdentity();

			sceGumMatrixMode(GU_MODEL);
			sceGumLoadIdentity();
		}

        void RenderManager::SetOrtho2(float left, float right, float bottom, float top, float zNear, float zFar)
		{
			//some lame stuff XD
			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();
			sceGumOrtho(-1024, 1024, -1024, 1024, -1024, 1024);

			sceGumMatrixMode(GU_VIEW);
			sceGumLoadIdentity();

			sceGumMatrixMode(GU_MODEL);
			sceGumLoadIdentity();
		}

		void RenderManager::SetPerspective(float _fov,float _aspect,float _znear,float _zfar)
		{
			fov = _fov;
			aspect = _aspect;
			znear = _znear;
			zfar = _zfar;

			sceGumMatrixMode(GU_PROJECTION);
			sceGumLoadIdentity();

			sceGumPerspective(fovv,aspect,znear,zfar);
			sceGumStoreMatrix(&proj);

			sceGumMatrixMode(GU_VIEW);
			sceGumLoadIdentity();

			sceGumStoreMatrix(&view);

			sceGumMatrixMode(GU_MODEL);
			sceGumLoadIdentity();
		}



		void  RenderManager::DrawToTexture(Texture* offscreenTexture )
		{
			//draw to texture
			sceGuDrawBufferList(GU_PSM_8888,(void*)offscreenTexture->data,offscreenTexture->width);

			// setup viewport
			sceGuOffset(2048 - (offscreenTexture->width/2),2048 - (offscreenTexture->height/2));
			sceGuViewport(2048,2048,offscreenTexture->width,offscreenTexture->height);

			//CleanBuffers();
		}

		void RenderManager::SetRTT()
		{
			// set frame buffer
			sceGuDrawBufferList(GU_PSM_8888,SCEGU_VRAM_BP32_0,BUF_WIDTH);

			// setup viewport
			sceGuOffset(2048 - (SCR_WIDTH/2),2048 - (SCR_HEIGHT/2));
			sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);

			CleanBuffers();
		}


		void RenderManager::SetActiveCamera(Camera *camera)
		{
			mCam = camera;
			mCam->needUpdate = true;
		}

		void RenderManager::UpdateFrustumMatrix()
		{
			gumMultMatrix(&projection_view_matrix,&proj,&view);
		}

		void RenderManager::SetClearColour(unsigned int color)
		{
			cleanColor = color;
		}
		
		RenderManager g_RenderManager;
	}
}

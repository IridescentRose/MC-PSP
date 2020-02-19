#include <Shadow/Graphics/RenderManager.h>

namespace Shadow
{
	namespace Graphics
	{

        void RenderManager::DrawCube(float x, float y, float z)
        {
        }

		void RenderManager::Init()
		{

			_fbp0 = getStaticVramBuffer(BUF_WIDTH, SCR_HEIGHT, GU_PSM_8888);
			_fbp1 = getStaticVramBuffer(BUF_WIDTH, SCR_HEIGHT, GU_PSM_8888);
			_zbp = getStaticVramBuffer(BUF_WIDTH, SCR_HEIGHT, GU_PSM_4444);

		    fontVerticalShift = 3;
		    fontType = 0;
		    defaultFontType = 1;

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


            sceGuDrawBuffer( GU_PSM_8888, _fbp0, BUF_WIDTH );
			sceGuDispBuffer( SCR_WIDTH, SCR_HEIGHT, _fbp1, BUF_WIDTH);
			sceGuDepthBuffer( _zbp, BUF_WIDTH);

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
			defFont = intraFontLoad("./assets/font/font.pgf", INTRAFONT_STRING_UTF8 | INTRAFONT_CACHE_LARGE);
			debugFont = intraFontLoad("./assets/font/ltn8.pgf",INTRAFONT_STRING_UTF8|INTRAFONT_CACHE_LARGE);	
			jpn0 = intraFontLoad("./assets/font/jpn0.pgf",INTRAFONT_STRING_UTF8|INTRAFONT_CACHE_LARGE);
  			kr0 = intraFontLoad("./assets/font/kr0.pgf",INTRAFONT_STRING_UTF8|INTRAFONT_CACHE_LARGE);  //Korean font (not available on all systems) with UTF-8 encoding
			arib = intraFontLoad("./assets/font/arib.pgf",INTRAFONT_STRING_UTF8|INTRAFONT_CACHE_LARGE);                     //Symbols (not available on all systems)
  			chn = intraFontLoad("./assets/font/gb3s1518.bwfon",INTRAFONT_STRING_UTF8|INTRAFONT_CACHE_LARGE);               //chinese font
 			
			intraFontSetStyle(debugFont,0.5f,0xFFFFFFFF,0, 0.0f, INTRAFONT_ALIGN_CENTER);
			intraFontSetStyle(jpn0,0.5f,0xFFFFFFFF,0, 0.0f, INTRAFONT_ALIGN_CENTER);
			intraFontSetStyle(kr0,0.5f,0xFFFFFFFF,0, 0.0f, INTRAFONT_ALIGN_CENTER); 
			intraFontSetStyle(chn,0.5f,0xFFFFFFFF,0, 0.0f, INTRAFONT_ALIGN_CENTER);
			intraFontSetStyle(arib,0.5f,0xFFFFFFFF,0, 0.0f, INTRAFONT_ALIGN_CENTER);
			intraFontSetStyle(defFont,0.25f,0xFFFFFFFF,0, 0.0f, INTRAFONT_ALIGN_CENTER);
			 
			intraFontSetAltFont(defFont, debugFont);
			intraFontSetAltFont(debugFont,jpn0);                     //japanese font is used for chars that don't exist in latin
  			intraFontSetAltFont(jpn0,chn);                        //chinese font (bwfon) is used for chars that don't exist in japanese (and latin)
  			intraFontSetAltFont(chn,kr0);                         //korean font is used for chars that don't exist in chinese (and jap and ltn)
  			intraFontSetAltFont(kr0,arib);                        //symbol font is used for chars that don't exist in korean (and chn,jap & ltn)
			
		}

		void RenderManager::SetFontStyle(float size, unsigned int color, unsigned int shadowColor, unsigned int options, float angle)
		{
			float size2 = size * 0.5f;
					sceGuDisable(GU_BLEND);
		sceGuEnable(GU_DEPTH_TEST);
            intraFontSetStyle(defFont, size2, color, shadowColor, angle, options);
			
            intraFontSetStyle(debugFont, size2, color, shadowColor, angle, options);
            intraFontSetStyle(jpn0, size2, color, shadowColor, angle, options);
            intraFontSetStyle(kr0, size2, color, shadowColor, angle, options);
            intraFontSetStyle(chn, size2, color, shadowColor, angle, options);
            intraFontSetStyle(arib, size2, color, shadowColor, angle, options);
            

		sceGuDisable(GU_DEPTH_TEST);
		sceGuEnable(GU_BLEND);
		sceGuColor(GU_COLOR(1,1,1,1.0f));

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

			intraFontPrint(defFont, x, y+fontVerticalShift, cbuffer);
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

			
			sceGuShadeModel(GU_SMOOTH);
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

		void RenderManager::SetOrtho()
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
			sceGuDrawBufferList(GU_PSM_8888,_fbp0,BUF_WIDTH);

			// setup viewport
			sceGuOffset(2048 - (SCR_WIDTH/2),2048 - (SCR_HEIGHT/2));
			sceGuViewport(2048,2048,SCR_WIDTH,SCR_HEIGHT);

			CleanBuffers();
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

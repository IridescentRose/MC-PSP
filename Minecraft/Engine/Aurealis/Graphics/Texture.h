#pragma once
#include <string>
#include <stdlib.h>
#include <malloc.h>
#include <png.h>
#include <pspdebug.h>
#include <pspgu.h>
#include <pspgum.h>
#include <psputils.h>
#include <pspdisplay.h>

class Texture {
public:
	int width, height, pWidth, pHeight, ramSpace, colorMode, swizzled;

	unsigned int texID;

	std::string fileName;

	unsigned short* data; //32 bit pixel data in (likely) 8888 RGBA

	inline void bindTexture(int minFilter = GU_LINEAR, int maxFilter = GU_LINEAR, bool modulate = false) {
		if (modulate) {
			sceGuTexMode(colorMode, 0, 0, swizzled);
			sceGuTexFunc(GU_TFX_MODULATE, GU_TCC_RGBA);
			sceGuTexFilter(minFilter, maxFilter);
			sceGuTexOffset(0.0f, 0.0f);
			sceGuTexWrap(GU_CLAMP, GU_CLAMP);
			sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		}
		else {
			sceGuTexMode(colorMode, 0, 0, 1);
			sceGuTexFunc(GU_TFX_REPLACE, GU_TCC_RGBA);
			sceGuTexFilter(minFilter, maxFilter);
			sceGuTexOffset(0.0f, 0.0f);
			sceGuTexWrap(GU_REPEAT, GU_REPEAT);
			sceGuTexImage(0, pWidth, pHeight, pWidth, data);
		}
	}


	~Texture()
	{
		if (data != NULL)
			free(data);
	}
};

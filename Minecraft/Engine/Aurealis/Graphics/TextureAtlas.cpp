#include "TextureAtlas.h"
#include <cmath>

TextureAtlas::TextureAtlas(int imageSize, int textureSize)
{
	m_imageSize = imageSize;
	m_texSize = textureSize;
}

TextureCoords TextureAtlas::getTexture(int id)
{

	static const float TEX_PER_ROW = 16.0f;
	static const float INDV_TEX_SIZE = 1.0f / TEX_PER_ROW;
	static const float PIXEL_SIZE = 1.0f / 16.0f;

	long coordX = id % 16;
	long coordY = (int)floor(((float)id / 16.f));
	
	float xMin = (coordX * INDV_TEX_SIZE);
	float yMin = (coordY * INDV_TEX_SIZE);

	float xMax = (xMin + INDV_TEX_SIZE);
	float yMax = (yMin + INDV_TEX_SIZE);

	TextureCoords coords;
	coords.coord[0] = xMin;
	coords.coord[1] = yMin;
	coords.coord[4] = xMax;
	coords.coord[5] = yMin;
	coords.coord[2] = xMin;
	coords.coord[3] = yMax;
	coords.coord[6] = xMax;
	coords.coord[7] = yMax;

	return coords;
}

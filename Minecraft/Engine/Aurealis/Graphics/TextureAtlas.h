#pragma once

struct TextureCoords {
	float coord[8];
};

class TextureAtlas {
public:
	TextureAtlas(int imageSize, int textureSize);
	TextureCoords getTexture(int id);

private:
	int m_imageSize;
	int m_texSize;
};
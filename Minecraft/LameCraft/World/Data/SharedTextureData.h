#pragma once
#include <Aurealis/Graphics/TextureUtil.h>

class SharedTextureData {
public:

	SharedTextureData();

	std::string texturePackName;

	void Init();
	void Cleanup();
	Texture* buttons;
	Texture* Utils;
	Texture* Terrain1;
	Texture* Terrain2;
	Texture* WaterAnimation;
	Texture* LavaAnimation;
	Texture* Items1;
	Texture* Blue;
	Texture* Sun;
	Texture* Moon;
	Texture* Stars;
	Texture* SnowBall3;
	Texture* zombieTexture;
	Texture* Steve;
	Texture* Red;
	Texture* Black;
	Texture* PumpkinMask;
	Texture* clouds1;
	Texture* inv;
	Texture* invCreative;
	Texture* crt;
	Texture* cht;
	Texture* fur;
	Texture* cursor;
	Texture* invSlider;
	Texture* furFire;
	Texture* furArrow;
	Texture* invCell;
	Texture* leatherArmor1;
	Texture* leatherArmor2;
	Texture* chainmailArmor1;
	Texture* chainmailArmor2;
	Texture* ironArmor1;
	Texture* ironArmor2;
	Texture* diamondArmor1;
	Texture* diamondArmor2;
	Texture* goldenArmor1;
	Texture* goldenArmor2;
	Texture* cowTexture;
	Texture* smokeTexture;
	Texture* flameTexture;
	Texture* noteTexture;
	Texture* bubbleTexture;
	Texture* explosionTexture;
	Texture* vegetationColorMap;
	Texture* clockTexture;
	Texture* compassTexture;
	Texture* skyColorTexture;
	Texture* rainTexture;
	Texture* snowTexture;
	Texture* creeperTexture;
	Texture* sheepTexture;
	Texture* sheepFurTexture;
};

extern SharedTextureData g_TextureData;
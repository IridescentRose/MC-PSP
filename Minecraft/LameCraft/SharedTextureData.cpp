#include "SharedTextureData.h"
#include <pspkernel.h>
SharedTextureData g_TextureData;

SharedTextureData::SharedTextureData()
{
	texturePackName = "Default";
}

void SharedTextureData::Init()
{
	buttons = TextureUtil::LoadPngTexturePack(texturePackName, "title/menu_elements.png");
	
	Utils = TextureUtil::LoadPngTexturePack(texturePackName, "hud/utils.png");
	Terrain1 = TextureUtil::LoadPngTexturePack(texturePackName, "terrain.png");
	Terrain2 = TextureUtil::LoadPngTexturePack(texturePackName, "terrain_mips.png");
	WaterAnimation = TextureUtil::LoadPngTexturePack(texturePackName, "water_still.png");
	LavaAnimation = TextureUtil::LoadPngTexturePack(texturePackName, "lava_still.png");
	Items1 = TextureUtil::LoadPngTexturePack(texturePackName, "items.png");
	
	Blue = TextureUtil::LoadPngTexturePack(texturePackName, "hud/blue.png");
	Sun = TextureUtil::LoadPngTexturePack(texturePackName, "environment/sun.png");
	Moon = TextureUtil::LoadPngTexturePack(texturePackName, "environment/moon.png");
	Stars = TextureUtil::LoadPngTexturePack(texturePackName, "environment/stars.png");
	SnowBall3 = TextureUtil::LoadPngTexturePack(texturePackName, "entity/snowball.png");
	
	zombieTexture = TextureUtil::LoadPngTexturePack(texturePackName, "entity/zombie.png");
	Steve = TextureUtil::LoadPngTexturePack(texturePackName, "entity/steve.png");
	Red = TextureUtil::LoadPngTexturePack(texturePackName, "hud/red.png");
	Black = TextureUtil::LoadPngTexturePack(texturePackName, "hud/black.png");
	
	PumpkinMask = TextureUtil::LoadPngTexturePack(texturePackName, "hud/pumpkinblur.png");
	clouds1 = TextureUtil::LoadPngTexturePack(texturePackName, "environment/clouds.png");
	inv = TextureUtil::LoadPngTexturePack(texturePackName, "gui/inventory1.png");
	invCreative = TextureUtil::LoadPngTexturePack(texturePackName, "gui/inventory_creative.png");
	crt = TextureUtil::LoadPngTexturePack(texturePackName, "gui/crafting_table.png");
	cht = TextureUtil::LoadPngTexturePack(texturePackName, "gui/chest.png");
	fur = TextureUtil::LoadPngTexturePack(texturePackName, "gui/furnace.png");
	cursor = TextureUtil::LoadPngTexturePack(texturePackName, "gui/cursor.png");
	invSlider = TextureUtil::LoadPngTexturePack(texturePackName, "gui/slider.png");
	furFire = TextureUtil::LoadPngTexturePack(texturePackName, "gui/fire.png");
	furArrow = TextureUtil::LoadPngTexturePack(texturePackName, "gui/arrow.png");
	invCell = TextureUtil::LoadPngTexturePack(texturePackName, "gui/cell.png");
	leatherArmor1 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/cloth_1.png");
	leatherArmor2 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/cloth_2.png");
	chainmailArmor1 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/chain_1.png");
	chainmailArmor2 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/chain_2.png");
	ironArmor1 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/iron_1.png");
	ironArmor2 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/iron_2.png");
	
	diamondArmor1 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/diamond_1.png");
	diamondArmor2 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/diamond_2.png");
	goldenArmor1 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/gold_1.png");
	goldenArmor2 = TextureUtil::LoadPngTexturePack(texturePackName, "armor/gold_2.png");
	cowTexture = TextureUtil::LoadPngTexturePack(texturePackName, "entity/cow.png");
	smokeTexture = TextureUtil::LoadPngTexturePack(texturePackName, "particle/smoke.png");
	flameTexture = TextureUtil::LoadPngTexturePack(texturePackName, "particle/flame.png");
	noteTexture = TextureUtil::LoadPngTexturePack(texturePackName, "particle/note.png");
	bubbleTexture = flameTexture;
	explosionTexture = TextureUtil::LoadPngTexturePack(texturePackName, "particle/explosion.png");
	vegetationColorMap = TextureUtil::LoadPngTexturePack(texturePackName, "colormap/grass.png");
	clockTexture = TextureUtil::LoadPngTexturePack(texturePackName, "item/clock.png");
	compassTexture = TextureUtil::LoadPngTexturePack(texturePackName, "item/compass.png");
	skyColorTexture = TextureUtil::LoadPngTexturePack(texturePackName, "environment/sky_color.png");
	rainTexture = TextureUtil::LoadPngTexturePack(texturePackName, "environment/rain.png");
	snowTexture = TextureUtil::LoadPngTexturePack(texturePackName, "environment/snow.png");
	creeperTexture = TextureUtil::LoadPngTexturePack(texturePackName, "entity/creeper.png");
	sheepTexture = TextureUtil::LoadPngTexturePack(texturePackName, "entity/sheep.png");
	sheepFurTexture = TextureUtil::LoadPngTexturePack(texturePackName, "entity/sheep_fur.png");
}

void SharedTextureData::Cleanup()
{
	delete Utils;
	delete Terrain1;
	delete Terrain2;
	delete WaterAnimation;
	delete LavaAnimation;
	delete Items1;
	delete Blue;
	delete Sun;
	delete Moon;
	delete Stars;
	delete SnowBall3;
	delete zombieTexture;
	delete Steve;
	delete Red;
	delete Black;
	delete PumpkinMask;
	delete clouds1;
	delete inv;
	delete invCreative;
	delete crt;
	delete cht;
	delete fur;
	delete cursor;
	delete invSlider;
	delete furFire;
	delete furArrow;
	delete invCell;
	delete leatherArmor1;
	delete leatherArmor2;
	delete chainmailArmor1;
	delete chainmailArmor2;
	delete ironArmor1;
	delete ironArmor2;
	delete diamondArmor1;
	delete diamondArmor2;
	delete goldenArmor1;
	delete goldenArmor2;
	delete cowTexture;
	delete smokeTexture;
	delete flameTexture;
	delete noteTexture;
	delete explosionTexture;
	delete vegetationColorMap;
	delete clockTexture;
	delete compassTexture;
	delete skyColorTexture;
	delete rainTexture;
	delete snowTexture;
	delete creeperTexture;
	delete sheepTexture;
	delete sheepFurTexture;
}

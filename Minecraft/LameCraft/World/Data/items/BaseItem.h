#ifndef BASEITEM_H
#define BASEITEM_H

#include <Aurealis/Graphics/Vertex.h>
#include <stdlib.h>
#include <string>

using namespace Aurealis::Graphics;

typedef unsigned short item_t;

class BaseItem
{
public:
	char textureRow;
	char plane;

	short furnItem;
    short durabilityPoints;

	short points;
	short addPoints;
	short add2Points;

	bool terrainTexture;
    bool stackable;

	char itemType; // "D" - default, "T" - tool, "F" - food, "H" - helmet, "C" - chestplate, "L" - leggings, "B" - boots "Y" - dye

	TexturedVertex *vertices;
	TexturedVertex *addVertices;
	TexturedVertex *add2Vertices;

	TexturedVertex *dropVertices;

	BaseItem();
	virtual ~BaseItem();

	static item_t getBaseID();
    std::string name;
};

#endif

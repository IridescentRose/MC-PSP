#ifndef SIMPLEMESHCHUNK_H
#define SIMPLEMESHCHUNK_H

#include "BaseBlock.h"
#include <vector>
#include <string>
#include "Blocks.h"
#include <Aurealis/Utils/Timer.h>
//framework
#include <Aurealis/Math/BoundingBox.h>
#include <Aurealis/Math/Vector2.h>
#include <Aurealis/Graphics/Vertex.h>
#include <cstdlib>

using namespace Aurealis::Math;
using namespace Aurealis::Utils;
using namespace Aurealis::Graphics;

class SimpleMeshChunk
{
public:

	//unsigned short id;
    bool inFrustum;

	unsigned char chunkStartZ;
	unsigned char chunkStartY;
	unsigned char chunkStartX;

	bool periodicallyUpadted;
	bool haveTransparentVerts;

	BoundingBox bBox;

	SimpleMeshChunk();
	SimpleMeshChunk(int _chunkSize);
	~SimpleMeshChunk();

	int trienglesCount;
	int fTrienglesCount;
	bool created;
	bool needUpdate;

	void position(float x,float y,float z, block_t id);
	void textureCoord(float u,float v);
	void triangle(int x,int y,int z);
	void colour(float x,float y,float z);

	void vert(float x,float y,float z,float u,float v,float r,float g,float b, block_t id);

	void end();

	void drawChunk(Vector3 camPos, bool trans);
	void endDrawChunk();
	void reset();

	std::vector<int> oldXZ;

	CraftPSPVertex *meshVertices;
	bool needsRedraw;
	CraftPSPVertex *floraVertices;

private:
    std::vector<CraftPSPVertex> mVertices;
	std::vector<Vector3> mTriangle;

	std::vector<block_t> blockIDs;
	Timer t;
	float elapsed;
};

#endif


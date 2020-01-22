#pragma once

#include <array>
#include <vector>
#include <mclib/common/Vector.h>

namespace std
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

extern int lighting(float time);

namespace Minecraft::Terrain {

	typedef struct
	{
		float u, v;
		unsigned int color;
		float x, y, z;
	}__attribute__((packed)) ChunkVertex16;

	enum FaceTypes{
		TYPE_FRONT,
		TYPE_BACK,
		TYPE_LEFT,
		TYPE_RIGHT,
		TYPE_TOP,
		TYPE_BOTTOM
	};

	class ChunkMesh {
	public:
		ChunkMesh();
		~ChunkMesh();

		void addFace(int faceType, const float blockFace[12], std::array<float, 8> texCoords,
			mc::Vector3i chunkPosition,
			mc::Vector3i blockPosition);

		int faces;

		void clear();

		std::vector<ChunkVertex16> frontVertexData;
		std::vector<ChunkVertex16> backVertexData;
		std::vector<ChunkVertex16> leftVertexData;
		std::vector<ChunkVertex16> rightVertexData;
		std::vector<ChunkVertex16> topVertexData;
		std::vector<ChunkVertex16> bottomVertexData;

		void updateLighting(int level);
	};

	struct ChunkMeshCollection
	{
		ChunkMesh solidMesh;
		ChunkMesh waterMesh;
		ChunkMesh floraMesh;
	};
}
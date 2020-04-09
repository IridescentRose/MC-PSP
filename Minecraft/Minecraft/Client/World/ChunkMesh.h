#pragma once

#include <array>
#include <glm/glm.hpp>
#include <vector>
#include <sstream>

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
			glm::vec3 chunkPosition,
			glm::vec3 blockPosition,
			glm::vec3 colorOffsets);

		int faces;

		void clear();

		std::vector<ChunkVertex16> frontVertexData;
		std::vector<ChunkVertex16> backVertexData;
		std::vector<ChunkVertex16> leftVertexData;
		std::vector<ChunkVertex16> rightVertexData;
		std::vector<ChunkVertex16> topVertexData;
		std::vector<ChunkVertex16> bottomVertexData;

		void updateLighting(int level, int lastLevel);
	};

	struct ChunkMeshCollection
	{
		ChunkMesh solidMesh;
		ChunkMesh waterMesh;
		ChunkMesh floraMesh;
	};
}
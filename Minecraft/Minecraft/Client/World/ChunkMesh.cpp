#include "ChunkMesh.h"
#include <Shadow/Utils/Logger.h>
#include <sstream>
namespace std
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}


using namespace Shadow::Utils;

#define CHUNK_SIZE 16

namespace Minecraft::Terrain {
#include "ChunkMesh.h"

	ChunkMesh::ChunkMesh()
	{
		faces = 0;
		frontVertexData.clear();
		backVertexData.clear();
		leftVertexData.clear();
		rightVertexData.clear();
		topVertexData.clear();
		bottomVertexData.clear();
	}

	ChunkMesh::~ChunkMesh()
	{
	}

	void ChunkMesh::addFace(int faceType, const short blockFace[12], std::array<float, 8> texCoords, mc::Vector3i chunkPosition, mc::Vector3i blockPosition)
	{
		ChunkVertex16 v1, v2, v3, v4, v5, v6;

		v1 = {texCoords[0], texCoords[0], blockFace[0 * 3 + 0] + blockPosition.x, blockFace[0 * 3 + 1] + blockPosition.y, blockFace[0 * 3 + 2] + blockPosition.z};
		v2 = {texCoords[1], texCoords[0], blockFace[1 * 3 + 0] + blockPosition.x, blockFace[1 * 3 + 1] + blockPosition.y, blockFace[1 * 3 + 2] + blockPosition.z};
		v3 = {texCoords[1], texCoords[1], blockFace[2 * 3 + 0] + blockPosition.x, blockFace[2 * 3 + 1] + blockPosition.y, blockFace[2 * 3 + 2] + blockPosition.z};

		v4 = {texCoords[1], texCoords[1], blockFace[2 * 3 + 0] + blockPosition.x, blockFace[2 * 3 + 1] + blockPosition.y, blockFace[2 * 3 + 2] + blockPosition.z};
		v5 = {texCoords[0], texCoords[1], blockFace[3 * 3 + 0] + blockPosition.x, blockFace[3 * 3 + 1] + blockPosition.y, blockFace[3 * 3 + 2] + blockPosition.z};
		v6 = {texCoords[0], texCoords[0], blockFace[0 * 3 + 0] + blockPosition.x, blockFace[0 * 3 + 1] + blockPosition.y, blockFace[0 * 3 + 2] + blockPosition.z};
		
		switch(faceType){
			case TYPE_TOP:{
				topVertexData.push_back(v1);
				topVertexData.push_back(v2);
				topVertexData.push_back(v3);
				topVertexData.push_back(v4);
				topVertexData.push_back(v5);
				topVertexData.push_back(v6);
				break;
			}

			case TYPE_BOTTOM:{
				bottomVertexData.push_back(v1);
				bottomVertexData.push_back(v2);
				bottomVertexData.push_back(v3);
				bottomVertexData.push_back(v4);
				bottomVertexData.push_back(v5);
				bottomVertexData.push_back(v6);
				break;
			}

			case TYPE_FRONT:{
				frontVertexData.push_back(v1);
				frontVertexData.push_back(v2);
				frontVertexData.push_back(v3);
				frontVertexData.push_back(v4);
				frontVertexData.push_back(v5);
				frontVertexData.push_back(v6);
				break;
			}


			case TYPE_BACK:{
				backVertexData.push_back(v1);
				backVertexData.push_back(v2);
				backVertexData.push_back(v3);
				backVertexData.push_back(v4);
				backVertexData.push_back(v5);
				backVertexData.push_back(v6);
				break;
			}

			case TYPE_LEFT:{
				leftVertexData.push_back(v1);
				leftVertexData.push_back(v2);
				leftVertexData.push_back(v3);
				leftVertexData.push_back(v4);
				leftVertexData.push_back(v5);
				leftVertexData.push_back(v6);
				break;
			}

			case TYPE_RIGHT:{
				rightVertexData.push_back(v1);
				rightVertexData.push_back(v2);
				rightVertexData.push_back(v3);
				rightVertexData.push_back(v4);
				rightVertexData.push_back(v5);
				rightVertexData.push_back(v6);
				break;
			}
		}
		
	}
}
#include <map>
#include "Chunk.h"

//TODO: TERRAIN GEN

namespace Minecraft{
    namespace Terrain{
        using ChunkMap = std::map<mc::Vector3i, Chunk*>;
        class ChunkManager
        {
            public:
                ChunkManager();

                Chunk*      getChunk    (int x, int y, int z);
                ChunkMap&   getChunks   ();

                bool chunkExists(int x, int y, int z);

                void loadChunk(int x, int y, int z);
                void unloadChunk(int x, int y, int z);
        };
        extern ChunkMap m_chunks;
    }
}
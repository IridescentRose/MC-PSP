#include "ChunkManager.h"

namespace Minecraft::Terrain{
    ChunkMap m_chunks;
    ChunkManager::ChunkManager(){
        m_chunks.clear();
    }

    Chunk* ChunkManager::getChunk(int x, int y, int z){
        if (!chunkExists(x, y, z)){
            return NULL;
        }
        return m_chunks[mc::Vector3i(x, y, z)];
    }
    ChunkMap& ChunkManager::getChunks(){
        return m_chunks;
    }

    bool ChunkManager::chunkExists(int x, int y, int z){
        return m_chunks.find(mc::Vector3i(x, y, z)) != m_chunks.end();
    }

    void ChunkManager::loadChunk(int x, int y, int z){
        Chunk* c = new Chunk();
        c->chunk_x = x;
        c->chunk_y = y;
        c->chunk_z = z;

        c->generateData();
        c->generateMesh();

        m_chunks.emplace(mc::Vector3i(x, y, z), std::move(c));
    }
    
    void ChunkManager::unloadChunk(int x, int y, int z){
        if(chunkExists(x, y, z)){
            delete m_chunks[mc::Vector3i(x, y, z)]; //Safety
            m_chunks.erase(mc::Vector3i(x, y, z));
        }
    }
}
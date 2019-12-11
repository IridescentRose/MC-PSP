#include <mclib/world/World.h>

namespace mc {
namespace world {

World::World()
{
}

World::~World() {
}

bool World::SetBlock(Vector3i position, s16 blockData) {
    ChunkColumnPtr chunk = GetChunk(position);
    if (!chunk) return false;

    Vector3i relative(position);

    relative.x %= 16;
    relative.z %= 16;

    if (relative.x < 0)
        relative.x += 16;
    if (relative.z < 0)
        relative.z += 16;

    std::size_t index = (std::size_t)position.y / 16;
    if ((*chunk)[index] == nullptr) {
        ChunkPtr section = std::make_shared<Chunk>();

        (*chunk)[index] = section;
    }

    relative.y %= 16;
    (*chunk)[index]->SetBlock(relative, block::BlockState(block::BlockRegistry::GetInstance()->GetBlock(blockData), blockData, position));
    return true;
}

ChunkColumnPtr World::GetChunk(Vector3i pos) const {
    s32 x = (s32)std::floor(pos.x / 16.0);
    s32 z = (s32)std::floor(pos.z / 16.0);

    ChunkCoord key(x, z);

    auto iter = m_Chunks.find(key);

    if (iter == m_Chunks.end()) return nullptr;

    return iter->second;
}

block::BlockState World::GetBlock(Vector3f pos) const {
    return GetBlock(Vector3i((s64)std::floor(pos.x), (s64)std::floor(pos.y), (s64)std::floor(pos.z)));
}

block::BlockState World::GetBlock(Vector3d pos) const {
    return GetBlock(Vector3i((s64)std::floor(pos.x), (s64)std::floor(pos.y), (s64)std::floor(pos.z)));
}

block::BlockState World::GetBlock(Vector3i pos) const {
    ChunkColumnPtr col = GetChunk(pos);

    if (!col) return block::BlockState(nullptr, 0, pos);

    s64 x = pos.x % 16;
    s64 z = pos.z % 16;

    if (x < 0)
        x += 16;
    if (z < 0)
        z += 16;

    block::BlockState state = col->GetBlock(Vector3i(x, pos.y, z));

    return block::BlockState(state.GetBlock(), state.GetData(), pos);
}

block::BlockEntityPtr World::GetBlockEntity(Vector3i pos) const {
    ChunkColumnPtr col = GetChunk(pos);

    if (!col) return nullptr;

    return col->GetBlockEntity(pos);
}

std::vector<block::BlockEntityPtr> World::GetBlockEntities() const {
    std::vector<block::BlockEntityPtr> blockEntities;

    for (auto iter = m_Chunks.begin(); iter != m_Chunks.end(); ++iter) {
        if (iter->second == nullptr) continue;
        std::vector<block::BlockEntityPtr> chunkBlockEntities = iter->second->GetBlockEntities();
        if (chunkBlockEntities.empty()) continue;
        blockEntities.insert(blockEntities.end(), chunkBlockEntities.begin(), chunkBlockEntities.end());
    }

    return blockEntities;
}

} // ns world
} // ns mc

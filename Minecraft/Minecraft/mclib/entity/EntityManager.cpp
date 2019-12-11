#include <mclib/entity/EntityManager.h>

#include <mclib/entity/Painting.h>
#include <mclib/entity/XPOrb.h>

#include <unordered_map>
#include <algorithm>
#include <iostream>

// todo: Use factories to create the entities

#define TAU 3.14159f * 2.0f
#define DEG_TO_RAD 3.14159f / 180.0f

namespace mc {
namespace entity {

EntityType GetEntityTypeFromObjectId(s32 oid) {
    static const std::unordered_map<s32, EntityType> mapping = {
        { 1, EntityType::Boat },
        { 2, EntityType::Item },
        { 3, EntityType::AreaEffectCloud },
        { 10, EntityType::MinecartRideable },
        { 50, EntityType::PrimedTnt },
        { 51, EntityType::EnderCrystal },
        { 60, EntityType::Arrow },
        { 61, EntityType::Snowball },
        { 62, EntityType::ThrownEgg },
        { 63, EntityType::Fireball },
        { 64, EntityType::SmallFireball },
        { 65, EntityType::ThrownEnderpearl },
        { 66, EntityType::WitherSkull },
        { 67, EntityType::ShulkerBullet },
        { 68, EntityType::LlamaSpit },
        { 70, EntityType::FallingObject },
        { 71, EntityType::ItemFrame },
        { 72, EntityType::EyeOfEnderSignal },
        { 73, EntityType::ThrownPotion },
        { 75, EntityType::ThrownExpBottle },
        { 76, EntityType::FireworksRocketEntity },
        { 77, EntityType::LeashKnot },
        { 78, EntityType::ArmorStand },
        { 79, EntityType::EvocationFangs },
        { 90, EntityType::FishingHook },
        { 91, EntityType::SpectralArrow },
        { 93, EntityType::DragonFireball }
    };

    return mapping.at(oid);
}

EntityManager::EntityManager()
{
    
}

EntityManager::~EntityManager() {
    
}


} // ns entity
} // ns mc

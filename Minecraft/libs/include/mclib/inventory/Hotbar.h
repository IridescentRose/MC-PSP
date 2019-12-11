#ifndef MCLIB_INVENTORY_HOTBAR_H_
#define MCLIB_INVENTORY_HOTBAR_H_

#include <mclib/inventory/Slot.h>

namespace mc {
namespace inventory {

class InventoryManager;

class Hotbar {
private:
    InventoryManager* m_InventoryManager;
    s32 m_SelectedSlot;

public:
    MCLIB_API Hotbar(InventoryManager* inventoryManager);
    MCLIB_API ~Hotbar();

    Hotbar(const Hotbar& rhs) = delete;
    Hotbar& operator=(const Hotbar& rhs) = delete;
    Hotbar(Hotbar&& rhs) = delete;
    Hotbar& operator=(Hotbar&& rhs) = delete;

    MCLIB_API void HandlePacket();

    // Sends a packet telling the server that the client is changing slots.
    // Slot should be between 0 and 8.
    MCLIB_API void SelectSlot(s32 hotbarIndex);
    MCLIB_API s32 GetSelectedSlot() const noexcept { return m_SelectedSlot; }

    MCLIB_API Slot GetCurrentItem();
    // Index should be between 0 and 8.
    MCLIB_API Slot GetItem(s32 hotbarIndex);
};

} // ns inventory
} // ns mc

#endif

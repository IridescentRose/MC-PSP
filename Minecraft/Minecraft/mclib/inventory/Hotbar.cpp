#include <mclib/inventory/Hotbar.h>

#include <mclib/inventory/Inventory.h>
#include <mclib/protocol/packets/PacketDispatcher.h>

namespace mc {
namespace inventory {

Hotbar::Hotbar(InventoryManager* inventoryManager):
      m_InventoryManager(inventoryManager), 
      m_SelectedSlot(0)
{
}

Hotbar::~Hotbar() {
}

void Hotbar::SelectSlot(s32 hotbarIndex) {
    m_SelectedSlot = hotbarIndex;

}

Slot Hotbar::GetCurrentItem() {
    return GetItem(m_SelectedSlot);
}

Slot Hotbar::GetItem(s32 hotbarIndex) {
    Inventory* inventory = m_InventoryManager->GetPlayerInventory();
    if (inventory == nullptr) return Slot();

    return inventory->GetItem(Inventory::HOTBAR_SLOT_START + hotbarIndex);
}

} // ns inventory
} // ns mc

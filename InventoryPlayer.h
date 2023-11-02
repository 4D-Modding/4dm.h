#pragma once

#include "4dm.h"

namespace fdm 
{
	class InventoryPlayer : public Inventory 
	{
	public:
		Inventory* hotbar; // 0x30
		Inventory* inventory; // 0x38

		bool addItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryPlayer* self, std::unique_ptr<Item>& item)>(FUNC_INVENTORYPLAYER_ADDITEM)(this, item);
		}
		Inventory::iterator begin() override
		{
			iterator result;
			return reinterpret_cast<Inventory::iterator (__thiscall*)(InventoryPlayer* self, Inventory::iterator* result)>(FUNC_INVENTORYPLAYER_BEGIN)(this, &result);
			return result;
		}
		void render(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<void (__thiscall*)(InventoryPlayer* self, const glm::ivec2& cursorPos)>(FUNC_INVENTORYPLAYER_RENDER)(this, cursorPos);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryPlayer* self, std::unique_ptr<Item>& item)>(FUNC_INVENTORYPLAYER_COMBINEITEM)(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryPlayer* self, std::unique_ptr<Item>& item)>(FUNC_INVENTORYPLAYER_PLACEITEM)(this, item);
		}
		int getSlotIndex(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<int (__thiscall*)(InventoryPlayer* self, const glm::ivec2& cursorPos)>(FUNC_INVENTORYPLAYER_GETSLOTINDEX)(this, cursorPos);
		}
		uint32_t getSlotCount() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(InventoryPlayer* self)>(FUNC_INVENTORYPLAYER_GETSLOTCOUNT)(this);
		}
		std::unique_ptr<Item>* getSlot(int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item>* (__thiscall*)(InventoryPlayer* self, uint32_t index)>(FUNC_INVENTORYPLAYER_GETSLOT)(this, index);
		}
		Inventory::iterator end() override
		{
			iterator result;
			return reinterpret_cast<Inventory::iterator (__thiscall*)(InventoryPlayer* self, Inventory::iterator* result)>(FUNC_INVENTORYPLAYER_END)(this, &result);
			return result;
		}
	};
}

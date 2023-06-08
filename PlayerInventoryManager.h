#pragma once
#ifndef PIM_H
#define PIM_H
#include "4dm.h"
#include "InventoryManager.h"
namespace fdm
{
	class InventoryManager;
	class Item;
	class InventoryCursor;
	class PlayerInventoryManager : public InventoryManager
	{
	public:
		InventoryManager* hotbar;
		InventoryManager* inventory;
		iterator begin() override
		{
			iterator* result = new iterator();
			return reinterpret_cast<iterator(__thiscall*)(PlayerInventoryManager*, iterator*)>(
				FUNC_PLAYERINVENTORYMANAGER_BEGIN
				)(this, result);
		}
		void render(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<void(__thiscall*)(PlayerInventoryManager*, const glm::ivec2&)>(
				FUNC_PLAYERINVENTORYMANAGER_RENDER
				)(this, cursorPos);
		}
		bool addItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, std::unique_ptr<Item>&)>(
				FUNC_PLAYERINVENTORYMANAGER_ADDITEM
				)(this, item);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, std::unique_ptr<Item>&)>(
				FUNC_PLAYERINVENTORYMANAGER_COMBINEITEM
				)(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, std::unique_ptr<Item>&)>(
				FUNC_PLAYERINVENTORYMANAGER_PLACEITEM
				)(this, item);
		}
		bool mouseButtonEvent(InventoryManager* other, InventoryCursor* cursor, int button, int action, char mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, InventoryManager*, InventoryCursor*, int, int, char)>(
				FUNC_PLAYERINVENTORYMANAGER_MOUSEBUTTONEVENT
				)(this, other, cursor, button, action, mods);
		}
		iterator end(void) override
		{
			iterator* result = new iterator();
			return reinterpret_cast<iterator(__thiscall*)(PlayerInventoryManager*, iterator*)>(
				FUNC_PLAYERINVENTORYMANAGER_END
				)(this, result);
		}
		int getSlotCount(void) override
		{
			return reinterpret_cast<int(__thiscall*)(PlayerInventoryManager*)>(
				FUNC_PLAYERINVENTORYMANAGER_GETSLOTCOUNT
				)(this);
		}
		std::unique_ptr<Item>* getSlot(unsigned int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item>*(__thiscall*)(PlayerInventoryManager*, unsigned int)>(
				FUNC_PLAYERINVENTORYMANAGER_GETSLOT
				)(this, index);
		}
	};
}
#endif
#pragma once
#ifndef PIM_H
#define PIM_H
#include "4dm.h"
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
		InventoryManager::iterator begin(void) override
		{
			InventoryManager::iterator* result = new InventoryManager::iterator();
			return reinterpret_cast<InventoryManager::iterator(__thiscall*)(PlayerInventoryManager*, InventoryManager::iterator*)>(
				base + idaOffsetFix(0x66E10)
				)(this, result);
		}
		void render(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<void(__thiscall*)(PlayerInventoryManager*, const glm::ivec2&)>(
				base + idaOffsetFix(0x85300)
				)(this, cursorPos);
		}
		bool addItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x66730)
				)(this, item);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x85330)
				)(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x853A0)
				)(this, item);
		}
		bool mouseButtonEvent(InventoryManager* other, InventoryCursor* cursor, int button, int action, char mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(PlayerInventoryManager*, InventoryManager*, InventoryCursor*, int, int, char)>(
				base + idaOffsetFix(0x85410)
				)(this, other, cursor, button, action, mods);
		}
		InventoryManager::iterator end(void) override
		{
			InventoryManager::iterator* result = new InventoryManager::iterator();
			return reinterpret_cast<InventoryManager::iterator(__thiscall*)(PlayerInventoryManager*, InventoryManager::iterator*)>(
				base + idaOffsetFix(0x85490)
				)(this, result);
		}
		int getSlotCount(void) override
		{
			return reinterpret_cast<int(__thiscall*)(PlayerInventoryManager*)>(
				base + idaOffsetFix(0x854E0)
				)(this);
		}
		std::unique_ptr<Item>* getSlot(unsigned int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item>*(__thiscall*)(PlayerInventoryManager*, unsigned int)>(
				base + idaOffsetFix(0x85510)
				)(this, index);
		}
	};
}
#endif
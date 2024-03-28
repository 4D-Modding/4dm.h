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
			return reinterpret_cast<bool (__thiscall*)(InventoryPlayer* self, std::unique_ptr<Item>& item)>(getFuncAddr((int)Func::InventoryPlayer::addItem))(this, item);
		}
		Inventory::iterator begin() override
		{
			iterator result;
			return reinterpret_cast<Inventory::iterator& (__thiscall*)(InventoryPlayer* self, Inventory::iterator* result)>(getFuncAddr((int)Func::InventoryPlayer::begin))(this, &result);
			return result;
		}
		void render(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<void (__thiscall*)(InventoryPlayer* self, const glm::ivec2& cursorPos)>(getFuncAddr((int)Func::InventoryPlayer::render))(this, cursorPos);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryPlayer* self, std::unique_ptr<Item>& item)>(getFuncAddr((int)Func::InventoryPlayer::combineItem))(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryPlayer* self, std::unique_ptr<Item>& item)>(getFuncAddr((int)Func::InventoryPlayer::placeItem))(this, item);
		}
		int getSlotIndex(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<int (__thiscall*)(InventoryPlayer* self, const glm::ivec2& cursorPos)>(getFuncAddr((int)Func::InventoryPlayer::getSlotIndex))(this, cursorPos);
		}
		uint32_t getSlotCount() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(InventoryPlayer* self)>(getFuncAddr((int)Func::InventoryPlayer::getSlotCount))(this);
		}
		std::unique_ptr<Item>* getSlot(int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item>* (__thiscall*)(InventoryPlayer* self, uint32_t index)>(getFuncAddr((int)Func::InventoryPlayer::getSlot))(this, index);
		}
		Inventory::iterator end() override
		{
			iterator result;
			return reinterpret_cast<Inventory::iterator& (__thiscall*)(InventoryPlayer* self, Inventory::iterator* result)>(getFuncAddr((int)Func::InventoryPlayer::end))(this, &result);
			return result;
		}
	};
}

#pragma once
#ifndef INVENTORY_H
#define INVENTORY_H
#include "4dm.h"
#include "InventoryManager.h"
namespace fdm
{
	class InventoryManager;
	class TexRenderer;
	class FontRenderer;
	class Item;
	class InventoryCursor;
	class World;
	class Player;

	class Inventory : public InventoryManager
	{
	public:
		static TexRenderer tr;
		static FontRenderer fr;
		glm::ivec2 renderPos;
		glm::ivec2 size;
		glm::ivec2 selectedSlot;
		std::string label;
		std::vector<Item> slots;

		~Inventory() 
		{
			reinterpret_cast<void(__thiscall*)(Inventory*)>(
				base + idaOffsetFix(0x1B160)
				)(this);
		}
		void renderInit(void) 
		{
			reinterpret_cast<void(__thiscall*)(Inventory*)>(
				base + idaOffsetFix(0x66070)
				)(this);
		}
		void render(const glm::ivec2& cursorPos) override
		{
			reinterpret_cast<void(__thiscall*)(Inventory*, const glm::ivec2&)>(
				base + idaOffsetFix(0x662F0)
				)(this, cursorPos);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x667A0)
				)(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, std::unique_ptr<Item>&)>(
				base + idaOffsetFix(0x66850)
				)(this, item);
		}
		bool mouseButtonEvent(InventoryManager* other, InventoryCursor* cursor, int button, int action, char mods) override 
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, InventoryManager*, InventoryCursor*, int, int, char)>(
				base + idaOffsetFix(0x668A0)
				)(this, other, cursor, button, action, mods);
		}
		void load(const nlohmann::json& j) 
		{
			return reinterpret_cast<void(__thiscall*)(Inventory*, const nlohmann::json&)>(
				base + idaOffsetFix(0x66A90)
				)(this, j);
		}
		nlohmann::json save(void) 
		{
			nlohmann::json* result = new nlohmann::json();
			return reinterpret_cast<nlohmann::json(__thiscall*)(Inventory*, nlohmann::json*)>(
				base + idaOffsetFix(0x66C70)
				)(this, result);
		}
		void clear(void) 
		{
			reinterpret_cast<void(__thiscall*)(Inventory*)>(
				base + idaOffsetFix(0x66DC0)
				)(this);
		}
		InventoryManager::iterator end(void) override
		{
			InventoryManager::iterator* result = new InventoryManager::iterator();
			return reinterpret_cast<InventoryManager::iterator(__thiscall*)(Inventory*, InventoryManager::iterator* result)>(
				base + idaOffsetFix(0x66E20)
				)(this, result);
		}
		int getSlotCount(void) override 
		{
			return reinterpret_cast<int(__thiscall*)(Inventory*)>(
				base + idaOffsetFix(0x66E40)
				)(this);
		}
		std::unique_ptr<Item>* getSlot(unsigned int index) override 
		{
			return reinterpret_cast<std::unique_ptr<Item>*(__thiscall*)(Inventory*, unsigned int)>(
				base + idaOffsetFix(0x66E50)
				)(this, index);
		}
		bool itemAction(World* world, Player* player, int action)
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, class World*, class Player*, int)>(
				base + idaOffsetFix(0x66EA0)
				)(this, world, player, action);
		}
	};
}
#endif
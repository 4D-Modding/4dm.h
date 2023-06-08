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
		//inline static TexRenderer tr;
		//inline static FontRenderer fr;

		inline static TexRenderer getTexRenderer() // tr
		{
			return *(reinterpret_cast<TexRenderer*>((base + 0x1BED70)));
		}
		inline static FontRenderer getFontRenderer() // fr
		{
			return *(reinterpret_cast<FontRenderer*>((base + 0x17BE40)));
		}

		glm::ivec2 renderPos;
		glm::ivec2 size;
		glm::ivec2 selectedSlot;
		std::string label;
		std::vector<std::unique_ptr<Item>> slots;

		~Inventory() 
		{
			reinterpret_cast<void(__thiscall*)(Inventory*)>(
				FUNC_INVENTORY_DINVENTORY
				)(this);
		}
		void renderInit(void) 
		{
			reinterpret_cast<void(__thiscall*)(Inventory*)>(
				FUNC_INVENTORY_RENDERINIT
				)(this);
		}
		void render(const glm::ivec2& cursorPos) override
		{
			reinterpret_cast<void(__thiscall*)(Inventory*, const glm::ivec2&)>(
				FUNC_INVENTORY_RENDER
				)(this, cursorPos);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, std::unique_ptr<Item>&)>(
				FUNC_INVENTORY_COMBINEITEM
				)(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, std::unique_ptr<Item>&)>(
				FUNC_INVENTORY_PLACEITEM
				)(this, item);
		}
		bool mouseButtonEvent(InventoryManager* other, InventoryCursor* cursor, int button, int action, char mods) override 
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, InventoryManager*, InventoryCursor*, int, int, char)>(
				FUNC_INVENTORY_MOUSEBUTTONEVENT
				)(this, other, cursor, button, action, mods);
		}
		void load(const nlohmann::json& j) 
		{
			return reinterpret_cast<void(__thiscall*)(Inventory*, const nlohmann::json&)>(
				FUNC_INVENTORY_LOAD
				)(this, j);
		}
		nlohmann::json save(void) 
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(Inventory*, nlohmann::json*)>(
				FUNC_INVENTORY_SAVE
				)(this, nullptr);
		}
		void clear(void) 
		{
			reinterpret_cast<void(__thiscall*)(Inventory*)>(
				FUNC_INVENTORY_CLEAR
				)(this);
		}
		InventoryManager::iterator end(void) override
		{
			return reinterpret_cast<InventoryManager::iterator(__thiscall*)(Inventory*, InventoryManager::iterator* result)>(
				FUNC_INVENTORY_END
				)(this, nullptr);
		}
		int getSlotCount(void) override 
		{
			return reinterpret_cast<int(__thiscall*)(Inventory*)>(
				FUNC_INVENTORY_GETSLOTCOUNT
				)(this);
		}
		std::unique_ptr<Item>* getSlot(unsigned int index) override 
		{
			return reinterpret_cast<std::unique_ptr<Item>*(__thiscall*)(Inventory*, unsigned int)>(
				FUNC_INVENTORY_GETSLOT
				)(this, index);
		}
		bool itemAction(World* world, Player* player, int action)
		{
			return reinterpret_cast<bool(__thiscall*)(Inventory*, class World*, class Player*, int)>(
				FUNC_INVENTORY_ITEMACTION
				)(this, world, player, action);
		}
	};
}
#endif
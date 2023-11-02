#pragma once

#include "4dm.h"
#include "Inventory.h"
#include "TexRenderer.h"
#include "FontRenderer.h"
#include "Item.h"

namespace fdm 
{
	class Inventory;
	class TexRenderer;
	class FontRenderer;
	class Item;

	class InventoryGrid : public Inventory 
	{
	public:
		inline static TexRenderer* tr = reinterpret_cast<TexRenderer*>((base + 0x2BE5B8));
		inline static FontRenderer* fr = reinterpret_cast<FontRenderer*>((base + 0x279360));
		glm::ivec2 renderPos; // 0x30
		glm::ivec2 size; // 0x38
		int selectedIndex; // 0x40
		PAD(0x4);
		std::string label; // 0x48
		std::vector<std::unique_ptr<Item>> slots; // 0x68

		~InventoryGrid() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGrid* self)>(FUNC_INVENTORYGRID_DESTR_INVENTORYGRID)(this);
		}
		InventoryGrid() {}
		InventoryGrid(const glm::ivec2& size) 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGrid* self, const glm::ivec2& size)>(FUNC_INVENTORYGRID_INVENTORYGRID)(this, size);
		}
		bool addItem(std::unique_ptr<Item>& item) override
		{
			// decompiled from InventoryPlayer loooool. also yea i didnt bother fixing/optimizing it. fuck it. its literally 3:38.
			auto v4 = combineItem(item);
			if (!item.get())
				return v4;
			auto v5 = placeItem(item);
			if (v5)
				return true;
			return v4;
		}
		void render(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<void (__thiscall*)(InventoryGrid* self, const glm::ivec2& cursorPos)>(FUNC_INVENTORYGRID_RENDER)(this, cursorPos);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryGrid* self, std::unique_ptr<Item>& item)>(FUNC_INVENTORYGRID_COMBINEITEM)(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryGrid* self, std::unique_ptr<Item>& item)>(FUNC_INVENTORYGRID_PLACEITEM)(this, item);
		}
		int getSlotIndex(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<int (__thiscall*)(InventoryGrid* self, const glm::ivec2& cursorPos)>(FUNC_INVENTORYGRID_GETSLOTINDEX)(this, cursorPos);
		}
		uint32_t getSlotCount() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(InventoryGrid* self)>(FUNC_INVENTORYGRID_GETSLOTCOUNT)(this);
		}
		std::unique_ptr<Item>* getSlot(int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item>* (__thiscall*)(InventoryGrid* self, int index)>(FUNC_INVENTORYGRID_GETSLOT)(this, index);
		}
		Inventory::iterator begin() override
		{
			// bruh. 3:39 btw
			return Inventory::iterator{ this, 0 };
		}
		Inventory::iterator end() override
		{
			iterator result;
			return reinterpret_cast<Inventory::iterator (__thiscall*)(InventoryGrid* self, Inventory::iterator* result)>(FUNC_INVENTORYGRID_END)(this, &result);
			return result;
		}
		void load(nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryGrid* self, nlohmann::json& j)>(FUNC_INVENTORYGRID_LOAD)(this, j);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(InventoryGrid* self, nlohmann::json* result)>(FUNC_INVENTORYGRID_SAVE)(this, &result);
			return result;
		}
	};
}

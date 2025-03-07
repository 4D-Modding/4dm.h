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
		glm::ivec2 renderPos{ 0 }; // 0x30
		glm::ivec2 size{ 0 }; // 0x38
		int selectedIndex = -1; // 0x40
		PAD(0x4);
		stl::string label = ""; // 0x48
		std::vector<std::unique_ptr<Item>> slots; // 0x68

		~InventoryGrid() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGrid* self)>(getFuncAddr((int)Func::InventoryGrid::destr_InventoryGrid))(this);
		}
		InventoryGrid() {}
		InventoryGrid(const glm::ivec2& size) 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGrid* self, const glm::ivec2& size)>(getFuncAddr((int)Func::InventoryGrid::InventoryGrid))(this, size);
		}
		void copy(const InventoryGrid& other)
		{
			renderPos = other.renderPos;
			size = other.size;
			selectedIndex = other.selectedIndex;
			label = other.label;

			slots.clear();
			slots.reserve(other.slots.size());
			for (auto& itemB : other.slots)
			{
				if (itemB)
				{
					slots.push_back(itemB->clone());
					slots.back()->count = itemB->count;
				}
				else
				{
					slots.push_back(nullptr);
				}
			}
		}
		InventoryGrid(const InventoryGrid& other)
		{
			copy(other);
		}
		InventoryGrid& operator=(const InventoryGrid& other)
		{
			copy(other);
			return *this;
		}
		InventoryGrid(InventoryGrid&& other) noexcept
		{
			copy(other);

			other.renderPos = glm::ivec2{ 0 };
			other.size = glm::ivec2{ 0 };
			other.selectedIndex = -1;
			other.label = "";
			other.slots.clear();
		}
		InventoryGrid& operator=(InventoryGrid&& other) noexcept
		{
			copy(other);

			other.renderPos = glm::ivec2{ 0 };
			other.size = glm::ivec2{ 0 };
			other.selectedIndex = -1;
			other.label = "";
			other.slots.clear();

			return *this;
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
			return reinterpret_cast<void (__thiscall*)(InventoryGrid* self, const glm::ivec2& cursorPos)>(getFuncAddr((int)Func::InventoryGrid::render))(this, cursorPos);
		}
		bool combineItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryGrid* self, std::unique_ptr<Item>& item)>(getFuncAddr((int)Func::InventoryGrid::combineItem))(this, item);
		}
		bool placeItem(std::unique_ptr<Item>& item) override
		{
			return reinterpret_cast<bool (__thiscall*)(InventoryGrid* self, std::unique_ptr<Item>& item)>(getFuncAddr((int)Func::InventoryGrid::placeItem))(this, item);
		}
		int getSlotIndex(const glm::ivec2& cursorPos) override
		{
			return reinterpret_cast<int (__thiscall*)(InventoryGrid* self, const glm::ivec2& cursorPos)>(getFuncAddr((int)Func::InventoryGrid::getSlotIndex))(this, cursorPos);
		}
		uint32_t getSlotCount() override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(InventoryGrid* self)>(getFuncAddr((int)Func::InventoryGrid::getSlotCount))(this);
		}
		std::unique_ptr<Item>* getSlot(int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item>* (__thiscall*)(InventoryGrid* self, int index)>(getFuncAddr((int)Func::InventoryGrid::getSlot))(this, index);
		}
		Inventory::iterator begin() override
		{
			// bruh. 3:39 btw
			return Inventory::iterator{ this, 0 };
		}
		Inventory::iterator end() override
		{
			iterator result;
			return reinterpret_cast<Inventory::iterator& (__thiscall*)(InventoryGrid* self, Inventory::iterator* result)>(getFuncAddr((int)Func::InventoryGrid::end))(this, &result);
			return result;
		}
		void load(const nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryGrid* self, const nlohmann::json& j)>(getFuncAddr((int)Func::InventoryGrid::load))(this, j);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(InventoryGrid* self, nlohmann::json* result)>(getFuncAddr((int)Func::InventoryGrid::save))(this, &result);
			return result;
		}
	};
}

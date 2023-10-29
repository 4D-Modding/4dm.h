#pragma once

#include "4dm.h"

namespace fdm 
{
	class InventoryGrid : public Inventory 
	{
	public:
		inline static constexpr TexRenderer tr = *reinterpret_cast<TexRenderer*>((base + 0x2BE5B8)); 
		inline static constexpr FontRenderer fr = *reinterpret_cast<FontRenderer*>((base + 0x279360)); 
		glm::ivec2 renderPos; // 0x30
		glm::ivec2 size; // 0x38
		int selectedIndex; // 0x40
		PAD(0x4);
		std::string label; // 0x48
		std::vector<std::unique_ptr<Item,std::default_delete<Item> >,std::allocator<std::unique_ptr<Item,std::default_delete<Item> > > > slots; // 0x68

		~InventoryGrid() 
		{
			return reinterpret_cast<void(__thiscall*)(InventoryGrid* self)>(FUNC_INVENTORYGRID_DESTR_INVENTORYGRID)(this);
		}
		InventoryGrid(const glm::ivec2& size) 
		{
			return reinterpret_cast<void(__thiscall*)(InventoryGrid* self, const glm::ivec2& size)>(FUNC_INVENTORYGRID_INVENTORYGRID)(this, size);
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
		std::unique_ptr<Item,std::default_delete<Item> > getSlot(int index) override
		{
			return reinterpret_cast<std::unique_ptr<Item,std::default_delete<Item> > (__thiscall*)(InventoryGrid* self, int index)>(FUNC_INVENTORYGRID_GETSLOT)(this, index);
		}
		Inventory::iterator end() override
		{
			return reinterpret_cast<Inventory::iterator (__thiscall*)(InventoryGrid* self, Inventory::iterator* result)>(FUNC_INVENTORYGRID_END)(this, result);
		}
		void load(nlohmann::json& j) 
		{
			return reinterpret_cast<void (__thiscall*)(InventoryGrid* self, nlohmann::json& j)>(FUNC_INVENTORYGRID_LOAD)(this, j);
		}
		nlohmann::json save() 
		{
			return reinterpret_cast<nlohmann::json (__thiscall*)(InventoryGrid* self, nlohmann::json& result)>(FUNC_INVENTORYGRID_SAVE)(this, result);
		}
	};
}

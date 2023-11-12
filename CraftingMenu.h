#pragma once

#include "4dm.h"
#include "InventoryCursor.h"
#include "GUI/Window.h"
#include "GUI/Element.h"

namespace fdm 
{
	using CraftingMenuCallback = std::add_pointer<bool(int reciperIndex, void* user)>::type;

	class InventoryManager;
	class InventoryCursor;
	class Item;

	class CraftingMenu : public gui::Element 
	{
	public:
		struct CraftableRecipe 
		{
			int recipeIndex; 
			PAD(0x4);
			std::vector<std::unique_ptr<Item>> recipe; // 0x8
			std::unique_ptr<Item> result; // 0x20
			int availableCount; // 0x28

			~CraftableRecipe() 
			{
				reinterpret_cast<void(__thiscall*)(CraftingMenu::CraftableRecipe* self)>(FUNC_CRAFTINGMENU_CRAFTABLERECIPE_DESTR_CRAFTABLERECIPE)(this);
			}
			CraftableRecipe(int recipeIndex, nlohmann::json& j, int availableCount) 
			{
				reinterpret_cast<void(__thiscall*)(CraftingMenu::CraftableRecipe* self, int recipeIndex, nlohmann::json& j, int availableCount)>(FUNC_CRAFTINGMENU_CRAFTABLERECIPE_CRAFTABLERECIPE)(this, recipeIndex, j, availableCount);
			}
		};
		inline static nlohmann::json* recipes = reinterpret_cast<nlohmann::json*>((base + 0x2BDF90));
		InventoryManager* Interface; // 0x8
		InventoryCursor* cursor; // 0x10
		std::vector<CraftingMenu::CraftableRecipe> craftableRecipes; // 0x18
		int xOffset; // 0x30
		int yOffset; // 0x34
		gui::AlignmentX xAlign; // 0x38
		gui::AlignmentY yAlign; // 0x3C
		inline static TexRenderer* tr = reinterpret_cast<TexRenderer*>((base + 0x2BDFA0));
		CraftingMenuCallback callback = NULL; // 0x40
		void* user; // 0x48

		inline static bool loadRecipes() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(FUNC_CRAFTINGMENU_LOADRECIPES)();
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, gui::Window* w)>(FUNC_CRAFTINGMENU_RENDER)(this, w);
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, int offset)>(FUNC_CRAFTINGMENU_OFFSETX)(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, int offset)>(FUNC_CRAFTINGMENU_OFFSETY)(this, offset);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, gui::Window* w, int* x, int* y)>(FUNC_CRAFTINGMENU_GETPOS)(this, w, x, y);
		}
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self, gui::Window* w, int* width, int* height)>(FUNC_CRAFTINGMENU_GETSIZE)(this, w, width, height);
		}
		bool mouseButtonInput(gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(CraftingMenu* self, gui::Window* w, int button, int action, int mods)>(FUNC_CRAFTINGMENU_MOUSEBUTTONINPUT)(this, w, button, action, mods);
		}
		void updateAvailableRecipes() 
		{
			return reinterpret_cast<void (__thiscall*)(CraftingMenu* self)>(FUNC_CRAFTINGMENU_UPDATEAVAILABLERECIPES)(this);
		}
	};
}

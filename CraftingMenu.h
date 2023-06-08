#pragma once
#ifndef CRAFTINGMENU_H
#define CRAFTINGMENU_H
#include "4dm.h"
#include "GUI/Window.h"
#include "Item.h"
namespace fdm
{
	class InventoryGUI;
	class InventoryCursor;
	class Window;
	class Item;
	
	class CraftingMenu : public gui::Element
	{
	public:
		struct CraftableRecipe
		{
		public:
			std::vector<std::unique_ptr<Item>> recipe;
			std::unique_ptr<Item> result;

			int availableCount;
			PAD(4);
			~CraftableRecipe()
			{
				reinterpret_cast<void(__thiscall*)(CraftableRecipe*)>(
					FUNC_CRAFTINGMENU_CRAFTABLERECIPE_DCRAFTABLERECIPE
					)(this);
			}
		};
		
		InventoryGUI* intrface;
		InventoryCursor* cursor;
		std::vector<CraftableRecipe> craftableRecipes;
		int xOffset;
		int yOffset;
		gui::AlignmentX xAlign;
		gui::AlignmentY yAlign;
		inline static nlohmann::json getRecipes() // recipes
		{
			return *(reinterpret_cast<nlohmann::json*>((base + 0x1BDD68)));
		}
		inline static TexRenderer getTexRenderer() // tr
		{
			return *(reinterpret_cast<TexRenderer*>((base + 0x1BDD78)));
		}
		inline static bool loadRecipes() 
		{
			return reinterpret_cast<bool(__fastcall*)()>(
				FUNC_CRAFTINGMENU_LOADRECIPES
				)();
		}
		inline static void renderInit() 
		{
			reinterpret_cast<void(__fastcall*)()>(
				FUNC_CRAFTINGMENU_RENDERINIT
				)();
		}
		void render(gui::Window* w) override
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*, gui::Window*)>(
				FUNC_CRAFTINGMENU_RENDER
				)(this, w);
		}
		void offsetX(int offset) override 
		{
			this->xOffset = offset;
		}
		void offsetY(int offset) override
		{
			this->yOffset = offset;
		}
		void alignX(gui::AlignmentX a) override
		{
			this->xAlign = a;
		}
		void alignY(gui::AlignmentY a) override
		{
			this->yAlign = a;
		}
		void getPos(const gui::Window* w, int* x, int* y) override
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*, const gui::Window*, int*, int*)>(
				FUNC_CRAFTINGMENU_GETPOS
				)(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) override
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*, const gui::Window*, int*, int*)>(
				FUNC_CRAFTINGMENU_GETSIZE
				)(this, w, width, height);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int) override 
		{
			return reinterpret_cast<bool(__thiscall*)(CraftingMenu*, const gui::Window*, int, int)>(
				FUNC_CRAFTINGMENU_MOUSEBUTTONINPUT
				)(this, w, button, action);
		}
		void updateAvailableRecipes() 
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*)>(
				FUNC_CRAFTINGMENU_UPDATEAVAILABLERECIPES
				)(this);
		}
	};
}
#endif
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
	private:
		static nlohmann::json recipes;
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
					base + idaOffsetFix(0x3D790)
					)(this);
			}
		};
		static TexRenderer tr;
		InventoryGUI* intrface;
		InventoryCursor* cursor;
		std::vector<CraftableRecipe> craftableRecipes;
		int xOffset;
		int yOffset;
		gui::AlignmentX xAlign;
		gui::AlignmentY yAlign;
		static nlohmann::json getRecipes()
		{
			CraftingMenu::recipes = *reinterpret_cast<nlohmann::json*>((base + idaOffsetFix(0x1BDE68)));
			return recipes;
		}
		static bool loadRecipes() 
		{
			return reinterpret_cast<bool(__fastcall*)()>(
				base + idaOffsetFix(0x3B650)
				)();
		}
		static void renderInit() 
		{
			reinterpret_cast<void(__fastcall*)()>(
				base + idaOffsetFix(0x3B960)
				)();
		}
		void render(gui::Window* w) override
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*, gui::Window*)>(
				base + idaOffsetFix(0x3BAE0)
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
				base + idaOffsetFix(0x3BFA0)
				)(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) override
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*, const gui::Window*, int*, int*)>(
				base + idaOffsetFix(0x3C080)
				)(this, w, width, height);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int) override 
		{
			return reinterpret_cast<bool(__thiscall*)(CraftingMenu*, const gui::Window*, int, int)>(
				base + idaOffsetFix(0x3C120)
				)(this, w, button, action);
		}
		void updateAvailableRecipes() 
		{
			reinterpret_cast<void(__thiscall*)(CraftingMenu*)>(
				base + idaOffsetFix(0x3CC20)
				)(this);
		}
	};
	nlohmann::json CraftingMenu::recipes{};
}
#endif
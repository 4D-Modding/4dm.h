#pragma once
#ifndef CRAFTINGMENU_H
#define CRAFTINGMENU_H
#include "4dm.h"
#include "GUI/Window.h"
namespace fdm
{
	class InventoryGUI;
	class InventoryCursor;
	class Window;
	class CraftingMenu : public gui::Element
	{
	public:
		struct CraftableRecipe 
		{
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
		static nlohmann::json recipes;
		static TexRenderer tr;
		InventoryGUI* intrface;
		InventoryCursor* cursor;
		std::vector<CraftableRecipe> craftableRecipes;
		int xOffset;
		int yOffset;
		gui::AlignmentX xAlign;
		gui::AlignmentY yAlign;

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
			reinterpret_cast<void(__thiscall*)(gui::Element*, gui::Window*)>(
				base + idaOffsetFix(0x3BAE0)
				)(this, w);
		}
		void offsetX(int offset) override 
		{
			this->yOffset = offset;
		}
		void offsetY(int a) override
		{
			this->yAlign = (gui::AlignmentY)a;
		}
		void getPos(const gui::Window* w, int* x, int* y) override
		{
			reinterpret_cast<void(__thiscall*)(gui::Element*, const gui::Window*, int*, int*)>(
				base + idaOffsetFix(0x3BFA0)
				)(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) override
		{
			reinterpret_cast<void(__thiscall*)(gui::Element*, const gui::Window*, int*, int*)>(
				base + idaOffsetFix(0x3C080)
				)(this, w, width, height);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int) override 
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element*, const gui::Window*, int, int)>(
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
}
#endif
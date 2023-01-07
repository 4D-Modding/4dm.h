#pragma once
#ifndef CRAFTINGMENU_H
#define CRAFTINGMENU_H
#include "4dm.h"
namespace fdm
{
	class InventoryGUI;
	class CraftingMenu : public gui::Element
	{
	public:
		struct CraftableRecipe 
		{
			std::vector<std::unique_ptr<Item>> recipe;
			std::unique_ptr<Item> result;
			int availableCount;
			PAD(4);
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
	};
}
#endif
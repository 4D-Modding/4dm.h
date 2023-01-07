#pragma once
#ifndef INVENTORYGUI_H
#define INVENTORYGUI_H
#include "4dm.h"
#include "GUI/gui.h"
#include "CraftingMenu.h"
namespace fdm
{
	class InventoryManager;
	class InventoryCursor;
	class QuadRenderer;
	class Shader;
	class CraftingMenu;
	class InventoryGUI
	{
	public:
		static const int scale;
		InventoryManager* primary;
		InventoryManager* secondary;
		InventoryCursor cursor;
		int wWidth;
		int wHeight;
		QuadRenderer qr;
		const Shader* qs;
		gui::Interface ui;
		gui::Text craftingText;
		gui::ContentBox craftingMenuBox;
		CraftingMenu craftingMenu;
	};
}
#endif
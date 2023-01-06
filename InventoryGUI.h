#pragma once
#ifndef INVENTORYGUI_H
#define INVENTORYGUI_H
#include "4dm.h"
namespace fdm
{
	class InventoryManager;
	class InventoryCursor;
	class QuadRenderer;
	class Shader;
	
	class InventoryGUI
	{
	public:
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
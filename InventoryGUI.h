#pragma once
#ifndef INVENTORYGUI_H
#define INVENTORYGUI_H
#include "4dm.h"
#include "GUI/gui.h"
#include "CraftingMenu.h"
#include "InventoryCursor.h"
#include "QuadRenderer.h"
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
		inline static const int scale = 0; // idk??
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

		~InventoryGUI() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*)>(
				FUNC_INVENTORYGUI_DINVENTORYGUI
				)(this);
		}
		void renderInit(GLFWwindow* w) 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*, GLFWwindow*)>(
				FUNC_INVENTORYGUI_RENDERINIT
				)(this, w);
		}
		void windowResize(GLFWwindow* w, int width, int height) 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*, GLFWwindow*, int, int)>(
				FUNC_INVENTORYGUI_WINDOWRESIZE
				)(this, w, width, height);
		}
		void updateCraftingMenuBox() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*)>(
				FUNC_INVENTORYGUI_UPDATECRAFTINGMENUBOX
				)(this);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)
		{
			reinterpret_cast<void(__fastcall*)(void*, const glm::ivec4&, const glm::ivec2&)>(
				FUNC_INVENTORYGUI_VIEWPORTCALLBACK
				)(user, pos, scroll);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D)
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*, const glm::ivec2&, const glm::ivec2&)>(
				FUNC_INVENTORYGUI_UPDATEPROJECTION
				)(this, size, translate2D);
		}
	};
}
#endif
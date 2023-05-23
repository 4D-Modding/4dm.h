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

		~InventoryGUI() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*)>(
				base + idaOffsetFix(0x4FFD0)
				)(this);
		}
		void renderInit(GLFWwindow* w) 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*, GLFWwindow*)>(
				base + idaOffsetFix(0x67040)
				)(this, w);
		}
		void windowResize(GLFWwindow* w, int width, int height) 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*, GLFWwindow*, int, int)>(
				base + idaOffsetFix(0x673E0)
				)(this, w, width, height);
		}
		void updateCraftingMenuBox() 
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*)>(
				base + idaOffsetFix(0x67490)
				)(this);
		}
		static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)
		{
			reinterpret_cast<void(__fastcall*)(void*, const glm::ivec4&, const glm::ivec2&)>(
				base + idaOffsetFix(0x67540)
				)(user, pos, scroll);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D)
		{
			reinterpret_cast<void(__thiscall*)(InventoryGUI*, const glm::ivec2&, const glm::ivec2&)>(
				base + idaOffsetFix(0x675A0)
				)(this, size, translate2D);
		}
	};
}
#endif
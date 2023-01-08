#pragma once
#ifndef INVENTORYMANAGER_H
#define INVENTORYMANAGER_H
#include "4dm.h"
namespace fdm
{
	class Item;
	class InventoryCursor;
	class InventoryManager
	{
	public:
		InventoryManager();
		class iterator
		{
			InventoryManager* manager;
			int index;
		};
		virtual iterator begin(void) = NULL;
		virtual void render(const glm::ivec2& cursorPos) = NULL;
		virtual bool addItem(std::unique_ptr<Item>& item) = NULL;
		virtual bool combineItem(std::unique_ptr<Item>& item) = NULL;
		virtual bool placeItem(std::unique_ptr<Item>& item) = NULL;
		virtual bool mouseButtonEvent(InventoryManager* other, InventoryCursor* cursor, int button, int action, char mods) = NULL;
		virtual iterator end(void) = NULL;
		virtual int getSlotCount(void) = NULL;
		virtual std::unique_ptr<Item>* getSlot(unsigned int index) = NULL;
	};
}
#endif
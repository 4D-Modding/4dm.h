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
		virtual iterator begin(void);
		virtual void render(const glm::ivec2& cursorPos);
		virtual bool addItem(std::unique_ptr<Item>& item);
		virtual bool combineItem(std::unique_ptr<Item>& item);
		virtual bool placeItem(std::unique_ptr<Item>& item);
		virtual bool mouseButtonEvent(InventoryManager* other, InventoryCursor* cursor, int button, int action, char mods);
		virtual iterator end(void);
		virtual int getSlotCount(void);
		virtual std::unique_ptr<Item>* getSlot(unsigned int index);
	};
}
#endif
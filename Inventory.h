#pragma once

#include "4dm.h"
#include "Item.h"

namespace fdm 
{
	class Item;
	class Inventory 
	{
	public:
		class iterator 
		{
		public:
			Inventory* inventory; 
			int index; // 0x8
		};
		std::string name; // 0x8
		bool updateFlag; // 0x28



		// VIRTUAL FUNCS

		virtual void render(const glm::ivec2& cursorPos) {}
		virtual bool addItem(std::unique_ptr<Item>& item) { return false; }
		virtual bool combineItem(std::unique_ptr<Item>& item) { return false; }
		virtual bool placeItem(std::unique_ptr<Item>& item) { return false; }
		virtual int getSlotIndex(const glm::ivec2 &) { return 0; }
		virtual uint32_t getSlotCount() { return 0; }
		virtual std::unique_ptr<Item>* getSlot(int index) { return NULL; }
		virtual Inventory::iterator begin() { return { nullptr, 0 }; }
		virtual Inventory::iterator end() { return { nullptr, 0 }; }
	};
}

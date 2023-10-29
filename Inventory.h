#pragma once

#include "4dm.h"

namespace fdm 
{
	class Inventory 
	{
	public:
		class iterator 
		{
			Inventory* inventory; 
			int index; // 0x8

		};
		std::string name; // 0x8
		bool updateFlag; // 0x28



		// VIRTUAL FUNCS

		virtual void render(const glm::ivec2& cursorPos) = NULL;
		virtual bool addItem(std::unique_ptr<Item>& item) = NULL;
		virtual bool combineItem(std::unique_ptr<Item>& item) = NULL;
		virtual bool placeItem(std::unique_ptr<Item>& item) = NULL;
		virtual int getSlotIndex(const glm::ivec2 &) = NULL;
		virtual uint32_t getSlotCount() = NULL;
		virtual std::unique_ptr<Item,std::default_delete<Item> > getSlot(int index) = NULL;
		virtual Inventory::iterator begin() = NULL;
		virtual Inventory::iterator end() = NULL;
	};
}

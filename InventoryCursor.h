#pragma once
#ifndef INVENTORYCURSOR_H
#define INVENTORYCURSOR_H
#include "4dm.h"
namespace fdm
{
	class Item;
	class InventoryCursor
	{
	public:
		std::unique_ptr<Item> item;
		glm::ivec2 pos;
	};
}
#endif
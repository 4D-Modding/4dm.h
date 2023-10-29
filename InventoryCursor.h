#pragma once

#include "4dm.h"

namespace fdm 
{
	class InventoryCursor 
	{
	public:
		std::unique_ptr<Item,std::default_delete<Item> > item; 
		glm::ivec2 pos; // 0x8

	};
}

#pragma once

#include "4dm.h"

namespace fdm 
{
	class InventorySession 
	{
	public:
		InventoryManager* manager; 
		Inventory* inventory; // 0x8

		~InventorySession() 
		{
			return reinterpret_cast<void(__thiscall*)(InventorySession* self)>(FUNC_INVENTORYSESSION_DESTR_INVENTORYSESSION)(this);
		}
	};
}

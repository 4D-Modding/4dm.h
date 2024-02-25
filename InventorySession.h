#pragma once

#include "4dm.h"
#include "InventoryManager.h"

namespace fdm 
{
	class InventorySession 
	{
	public:
		InventoryManager* manager; 
		Inventory* inventory; // 0x8

		~InventorySession() 
		{
			reinterpret_cast<void(__thiscall*)(InventorySession* self)>(getFuncAddr((int)Func::InventorySession::destr_InventorySession))(this);
		}
	};
}

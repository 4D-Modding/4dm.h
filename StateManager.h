#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateManager 
	{
	public:
		std::vector<State *,std::allocator<State *> > states; 
		GLFWwindow* window; // 0x18

		inline static void pushState(State* state) 
		{
			return reinterpret_cast<void (__fastcall*)(StateManager* self, State* state)>(FUNC_STATEMANAGER_PUSHSTATE)(this, state);
		}
	};
}

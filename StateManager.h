#pragma once

#include "4dm.h"

namespace fdm 
{
	class State;
	class StateManager 
	{
	public:
		std::vector<State *> states; 
		GLFWwindow* window; // 0x18

		void pushState(State* state) 
		{
			return reinterpret_cast<void (__thiscall*)(StateManager* self, State* state)>(FUNC_STATEMANAGER_PUSHSTATE)(this, state);
		}
	};
}

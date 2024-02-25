#pragma once

#include "4dm.h"
#include "State.h"

namespace fdm 
{
	class StateManager 
	{
	public:
		std::vector<State *> states; 
		GLFWwindow* window; // 0x18

		void pushState(State* state) 
		{
			return reinterpret_cast<void (__thiscall*)(StateManager* self, State* state)>(getFuncAddr((int)Func::StateManager::pushState))(this, state);
		}

		// thanks mashpoe for telling me about the fact that those funcs exist
		// thanks to me the tr1ngledev for writing them

		/* // I COMPLETELY FORGOT PUSHSTATE IS COMPILED IN THE GAME AND EXISTS IN HERE LMFAO

		void pushState(State* state)
		{
			State* lastState = states.back();
			if (lastState != state)
				lastState->pause(*this);

			states.push_back(state);

			state->init(*this);
		}

		*/

		void popState()
		{
			if (!states.empty())
			{
				states.back()->close(*this);

				states.pop_back();

				if (!states.empty())
					states.back()->resume(*this);
			}
		}

		void changeState(State* newState)
		{
			popState();
			pushState(newState);
		}
	};
}

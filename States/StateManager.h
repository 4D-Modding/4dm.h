#pragma once
#ifndef STATEMANAGER_H
#define STATEMANAGER_H
#include "../4dm.h"
#include "State.h"
namespace fdm
{
	class State;
	struct StateManager
	{
	public:
		std::vector<State*> states;
		GLFWwindow* window;
	};
}
#endif
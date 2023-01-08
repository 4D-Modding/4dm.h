#pragma once
#ifndef STATE_H
#define STATE_H
#include "../4dm.h"
namespace fdm
{
	struct StateManager;
	class State
	{
	public:
		virtual void init(StateManager&) = NULL;
		virtual void close(StateManager&) = NULL;
		virtual void update(StateManager&, double) = NULL;
		virtual void render(StateManager&) = NULL;
		virtual void pause(StateManager&) = NULL;
		virtual void resume(StateManager&) = NULL;
		virtual void mouseInput(StateManager&, double, double) = NULL;
		virtual void scrollInput(StateManager&, double, double) = NULL;
		virtual void mouseButtonInput(StateManager&, int, int, int) = NULL;
		virtual void keyInput(StateManager&, int, int, int, int) = NULL;
		virtual void windowResize(StateManager&, int, int) = NULL;
		virtual void charInput(StateManager&, unsigned int) = NULL;
	};
}
#endif
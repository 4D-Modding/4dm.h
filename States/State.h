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
		virtual void init(StateManager&);
		virtual void close(StateManager&);
		virtual void update(StateManager&, double);
		virtual void render(StateManager&);
		virtual void pause(StateManager&);
		virtual void resume(StateManager&);
		virtual void mouseInput(StateManager&, double, double);
		virtual void scrollInput(StateManager&, double, double);
		virtual void mouseButtonInput(StateManager&, int, int, int);
		virtual void keyInput(StateManager&, int, int, int, int);
		virtual void windowResize(StateManager&, int, int);
		virtual void charInput(StateManager&, unsigned int);
	};
}
#endif
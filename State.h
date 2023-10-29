#pragma once

#include "4dm.h"
#include "StateManager.h"

namespace fdm 
{
	class State 
	{
	public:
		virtual void init(StateManager& s) = NULL;
		virtual void close(StateManager& s) = NULL;
		virtual void update(StateManager& s, double dt) = NULL;
		virtual void render(StateManager& s) = NULL;
		virtual void pause(StateManager& s) = NULL;
		virtual void resume(StateManager& s) = NULL;
		virtual void mouseInput(StateManager& s, double xpos, double ypos) = NULL;
		virtual void scrollInput(StateManager& s, double xoff, double yoff) = NULL;
		virtual void mouseButtonInput(StateManager& s, int button, int action, int mods) = NULL;
		virtual void keyInput(StateManager&, int key, int scancode, int action, int mods) = NULL;
		virtual void windowResize(StateManager&, int width, int height) = NULL;
		virtual void charInput(StateManager&, uint32_t codepoint) = NULL;
		virtual void fileDrop(StateManager&, int count, const char** paths) = NULL;
	};
}

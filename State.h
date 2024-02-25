#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateManager;
	class State 
	{
	public:
		virtual void init(StateManager& s) {}
		virtual void close(StateManager& s) {}
		virtual void update(StateManager& s, double dt) {}
		virtual void render(StateManager& s) {}
		virtual void pause(StateManager& s) {}
		virtual void resume(StateManager& s) {}
		virtual void mouseInput(StateManager& s, double xpos, double ypos) {}
		virtual void scrollInput(StateManager& s, double xoff, double yoff) {}
		virtual void mouseButtonInput(StateManager& s, int button, int action, int mods) {}
		virtual void keyInput(StateManager&, int key, int scancode, int action, int mods) {}
		virtual void windowResize(StateManager&, int width, int height) {}
		virtual void charInput(StateManager&, uint32_t codepoint) {}
		virtual void fileDrop(StateManager&, int count, const char** paths) {}
	};
}

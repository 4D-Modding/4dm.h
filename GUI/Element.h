#pragma once

#include "gui.h"
#include "Window.h"

namespace fdm::gui
{
	class Element 
	{
	public:
		// VIRTUAL FUNCS
		virtual void render(gui::Window* w) = NULL;
		virtual void alignX(gui::AlignmentX alignment) = NULL;
		virtual void alignY(gui::AlignmentY alignment) = NULL;
		virtual void offsetX(int offset) = NULL;
		virtual void offsetY(int offset) = NULL;
		virtual void getPos(gui::Window* w, int* x, int* y) = NULL;
		virtual void getSize(gui::Window* w, int* width, int* height) = NULL;
		virtual bool mouseInput(gui::Window* w, double xpos, double ypos) = NULL;
		virtual bool scrollInput(gui::Window* w, double xoff, double yoff) = NULL;
		virtual bool mouseButtonInput(gui::Window* w, int button, int action, int mods) = NULL;
		virtual bool keyInput(gui::Window* w, int, int, int, int) = NULL;
		virtual bool charInput(gui::Window* w, uint32_t codepoint) = NULL;
		virtual bool enabled()
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self)>(FUNC_GUI_ELEMENT_ENABLED)(this);
		}
		virtual void select() = NULL;
		virtual void deselect() = NULL;
		virtual int getCursorType()
		{
			return reinterpret_cast<int(__thiscall*)(gui::Element * self)>(FUNC_GUI_ELEMENT_GETCURSORTYPE)(this);
		}
	};
}

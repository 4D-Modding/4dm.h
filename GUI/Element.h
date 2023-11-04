#pragma once

//#include "gui.h"
#include "Window.h"

namespace fdm::gui
{
	enum AlignmentX;
	enum AlignmentY;
	class Window;
	class Element 
	{
	public:
		// VIRTUAL FUNCS
		virtual void render(gui::Window* w) { }
		virtual void alignX(gui::AlignmentX alignment) { }
		virtual void alignY(gui::AlignmentY alignment) { }
		virtual void offsetX(int offset) { }
		virtual void offsetY(int offset) { }
		virtual void getPos(gui::Window* w, int* x, int* y) { }
		virtual void getSize(gui::Window* w, int* width, int* height) { }
		virtual bool mouseInput(gui::Window* w, double xpos, double ypos){ return false; }
		virtual bool scrollInput(gui::Window* w, double xoff, double yoff){ return false; }
		virtual bool mouseButtonInput(gui::Window* w, int button, int action, int mods){ return false; }
		virtual bool keyInput(gui::Window* w, int, int, int, int){ return false; }
		virtual bool charInput(gui::Window* w, uint32_t codepoint){ return false; }
		virtual bool enabled()
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self)>(FUNC_GUI_ELEMENT_ENABLED)(this);
		}
		virtual void select() { }
		virtual void deselect() { }
		virtual int getCursorType()
		{
			return reinterpret_cast<int(__thiscall*)(gui::Element * self)>(FUNC_GUI_ELEMENT_GETCURSORTYPE)(this);
		}
	};
}

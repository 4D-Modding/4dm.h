#pragma once

//#include "gui.h"
#include "Window.h"

namespace fdm::gui
{
	enum AlignmentX: int;
	enum AlignmentY: int;
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
		virtual void getPos(const gui::Window* w, int* x, int* y) const { }
		virtual void getSize(const gui::Window* w, int* width, int* height) const { }
		virtual bool mouseInput(const gui::Window* w, double xpos, double ypos) { return false; }
		virtual bool scrollInput(const gui::Window* w, double xoff, double yoff) { return false; }
		virtual bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) { return false; }
		virtual bool keyInput(const gui::Window* w, int, int, int, int) { return false; }
		virtual bool charInput(const gui::Window* w, uint32_t codepoint) { return false; }
		virtual bool enabled()
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self)>(getFuncAddr((int)Func::gui_Nested::Element::enabled))(this);
		}
		virtual void select() { }
		virtual void deselect() { }
		virtual int getCursorType()
		{
			return reinterpret_cast<int(__thiscall*)(gui::Element * self)>(getFuncAddr((int)Func::gui_Nested::Element::getCursorType))(this);
		}
	};
}

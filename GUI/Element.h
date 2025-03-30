#pragma once

#include "Alignment.h"

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
		virtual void getPos(const gui::Window* w, int* x, int* y) const { }
		virtual void getSize(const gui::Window* w, int* width, int* height) const { }
		virtual bool mouseInput(const gui::Window* w, double xpos, double ypos)
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self, const gui::Window*, double, double)>(getFuncAddr((int)Func::gui::Element::mouseInput))(this, w, xpos, ypos);
		}
		virtual bool scrollInput(const gui::Window* w, double xoff, double yoff)
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self, const gui::Window*, double, double)>(getFuncAddr((int)Func::gui::Element::scrollInput))(this, w, xoff, yoff);
		}
		virtual bool mouseButtonInput(const gui::Window* w, int button, int action, int mods)
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self, const gui::Window*, int, int, int)>(getFuncAddr((int)Func::gui::Element::mouseButtonInput))(this, w, button, action, mods);
		}
		virtual bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods)
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self, const gui::Window*, int, int, int, int)>(getFuncAddr((int)Func::gui::Element::keyInput))(this, w, key, scancode, action, mods);
		}
		virtual bool charInput(const gui::Window* w, uint32_t codepoint)
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self, const gui::Window*, uint32_t)>(getFuncAddr((int)Func::gui::Element::charInput))(this, w, codepoint);
		}
		virtual bool enabled()
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Element * self)>(getFuncAddr((int)Func::gui::Element::enabled))(this);
		}
		virtual void select()
		{
			return reinterpret_cast<void(__thiscall*)(gui::Element * self)>(getFuncAddr((int)Func::gui::Element::select))(this);
		}
		virtual void deselect()
		{
			return reinterpret_cast<void(__thiscall*)(gui::Element * self)>(getFuncAddr((int)Func::gui::Element::deselect))(this);
		}
		virtual int getCursorType()
		{
			return reinterpret_cast<int(__thiscall*)(gui::Element * self)>(getFuncAddr((int)Func::gui::Element::getCursorType))(this);
		}
	};
}

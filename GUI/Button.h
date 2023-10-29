#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::Button : public gui::Element 
	{
	public:
		std::string text; // 0x8
		bool clickable; // 0x28
		bool mouseDown; // 0x29
		bool selected; // 0x2A
		PAD(0x1);
		int xOffset; // 0x2C
		int yOffset; // 0x30
		gui::AlignmentX xAlign; // 0x34
		gui::AlignmentY yAlign; // 0x38
		int width; // 0x3C
		int height; // 0x40
		PAD(0x4);
		void* user; // 0x48
		void* callback; // 0x50

		void ~Button() 
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self)>(FUNC_GUI_BUTTON_DESTR_BUTTON)(this);
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self, gui::Window* w)>(FUNC_GUI_BUTTON_RENDER)(this, w);
		}
		bool mouseButtonInput(gui::Window* w, int button, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self, gui::Window* w, int button, int action)>(FUNC_GUI_BUTTON_MOUSEBUTTONINPUT)(this, w, button, action);
		}
		bool keyInput(const gui::Window* w, __int64 key, __int64 scancode, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self, const gui::Window* w, __int64 key, __int64 scancode, int action)>(FUNC_GUI_BUTTON_KEYINPUT)(this, w, key, scancode, action);
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self, int offset)>(FUNC_GUI_BUTTON_OFFSETX)(this, offset);
		}
		bool enabled() override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self)>(FUNC_GUI_BUTTON_ENABLED)(this);
		}
		void select() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self)>(FUNC_GUI_BUTTON_SELECT)(this);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_BUTTON_GETPOS)(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self, const gui::Window* w, int* width, int* height)>(FUNC_GUI_BUTTON_GETSIZE)(this, w, width, height);
		}
		bool touchingMouse(gui::Window* w) 
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self, gui::Window* w)>(FUNC_GUI_BUTTON_TOUCHINGMOUSE)(this, w);
		}
	};
}

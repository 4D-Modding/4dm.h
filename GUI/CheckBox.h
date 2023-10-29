#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::CheckBox : public gui::Element 
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
		inline static const int width = 20; 
		inline static const int height = 20; 
		PAD(0x4);
		void* user; // 0x40
		void* callback; // 0x48
		bool checked; // 0x50

		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::CheckBox* self, gui::Window* w)>(FUNC_GUI_CHECKBOX_RENDER)(this, w);
		}
		bool mouseButtonInput(gui::Window* w, int button, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::CheckBox* self, gui::Window* w, int button, int action)>(FUNC_GUI_CHECKBOX_MOUSEBUTTONINPUT)(this, w, button, action);
		}
		bool keyInput(const gui::Window* w, __int64 key, __int64 scancode, int action) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::CheckBox* self, const gui::Window* w, __int64 key, __int64 scancode, int action)>(FUNC_GUI_CHECKBOX_KEYINPUT)(this, w, key, scancode, action);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::CheckBox* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_CHECKBOX_GETPOS)(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::CheckBox* self, const gui::Window* w, int* width, int* height)>(FUNC_GUI_CHECKBOX_GETSIZE)(this, w, width, height);
		}
		bool touchingMouse(gui::Window* w) 
		{
			return reinterpret_cast<bool (__thiscall*)(gui::CheckBox* self, gui::Window* w)>(FUNC_GUI_CHECKBOX_TOUCHINGMOUSE)(this, w);
		}
	};
}

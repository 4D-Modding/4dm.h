#pragma once

#include "gui.h"

namespace fdm::gui
{
	using ButtonCallback = std::add_pointer<void(void* user)>::type;
	class Button : public gui::Element
	{
	public:
		std::string text; // 0x8
		bool clickable = true; // 0x28
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
		ButtonCallback callback = NULL; // 0x50

		~Button()
		{
			reinterpret_cast<void(__thiscall*)(gui::Button * self)>(FUNC_GUI_BUTTON_DESTR_BUTTON)(this);
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void(__thiscall*)(gui::Button * self, gui::Window * w)>(FUNC_GUI_BUTTON_RENDER)(this, w);
		}
		bool mouseButtonInput(gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Button * self, gui::Window * w, int button, int action, int mods)>(FUNC_GUI_BUTTON_MOUSEBUTTONINPUT)(this, w, button, action, mods);
		}
		bool keyInput(gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Button * self, gui::Window * w, int key, int scancode, int action, int mods)>(FUNC_GUI_BUTTON_KEYINPUT)(this, w, key, scancode, action, mods);
		}
		void offsetX(int offset) override
		{
			this->xOffset = offset;
		}
		void offsetY(int offset) override
		{
			this->yOffset = offset;
		}
		void alignX(gui::AlignmentX a)
		{
			this->xAlign = a;
		}
		void alignY(gui::AlignmentY a)
		{
			this->yAlign = a;
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
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Button* self, gui::Window* w, int* width, int* height)>(FUNC_GUI_BUTTON_GETSIZE)(this, w, width, height);
		}
		bool touchingMouse(gui::Window* w) 
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self, gui::Window* w)>(FUNC_GUI_BUTTON_TOUCHINGMOUSE)(this, w);
		}
	};
}

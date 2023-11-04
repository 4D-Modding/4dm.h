#pragma once

#include "gui.h"

namespace fdm::gui
{
	using SliderCallback = std::add_pointer<void(void* user, int value)>::type;
	class Slider : public gui::Element 
	{
	public:
		inline static const int height = 50; 
		std::string text; // 0x8
		bool clickable = true; // 0x28
		bool mouseDown; // 0x29
		bool selected; // 0x2A
		PAD(0x1);
		int range; // 0x2C
		int width; // 0x30
		int value; // 0x34
		int xOffset; // 0x38
		int yOffset; // 0x3C
		gui::AlignmentX xAlign; // 0x40
		gui::AlignmentY yAlign; // 0x44
		void* user; // 0x48
		SliderCallback callback = NULL; // 0x50

		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, int offset)>(FUNC_GUI_SLIDER_OFFSETX)(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, int offset)>(FUNC_GUI_SLIDER_OFFSETY)(this, offset);
		}
		void deselect() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self)>(FUNC_GUI_SLIDER_DESELECT)(this);
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::Window* w)>(FUNC_GUI_SLIDER_RENDER)(this, w);
		}
		bool mouseButtonInput(gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Slider* self, gui::Window* w, int button, int action, int mods)>(FUNC_GUI_SLIDER_MOUSEBUTTONINPUT)(this, w, button, action, mods);
		}
		bool mouseInput(gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Slider* self, gui::Window* w, double xpos, double ypos)>(FUNC_GUI_SLIDER_MOUSEINPUT)(this, w, xpos, ypos);
		}
		bool keyInput(gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Slider* self, gui::Window* w, int key, int scancode, int action, int mods)>(FUNC_GUI_SLIDER_KEYINPUT)(this, w, key, scancode, action, mods);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::AlignmentX a)>(FUNC_GUI_SLIDER_ALIGNX)(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::AlignmentY a)>(FUNC_GUI_SLIDER_ALIGNY)(this, a);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_SLIDER_GETPOS)(this, w, x, y);
		}
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::Window* w, int* width, int* height)>(FUNC_GUI_SLIDER_GETSIZE)(this, w, width, height);
		}
	};
}

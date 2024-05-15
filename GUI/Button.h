#pragma once

#include "gui.h"

namespace fdm::gui
{
	using ButtonCallback = std::add_pointer<void(void* user)>::type;
	class Button : public gui::Element
	{
	public:
		stl::string text = ""; // 0x8
		bool clickable = true; // 0x28
		bool mouseDown; // 0x29
		bool selected; // 0x2A
		PAD(0x1);
		int xOffset = 0; // 0x2C
		int yOffset = 0; // 0x30
		gui::AlignmentX xAlign = ALIGN_LEFT; // 0x34
		gui::AlignmentY yAlign = ALIGN_TOP; // 0x38
		int width = 100; // 0x3C
		int height = 50; // 0x40
		PAD(0x4);
		void* user; // 0x48
		ButtonCallback callback = NULL; // 0x50

		~Button()
		{
			reinterpret_cast<void(__thiscall*)(gui::Button * self)>(getFuncAddr((int)Func::gui::Button::destr_Button))(this);
		}
		void setText(const stl::string& text)
		{
			this->text = text;
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void(__thiscall*)(gui::Button * self, gui::Window * w)>(getFuncAddr((int)Func::gui::Button::render))(this, w);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Button * self, const gui::Window * w, int button, int action, int mods)>(getFuncAddr((int)Func::gui::Button::mouseButtonInput))(this, w, button, action, mods);
		}
		bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Button * self, const gui::Window * w, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::gui::Button::keyInput))(this, w, key, scancode, action, mods);
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
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self)>(getFuncAddr((int)Func::gui::Button::enabled))(this);
		}
		void select() override
		{
			selected = true;
		}
		void deselect() override
		{
			selected = false;
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Button* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::gui::Button::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Button* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::gui::Button::getSize))(this, w, width, height);
		}
		bool touchingMouse(const gui::Window* w)
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Button* self, const gui::Window* w)>(getFuncAddr((int)Func::gui::Button::touchingMouse))(this, w);
		}
	};
}

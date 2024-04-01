#pragma once

#include "gui.h"

namespace fdm::gui
{
	using CheckBoxCallback = std::add_pointer<void(void* user, bool checked)>::type;
	class CheckBox : public gui::Element 
	{
	public:
		std::string text = ""; // 0x8
		bool clickable = true; // 0x28
		bool mouseDown; // 0x29
		bool selected; // 0x2A
		PAD(0x1);
		int xOffset = 0; // 0x2C
		int yOffset = 0; // 0x30
		gui::AlignmentX xAlign = ALIGN_LEFT; // 0x34
		gui::AlignmentY yAlign = ALIGN_TOP; // 0x38
		inline static const int width = 20; 
		inline static const int height = 20; 
		PAD(0x4);
		void* user; // 0x40
		CheckBoxCallback callback = NULL; // 0x48
		bool checked; // 0x50

		void setText(const std::string& text)
		{
			this->text = text;
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
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::CheckBox* self, gui::Window* w)>(getFuncAddr((int)Func::gui_Nested::CheckBox::render))(this, w);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::CheckBox* self, const gui::Window* w, int button, int action, int mods)>(getFuncAddr((int)Func::gui_Nested::CheckBox::mouseButtonInput))(this, w, button, action, mods);
		}
		bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::CheckBox* self, const gui::Window* w, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::gui_Nested::CheckBox::keyInput))(this, w, key, scancode, action, mods);
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::CheckBox* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::gui_Nested::CheckBox::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::CheckBox* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::gui_Nested::CheckBox::getSize))(this, w, width, height);
		}
		void select() override
		{
			selected = true;
		}
		void deselect() override
		{
			selected = false;
		}
		bool touchingMouse(gui::Window* w) 
		{
			return reinterpret_cast<bool (__thiscall*)(gui::CheckBox* self, gui::Window* w)>(getFuncAddr((int)Func::gui_Nested::CheckBox::touchingMouse))(this, w);
		}
	};
}

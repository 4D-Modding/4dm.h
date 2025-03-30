#pragma once

#include "gui.h"

namespace fdm::gui
{
	using SliderCallback = std::add_pointer<void(void* user, int value)>::type;
	class Slider : public gui::Element 
	{
	public:
		inline static const int height = 50;
		stl::string text = ""; // 0x8
		bool clickable = true; // 0x28
		bool mouseDown; // 0x29
		bool selected; // 0x2A
		PAD(0x1);
		int range = 100; // 0x2C
		int width = 100; // 0x30
		int value = 0; // 0x34
		int xOffset = 0; // 0x38
		int yOffset = 0; // 0x3C
		gui::AlignmentX xAlign = ALIGN_LEFT; // 0x40
		gui::AlignmentY yAlign = ALIGN_TOP; // 0x44
		void* user; // 0x48
		SliderCallback callback = NULL; // 0x50

		void setText(const stl::string& text)
		{
			this->text = text;
		}
		void offsetX(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, int offset)>(getFuncAddr((int)Func::gui::Slider::offsetX))(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, int offset)>(getFuncAddr((int)Func::gui::Slider::offsetY))(this, offset);
		}
		void select() override
		{
			return reinterpret_cast<void(__thiscall*)(gui::Slider * self)>(getFuncAddr((int)Func::gui::Slider::select))(this);
		}
		void deselect() override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self)>(getFuncAddr((int)Func::gui::Slider::deselect))(this);
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::Window* w)>(getFuncAddr((int)Func::gui::Slider::render))(this, w);
		}
		bool mouseButtonInput(const gui::Window* w, int button, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Slider* self, const gui::Window* w, int button, int action, int mods)>(getFuncAddr((int)Func::gui::Slider::mouseButtonInput))(this, w, button, action, mods);
		}
		bool mouseInput(const gui::Window* w, double xpos, double ypos) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Slider* self, const gui::Window* w, double xpos, double ypos)>(getFuncAddr((int)Func::gui::Slider::mouseInput))(this, w, xpos, ypos);
		}
		bool keyInput(const gui::Window* w, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<bool (__thiscall*)(gui::Slider* self, const gui::Window* w, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::gui::Slider::keyInput))(this, w, key, scancode, action, mods);
		}
		void alignX(gui::AlignmentX a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::AlignmentX a)>(getFuncAddr((int)Func::gui::Slider::alignX))(this, a);
		}
		void alignY(gui::AlignmentY a) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Slider* self, gui::AlignmentY a)>(getFuncAddr((int)Func::gui::Slider::alignY))(this, a);
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Slider* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::gui::Slider::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Slider* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::gui::Slider::getSize))(this, w, width, height);
		}
		bool enabled() override
		{
			return reinterpret_cast<bool(__thiscall*)(gui::Slider * self)>(getFuncAddr((int)Func::gui::Slider::enabled))(this);
		}
	};
}

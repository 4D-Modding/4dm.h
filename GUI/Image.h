#pragma once

#include "gui.h"

namespace fdm::gui
{
	class Image : public gui::Element 
	{
	public:
		TexRenderer* tr; // 0x8
		int xOffset = 0; // 0x10
		int yOffset = 0; // 0x14
		gui::AlignmentX xAlign = ALIGN_LEFT; // 0x18
		gui::AlignmentY yAlign = ALIGN_TOP; // 0x1C
		int width = 0; // 0x20
		int height = 0; // 0x24

		Image() {}

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
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, gui::Window* w)>(getFuncAddr((int)Func::gui::Image::render))(this, w);
		}
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Image* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::gui::Image::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Image* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::gui::Image::getSize))(this, w, width, height);
		}
		bool enabled() override
		{
			return false;
		}
	};
}

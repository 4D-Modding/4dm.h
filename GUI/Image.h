#pragma once

#include "gui.h"

namespace fdm::gui
{
	class Image : public gui::Element 
	{
	public:
		TexRenderer* tr; // 0x8
		int xOffset; // 0x10
		int yOffset; // 0x14
		gui::AlignmentX xAlign; // 0x18
		gui::AlignmentY yAlign; // 0x1C
		int width; // 0x20
		int height; // 0x24

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
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, gui::Window* w)>(FUNC_GUI_IMAGE_RENDER)(this, w);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_IMAGE_GETPOS)(this, w, x, y);
		}
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, gui::Window* w, int* width, int* height)>(FUNC_GUI_IMAGE_GETSIZE)(this, w, width, height);
		}
	};
}

#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::Image : public gui::Element 
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
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, int offset)>(FUNC_GUI_IMAGE_OFFSETX)(this, offset);
		}
		void offsetY(int offset) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, int offset)>(FUNC_GUI_IMAGE_OFFSETY)(this, offset);
		}
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, gui::Window* w)>(FUNC_GUI_IMAGE_RENDER)(this, w);
		}
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_IMAGE_GETPOS)(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Image* self, const gui::Window* w, int* width, int* height)>(FUNC_GUI_IMAGE_GETSIZE)(this, w, width, height);
		}
	};
}

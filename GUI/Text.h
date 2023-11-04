#pragma once

#include "gui.h"

namespace fdm::gui
{
	class Text : public gui::Element 
	{
	public:
		std::string text; // 0x8
		int xOffset; // 0x28
		int yOffset; // 0x2C
		gui::AlignmentX xAlign; // 0x30
		gui::AlignmentY yAlign; // 0x34
		glm::vec4 color{1}; // 0x38
		uint32_t size; // 0x48
		uint32_t wrapWidth; // 0x4C
		bool shadow; // 0x50
		bool fancy; // 0x51

		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, gui::Window* w)>(FUNC_GUI_TEXT_RENDER)(this, w);
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
		void getPos(gui::Window* w, int* x, int* y) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, gui::Window* w, int* x, int* y)>(FUNC_GUI_TEXT_GETPOS)(this, w, x, y);
		}
		void getSize(gui::Window* w, int* width, int* height) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, gui::Window* w, int* width, int* height)>(FUNC_GUI_TEXT_GETSIZE)(this, w, width, height);
		}
		void setText(const std::string& text) 
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, const std::string& text)>(FUNC_GUI_TEXT_SETTEXT)(this, text);
		}
		void renderText(gui::Window* w, FontRenderer* text, int x, int y, bool align) 
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, gui::Window* w, FontRenderer* text, int x, int y, bool align)>(FUNC_GUI_TEXT_RENDERTEXT)(this, w, text, x, y, align);
		}
	};
}

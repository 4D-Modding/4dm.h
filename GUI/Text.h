#pragma once

#include "gui.h"

namespace fdm::gui
{
	class Text : public gui::Element 
	{
	public:
		std::string text = ""; // 0x8
		int xOffset = 0; // 0x28
		int yOffset = 0; // 0x2C
		gui::AlignmentX xAlign = ALIGN_LEFT; // 0x30
		gui::AlignmentY yAlign = ALIGN_TOP;  // 0x34
		glm::vec4 color{1}; // 0x38
		uint32_t size = 1; // 0x48
		uint32_t wrapWidth; // 0x4C
		bool shadow; // 0x50
		bool fancy; // 0x51

		bool enabled() override { return false; }
		void render(gui::Window* w) override
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, gui::Window* w)>(getFuncAddr((int)Func::gui_Nested::Text::render))(this, w);
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
		void getPos(const gui::Window* w, int* x, int* y) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Text* self, const gui::Window* w, int* x, int* y)>(getFuncAddr((int)Func::gui_Nested::Text::getPos))(this, w, x, y);
		}
		void getSize(const gui::Window* w, int* width, int* height) const override
		{
			return reinterpret_cast<void (__thiscall*)(const gui::Text* self, const gui::Window* w, int* width, int* height)>(getFuncAddr((int)Func::gui_Nested::Text::getSize))(this, w, width, height);
		}
		void setText(const std::string& text) 
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, const std::string& text)>(getFuncAddr((int)Func::gui_Nested::Text::setText))(this, text);
		}
		void renderText(gui::Window* w, const std::string& text, int x, int y, bool align) 
		{
			return reinterpret_cast<void (__thiscall*)(gui::Text* self, gui::Window* w, const std::string & text, int x, int y, bool align)>(getFuncAddr((int)Func::gui_Nested::Text::renderText))(this, w, text, x, y, align);
		}
	};
}

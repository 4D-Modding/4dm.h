#pragma once
#ifndef GUI_TEXT_H
#define GUI_TEXT_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class Text : public Element
		{
		public:
			std::string text;
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			glm::vec4 color;
			unsigned int size;
			unsigned int wrapWidth;
			bool shadow;
			bool fancy;

			void render(gui::Window* w) override 
			{
				reinterpret_cast<void(__thiscall*)(gui::Text*, gui::Window*)>(
					base + idaOffsetFix(0x5B830)
					)(this, w);
			}
			void offsetX(int offset) override
			{
				this->xOffset = offset;
			}
			void offsetY(int offset) override
			{
				this->yOffset = offset;
			}
			void alignX(AlignmentX a) override
			{
				this->xAlign = a;
			}
			void alignY(AlignmentY a) override
			{
				this->yAlign = a;
			}
			void getPos(const gui::Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(gui::Text*, const gui::Window*, int*, int*)>(
					base + idaOffsetFix(0x5BC50)
					)(this, w, x, y);
			}
			void getSize(const gui::Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(gui::Text*, const gui::Window*, int*, int*)>(
					base + idaOffsetFix(0x5BD30)
					)(this, w, width, height);
			}
			void setText(const std::string& text)
			{
				reinterpret_cast<void(__thiscall*)(gui::Text*, const std::string&)>(
					base + idaOffsetFix(0x5BFA0)
					)(this, text);
			}
			void renderText(gui::Window* w, const std::string& text, int x, int y, bool align)
			{
				reinterpret_cast<void(__thiscall*)(gui::Text*, gui::Window*, const std::string&, int, int, bool)>(
					base + idaOffsetFix(0x5C140)
					)(this, w, text, x, y, align);
			}
		};
	}
}
#endif
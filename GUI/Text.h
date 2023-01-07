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
		};
	}
}
#endif
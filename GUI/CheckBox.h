#pragma once
#ifndef GUI_CHECKBOX_H
#define GUI_CHECKBOX_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class CheckBox : public Element
		{
		public:
			std::string text;
			bool clickable;
			bool mouseDown;
			bool selected;
			PAD(1);
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			PAD(4);
			void* user;
			void* callback;
			bool checked;
		};
	}
}
#endif
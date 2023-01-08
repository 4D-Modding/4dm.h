#pragma once
#ifndef GUI_BTN_H
#define GUI_BTN_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		using ButtonCallback = std::add_pointer<void(void* user)>::type;

		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class Button : public Element
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
			int width;
			int height;
			PAD(4);
			void* user;
			ButtonCallback* callback = NULL;
		};
	}
}
#endif
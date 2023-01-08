#pragma once
#ifndef GUI_SLIDER_H
#define GUI_SLIDER_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		using SliderCallback = std::add_pointer<void(void* user, int value)>::type;

		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class Slider : public Element
		{
		public:
			const int height;
			std::string text;
			bool clickable;
			bool mouseDown;
			bool selected;
			PAD(1);
			int range;
			int width;
			int value;
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			void* user;
			SliderCallback callback;
		};
	}
}
#endif
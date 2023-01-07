#pragma once
#ifndef GUI_TEXTINPUT_H
#define GUI_TEXTINPUT_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class TextInput : public Element
		{
		public:
			static const int maxScrollPos;
			static const float cursorBlinkTime;
			static const float lastTypedCharTime;
			std::string text;
			bool enabled;
			bool mouseDown;
			bool active;
			bool highlight;
			int cursorPos;
			int highlightStart;
			unsigned int height;
			unsigned int width;
			int scrollPos;
			float cursorBlinkTimer;
			float lastTypedCharTimer;
			int lastTypedCharIndex;
			int xOffset;
			int yOffset;
			enum AlignmentX xAlign;
			enum AlignmentY yAlign;
			PAD(4);
			void* user;
			void* callback;
		};
	}
}
#endif
#pragma once
#ifndef GUI_CONTENTBOX_H
#define GUI_CONTENTBOX_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Element;
		class Window;
		class ElemContainer;
		enum AlignmentX;
		enum AlignmentY;
		class ContentBox : public Element, public Window, public ElemContainer 
		{
		public:
			static const int scrollbarWidth;
			Window* parent;
			std::vector<Element*> elements;
			int selectedElemIndex;
			bool active;
			PAD(3);
			unsigned int width;
			unsigned int height;
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			int xScroll;
			int yScroll;
			unsigned int scrollW;
			unsigned int scrollH;
			bool scrollingX;
			bool scrollingY;
			PAD(2);
			int scrollbarClickPos;
			int scrollStep;
			bool viewUpdateFlag;

			void addElement(Element* e) override
			{
				reinterpret_cast<void(__thiscall*)(gui::ContentBox*, Element*)> (
					base + idaOffsetFix(0x5B660)
					)(this, e);
			}
		};
	}
}
#endif
#pragma once
#ifndef GUI_ELEMENT_H
#define GUI_ELEMENT_H
#include "gui.h"
#include "Window.h"
namespace fdm
{
	namespace gui
	{
		class Window;
		enum AlignmentX;
		enum AlignmentY;
		class Element
		{
		public:
			virtual void render(Window*) = NULL;
			virtual void alignX(AlignmentX) = NULL;
			virtual void alignY(AlignmentY) = NULL;
			virtual void offsetX(int) = NULL;
			virtual void offsetY(int) = NULL;
			virtual void getPos(const Window*, int*, int*) = NULL;
			virtual void getSize(const Window*, int*, int*) = NULL;
			virtual void mouseInput(const Window*, long double, long double) = NULL;
			virtual bool scrollInput(const Window*, long double, long double) = NULL;
			virtual bool mouseButtonInput(const Window*, int, int, int) = NULL;
			virtual bool keyInput(const Window*, int, int, int, int) = NULL;
			virtual bool charInput(const Window*, unsigned int) = NULL;
			virtual bool enabled() = NULL;
			virtual void select() = NULL;
			virtual void deselect() = NULL;
		};
	}
}
#endif
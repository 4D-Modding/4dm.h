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
			virtual void render(Window*) {};
			virtual void alignX(AlignmentX) {};
			virtual void alignY(AlignmentY) {};
			virtual void offsetX(int) {};
			virtual void offsetY(int) {};
			virtual void getPos(const Window*, int*, int*) {};
			virtual void getSize(const Window*, int*, int*) {};
			virtual void mouseInput(const Window*, long double, long double) {};
			virtual bool scrollInput(const Window*, long double, long double) { return NULL; };
			virtual bool mouseButtonInput(const Window*, int, int, int) { return NULL; };
			virtual bool keyInput(const Window*, int, int, int, int) { return NULL; };
			virtual bool charInput(const Window*, unsigned int) { return NULL; };
			virtual bool enabled() { return NULL; };
			virtual void select() {};
			virtual void deselect() {};
		};
	}
}
#endif
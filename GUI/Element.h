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
			virtual void render(Window* w) {}
			virtual void alignX(AlignmentX a) {}
			virtual void alignY(AlignmentY a) {}
			virtual void offsetX(int offset) {}
			virtual void offsetY(int offset) {}
			virtual void getPos(const Window* w, int* x, int* y) {}
			virtual void getSize(const Window* w, int* width, int* height) {}
			virtual void mouseInput(const Window* w, double xPos, double yPos) {}
			virtual bool scrollInput(const Window* w, double xOff, double yOff) { return NULL; }
			virtual bool mouseButtonInput(const Window* w, int button, int action, int mods) { return NULL; }
			virtual bool keyInput(const Window* w, int key, int scancode, int action, int mods) { return NULL; }
			virtual bool charInput(const Window* w, unsigned int codepoint) { return NULL; }
			virtual bool enabled() { return NULL; }
			virtual void select() {}
			virtual void deselect() {}
		};
	}
}
#endif
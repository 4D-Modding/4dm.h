#pragma once
#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Window 
		{
		public:
			virtual QuadRenderer* getQuadRenderer();
			virtual FontRenderer* getFont();
			virtual GLFWwindow* getGLFWwindow();
			virtual void getCursorPos(int*, int*);
			virtual void getSize(int*, int*);
			virtual void changeViewport(const glm::ivec4*, const glm::ivec2*);
		};
	}
}
#endif
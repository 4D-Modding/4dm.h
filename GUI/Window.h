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
			virtual QuadRenderer* getQuadRenderer() = NULL;
			virtual FontRenderer* getFont() = NULL;
			virtual GLFWwindow* getGLFWwindow() = NULL;
			virtual void getCursorPos(int*, int*) = NULL;
			virtual void getSize(int*, int*) = NULL;
			virtual void changeViewport(const glm::ivec4*, const glm::ivec2*) = NULL;
		};
	}
}
#endif
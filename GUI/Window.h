#pragma once
#ifndef GUI_WINDOW_H
#define GUI_WINDOW_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class QuadRenderer;
		class FontRenderer;
		class Window 
		{
		public:
			virtual QuadRenderer* getQuadRenderer() { return NULL; };
			virtual FontRenderer* getFont() { return NULL; };
			virtual GLFWwindow* getGLFWwindow() { return NULL; };
			virtual void getCursorPos(int*, int*) { };
			virtual void getSize(int*, int*) { };
			virtual void changeViewport(const glm::ivec4&, const glm::ivec2&) { };
		};
	}
}
#endif
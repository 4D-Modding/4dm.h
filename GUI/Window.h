#pragma once

#include "gui.h"

namespace fdm::gui
{
	class Window 
	{
	public:
		// VIRTUAL FUNCS

		virtual QuadRenderer* getQuadRenderer() = NULL;
		virtual FontRenderer* getFont() = NULL;
		virtual GLFWwindow* getGLFWwindow() = NULL;
		virtual void getCursorPos(int * x, int * y) = NULL;
		virtual void getSize(int * width, int * height) = NULL;
		virtual void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) = NULL;
	};
}

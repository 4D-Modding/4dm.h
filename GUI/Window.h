#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::Window 
	{
	public:



		// VIRTUAL FUNCS

		virtual QuadRenderer getQuadRenderer() = NULL;
		virtual FontRenderer getFont() = NULL;
		virtual GLFWwindow getGLFWwindow() = NULL;
		virtual void getCursorPos(int *, int *) = NULL;
		virtual void getSize(int *, int *) = NULL;
		virtual void changeViewport(const glm::ivec4&, const glm::ivec2&) = NULL;
	};
}

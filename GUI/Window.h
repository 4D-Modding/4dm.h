#pragma once

//#include "gui.h"
#include "../4dm.h"

namespace fdm
{
	class QuadRenderer;
	class FontRenderer;
	
	namespace gui
	{
		class Window
		{
		public:
			virtual QuadRenderer* getQuadRenderer() { return NULL; }
			virtual FontRenderer* getFont() { return NULL; }
			virtual GLFWwindow* getGLFWwindow() { return NULL; }
			virtual void getCursorPos(int* x, int* y) { }
			virtual void getSize(int* width, int* height) { }
			virtual void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) { }
		};
	}
}

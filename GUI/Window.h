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
			virtual QuadRenderer* getQuadRenderer() const { return NULL; }
			virtual FontRenderer* getFont() const { return NULL; }
			virtual GLFWwindow* getGLFWwindow() const { return NULL; }
			virtual void getCursorPos(int* x, int* y) const { }
			virtual void getSize(int* width, int* height) const { }
			virtual void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) { }
		};
	}
}

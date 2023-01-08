#pragma once
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H
#include "gui.h"
namespace fdm 
{
	namespace gui 
	{
		using ViewportCallback = std::add_pointer<void(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>::type;

		class Window;
		class ElemContainer;
		class Element;
		class QuadRenderer;
		class FontRenderer;
		class Interface : public Window, public ElemContainer
		{
		public:
			std::vector<Element*> elements;
			int selectedElemIndex;
			PAD(4);
			QuadRenderer* qr;
			FontRenderer* font;
			GLFWwindow* window;
			ViewportCallback viewportCallback = NULL;
			void* viewportUser;
			bool viewUpdateFlag;
		};
	}
}
#endif
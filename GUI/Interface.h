#pragma once
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H
#include "gui.h"
namespace fdm 
{
	namespace gui 
	{
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
			void* viewportCallback;
			void* viewportUser;
			bool viewUpdateFlag;
		};
	}
}
#endif
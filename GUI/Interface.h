#pragma once
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H
#include "../4dm.h"
#include "gui.h"
#include "Window.h"
namespace fdm 
{
	namespace gui 
	{
		class Window;
		class ElemContainer;
		class Interface : public Window, public ElemContainer
		{

		};
	}
}
#endif
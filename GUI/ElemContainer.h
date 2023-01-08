#pragma once
#ifndef GUI_ELEMCONTAINER_H
#define GUI_ELEMCONTAINER_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Element;
		class ElemContainer
		{
		public:
			virtual void addElement(Element*) = NULL;
			virtual bool removeElement(Element*) = NULL;
			virtual bool selectElement(Element*) = NULL;
			virtual void clear() = NULL;
			virtual bool empty() = NULL;
		};
	}
}
#endif
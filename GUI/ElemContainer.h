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
			virtual void addElement(Element*) {};
			virtual bool removeElement(Element*) { return NULL; };
			virtual bool selectElement(Element*) { return NULL; };
			virtual void clear() {};
			virtual bool empty() { return NULL; };
		};
	}
}
#endif
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
			virtual void addElement(Element*);
			virtual bool removeElement(Element*);
			virtual bool selectElement(Element*);
			virtual void clear();
			virtual bool empty();
		};
	}
}
#endif
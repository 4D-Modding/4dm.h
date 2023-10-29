#pragma once

#include "4dm.h"

namespace fdm 
{
	class gui::ElemContainer 
	{
	public:



		// VIRTUAL FUNCS

		virtual void addElement(gui::Element *) = NULL;
		virtual bool removeElement(gui::Element *) = NULL;
		virtual bool selectElement(gui::Element *) = NULL;
		virtual void clear() = NULL;
		virtual bool empty() = NULL;
	};
}

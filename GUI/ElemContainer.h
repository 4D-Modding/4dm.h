#pragma once

#include "gui.h"

namespace fdm::gui
{
	class ElemContainer 
	{
	public:
		// VIRTUAL FUNCS
		virtual void addElement(gui::Element * element) = NULL;
		virtual bool removeElement(gui::Element * element) = NULL;
		virtual bool selectElement(gui::Element * element) = NULL;
		virtual void clear() = NULL;
		virtual bool empty() = NULL;
	};
}

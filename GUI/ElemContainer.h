#pragma once

#include "gui.h"

namespace fdm::gui
{
	class Element;
	class ElemContainer 
	{
	public:
		// VIRTUAL FUNCS
		virtual void addElement(gui::Element * element) { }
		virtual bool removeElement(gui::Element * element) { return false; }
		virtual bool selectElement(gui::Element * element) { return false; }
		virtual void clear() { }
		virtual bool empty() { return false; }
	};
}

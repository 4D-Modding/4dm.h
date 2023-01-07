#pragma once
#ifndef GUI_ALIGNMENT_H
#define GUI_ALIGNMENT_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		enum AlignmentX 
		{
			ALIGN_LEFT = 0,
			ALIGN_RIGHT = 1,
			ALIGN_CENTER_X = 2
		};
		enum AlignmentY
		{
			ALIGN_TOP = 0,
			ALIGN_BOTTOM = 1,
			ALIGN_CENTER_Y = 2
		};
	}
}
#endif
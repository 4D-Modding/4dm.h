#pragma once
#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H
#include "gui.h"
namespace fdm
{
	namespace gui
	{
		class Element;
		enum AlignmentX;
		enum AlignmentY;

		class Image : public Element
		{
		public:
			TexRenderer* tr;
			int xOffset;
			int yOffset;
			AlignmentX xAlign;
			AlignmentY yAlign;
			int width;
			int height;
		};
	}
}
#endif
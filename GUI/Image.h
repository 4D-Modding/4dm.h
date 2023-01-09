#pragma once
#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H
#include "gui.h"
#include "../Tex2D.h"
#include "../TexRenderer.h"
#include "../ShaderManager.h"
namespace fdm
{
	class Tex2D;
	class TexRenderer;
	class ShaderManager;
	namespace gui
	{
		class Element;
		class Window;
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
			
			void offsetX(int offset) override
			{
				this->xOffset = offset;
			}
			void offsetY(int offset) override
			{
				this->yOffset = offset;
			}
			void alignX(AlignmentX a) override
			{
				this->xAlign = a;
			}
			void alignY(AlignmentY a) override
			{
				this->yAlign = a;
			}
			void render(Window* w) override 
			{
				reinterpret_cast<void(__thiscall*)(Image*, Window*)>(
					base + idaOffsetFix(0x5C4C0)
					)(this, w);
			}
			void getPos(const Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(Image*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x5C5D0)
					)(this, w, x, y);
			}
			void getSize(const Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(Image*, const Window*, int*, int*)>(
					base + idaOffsetFix(0x5C6B0)
					)(this, w, width, height);
			}
			void loadImage(const std::string& path) // thats custom function (it doesnt exist in game) but it makes it easier to use Image
			{
				Tex2D* img = new Tex2D();
				img->load(path);
				TexRenderer* tr = new TexRenderer();
				tr->texture = img;
				tr->shader = ShaderManager::get("tex2DShader");
				tr->init();
				this->tr = tr;
				this->width = img->width;
				this->height = img->height;
			}
		};
	}
}
#endif
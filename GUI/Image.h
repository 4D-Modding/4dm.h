#pragma once
#ifndef GUI_IMAGE_H
#define GUI_IMAGE_H
#include "gui.h"
#include "../Tex2D.h"
#include "../TexRenderer.h"
#include "../ShaderManager.h"
#include "../ResourceManager.h"
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
					FUNC_GUI_IMAGE_RENDER
					)(this, w);
			}
			void getPos(const Window* w, int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(Image*, const Window*, int*, int*)>(
					FUNC_GUI_IMAGE_GETPOS
					)(this, w, x, y);
			}
			void getSize(const Window* w, int* width, int* height) override
			{
				reinterpret_cast<void(__thiscall*)(Image*, const Window*, int*, int*)>(
					FUNC_GUI_IMAGE_GETSIZE
					)(this, w, width, height);
			}
			// thats custom function (it doesnt exist in game) but it makes it easier to use Image
			void loadImage(const std::string& path, bool modFolder = false)
			{
				const Tex2D* img = ResourceManager::get(path, modFolder);
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

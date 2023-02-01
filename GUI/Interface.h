#pragma once
#ifndef GUI_INTERFACE_H
#define GUI_INTERFACE_H
#include "gui.h"
#include "../Shader.h"
#include "../ShaderManager.h"
namespace fdm 
{
	class QuadRenderer;
	class FontRenderer;
	namespace gui 
	{
		using ViewportCallback = std::add_pointer<void(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>::type;

		class Window;
		class ElemContainer;
		class Element;
		
		class Interface : public Window, public ElemContainer
		{
		public:
			std::vector<Element*> elements;
			int selectedElemIndex;
			PAD(4);
			QuadRenderer* qr;
			FontRenderer* font;
			GLFWwindow* window;
			ViewportCallback viewportCallback = NULL;
			void* viewportUser;
			bool viewUpdateFlag;
			
			~Interface() 
			{
				reinterpret_cast<void(__thiscall*)(Interface*)>(
					base + idaOffsetFix(0x3EF40)
					)(this);
			}
			void render()
			{
				reinterpret_cast<void(__thiscall*)(Interface*)>(
					base + idaOffsetFix(0x56280)
					)(this);
			}
			void mouseInput(double xPos, double yPos)
			{
				reinterpret_cast<void(__thiscall*)(Interface*, double, double)>(
					base + idaOffsetFix(0x56370)
					)(this, xPos, yPos);
			}
			bool scrollInput(double xOff, double yOff) 
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, double, double)>(
					base + idaOffsetFix(0x56400)
					)(this, xOff, yOff);
			}
			bool mouseButtonInput(int button, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, int, int, int)>(
					base + idaOffsetFix(0x564A0)
					)(this, button, action, mods);
			}
			bool keyInput(int key, int scancode, int action, int mods)
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, int, int, int, int)>(
					base + idaOffsetFix(0x565A0)
					)(this, key, scancode, action, mods);
			}
			QuadRenderer* getQuadRenderer() override 
			{
				return reinterpret_cast<QuadRenderer * (__thiscall*)(Interface*)>(
					base + idaOffsetFix(0x56750)
					)(this);
			}
			FontRenderer* getFont() override
			{
				return reinterpret_cast<FontRenderer * (__thiscall*)(Interface*)>(
					base + idaOffsetFix(0x56760)
					)(this);
			}
			GLFWwindow* getGLFWwindow() override
			{
				return reinterpret_cast<GLFWwindow * (__thiscall*)(Interface*)>(
					base + idaOffsetFix(0x56770)
					)(this);
			}
			void getCursorPos(int* x, int* y) override
			{
				reinterpret_cast<void(__thiscall*)(Interface*, int*, int*)>(
					base + idaOffsetFix(0x56780)
					)(this, x, y);
			}
			void getSize(int* w, int* h) override
			{
				reinterpret_cast<void(__thiscall*)(Interface*, int*, int*)>(
					base + idaOffsetFix(0x567E0)
					)(this, w, h);
			}
			void changeViewport(const glm::ivec4& pos, const glm::ivec2& scroll) override
			{
				reinterpret_cast<void(__thiscall*)(Interface*, const glm::ivec4&, const glm::ivec2&)>(
					base + idaOffsetFix(0x567F0)
					)(this, pos, scroll);
			}
			void addElement(Element* e) override 
			{
				reinterpret_cast<void(__thiscall*)(Interface*, Element*) > (
					base + idaOffsetFix(0x56810)
					)(this, e);
			}
			bool removeElement(Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, Element*)> (
					base + idaOffsetFix(0x56850)
					)(this, e);
			}
			bool selectElement(Element* e) override
			{
				return reinterpret_cast<bool(__thiscall*)(Interface*, Element*)> (
					base + idaOffsetFix(0x568E0)
					)(this, e);
			}
			void clear() override 
			{
				reinterpret_cast<void(__thiscall*)(Interface*)> (
					base + idaOffsetFix(0x569A0)
					)(this);
			}
			bool empty() override
			{
				reinterpret_cast<bool(__thiscall*)(Interface*)> (
					base + idaOffsetFix(0x569F0)
					)(this);
			}
		};
	}
}
#endif
#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateTutorialSlideshow : public State 
	{
	public:
		inline static StateTutorialSlideshow* instanceObj = reinterpret_cast<StateTutorialSlideshow*>((base + 0x2C1E80));
		bool updateViewFlag; // 0x8
		PAD(0x7);
		FontRenderer font; // 0x10
		QuadRenderer qr; // 0xB0
		Shader* qs; // 0xD8
		gui::Interface ui; // 0xE0
		gui::Button continueButton; // 0x148
		gui::Button backButton; // 0x1A0
		gui::Button exitButton; // 0x1F8
		inline static const int slide_box_count = 4; 
		gui::ContentBox slides[4]; // 0x250
		int currentSlide; // 0x450
		PAD(0x4);
		gui::Text slide0_text1; // 0x458
		gui::Text slide0_text2; // 0x4B0
		gui::Image comparisonImage; // 0x508
		TexRenderer comparisonImageRenderer; // 0x530
		gui::Text slide1_text1; // 0x558
		gui::Text slide1_text2; // 0x5B0
		gui::Text slide1_text3; // 0x608
		gui::Image forgImage; // 0x660
		float forgAnimStart; // 0x688
		TexRenderer forgImageTexRenderer; // 0x690
		gui::Image crossSectionImage; // 0x6B8
		TexRenderer crossSectionImageRenderer; // 0x6E0
		gui::Text slide2_text1; // 0x708
		gui::Text slide2_text2; // 0x760
		gui::Image crossSectionImage1; // 0x7B8
		gui::Image crossSectionImage2; // 0x7E0
		TexRenderer crossSectionImage2Renderer; // 0x808
		gui::Text slide3_text1; // 0x830
		gui::Text slide3_text2; // 0x888
		gui::Text slide3_text3; // 0x8E0
		gui::Text slide3_text4; // 0x938
		gui::Image rotation4D; // 0x990
		TexRenderer rotation4DRenderer; // 0x9B8

		~StateTutorialSlideshow() 
		{
			reinterpret_cast<void(__thiscall*)(StateTutorialSlideshow* self)>(FUNC_STATETUTORIALSLIDESHOW_DESTR_STATETUTORIALSLIDESHOW)(this);
		}
		StateTutorialSlideshow() 
		{
			reinterpret_cast<void(__thiscall*)(StateTutorialSlideshow* self)>(FUNC_STATETUTORIALSLIDESHOW_STATETUTORIALSLIDESHOW)(this);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(FUNC_STATETUTORIALSLIDESHOW_UPDATEPROJECTION)(this, size, translate2D);
		}
		void updateSlideSize(int width, int height) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, int width, int height)>(FUNC_STATETUTORIALSLIDESHOW_UPDATESLIDESIZE)(this, width, height);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(FUNC_STATETUTORIALSLIDESHOW_VIEWPORTCALLBACK)(user, pos, scroll);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, StateManager& s)>(FUNC_STATETUTORIALSLIDESHOW_INIT)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, StateManager& s, double dt)>(FUNC_STATETUTORIALSLIDESHOW_UPDATE)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, StateManager& s)>(FUNC_STATETUTORIALSLIDESHOW_RENDER)(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, StateManager& s)>(FUNC_STATETUTORIALSLIDESHOW_RESUME)(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, StateManager& s, int width, int height)>(FUNC_STATETUTORIALSLIDESHOW_WINDOWRESIZE)(this, s, width, height);
		}
		inline static void continueButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETUTORIALSLIDESHOW_CONTINUEBUTTONCALLBACK)(user);
		}
		inline static void backButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATETUTORIALSLIDESHOW_BACKBUTTONCALLBACK)(user);
		}
		void setSlide(StateManager& s, int index) 
		{
			return reinterpret_cast<void (__thiscall*)(StateTutorialSlideshow* self, StateManager& s, int index)>(FUNC_STATETUTORIALSLIDESHOW_SETSLIDE)(this, s, index);
		}
	};
}

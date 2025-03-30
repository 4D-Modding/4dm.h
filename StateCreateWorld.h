#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateCreateWorld : public State 
	{
	public:
		inline static StateCreateWorld& instanceObj = *reinterpret_cast<StateCreateWorld*>(getDataAddr((int)Data::StateCreateWorld::instanceObj));
		bool updateViewFlag; // 0x8
		PAD(0x7);
		FontRenderer font; // 0x10
		QuadRenderer qr; // 0xB0
		Shader* qs; // 0xD8
		gui::Interface ui; // 0xE0
		gui::Button createButton; // 0x148
		gui::Button cancelButton; // 0x1A0
		gui::Text worldNameText; // 0x1F8
		gui::Text worldSeedText; // 0x250
		gui::Text noNameErrorMsg; // 0x2A8
		gui::TextInput worldNameInput; // 0x300
		gui::TextInput worldSeedInput; // 0x390
		gui::CheckBox flatWorldCheckBox; // 0x420
		gui::CheckBox caveCheckbox; // 0x478
		gui::Slider caveSizeSlider; // 0x4D0
		gui::Slider biomeSizeSlider; // 0x528
		gui::Slider amplificationSlider; // 0x580
		inline static constexpr const float maxCaveSizeF = 0.85f;
		inline static constexpr const int minCaveSize = 10;
		inline static constexpr const int maxCaveSize = 340;
		inline static constexpr const int minBiomeSize = 10;
		inline static constexpr const int maxBiomeSize = 500;
		inline static constexpr const int minAmplification = 0;
		inline static constexpr const int maxAmplification = 500;

		StateCreateWorld() 
		{
			reinterpret_cast<void(__thiscall*)(StateCreateWorld* self)>(getFuncAddr((int)Func::StateCreateWorld::StateCreateWorld))(this);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s)>(getFuncAddr((int)Func::StateCreateWorld::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s)>(getFuncAddr((int)Func::StateCreateWorld::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateCreateWorld::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s)>(getFuncAddr((int)Func::StateCreateWorld::render))(this, s);
		}
		void resume(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s)>(getFuncAddr((int)Func::StateCreateWorld::resume))(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateCreateWorld::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateCreateWorld::scrollInput))(this, s, xoffset, yoffset);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::StateCreateWorld::keyInput))(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateCreateWorld::windowResize))(this, s, width, height);
		}
		void charInput(StateManager& s, uint32_t codepoint) override
		{
			return reinterpret_cast<void (__thiscall*)(StateCreateWorld* self, StateManager& s, uint32_t codepoint)>(getFuncAddr((int)Func::StateCreateWorld::charInput))(this, s, codepoint);
		}
		inline static void amplificationSliderCallback(void* user, int value)
		{
			return reinterpret_cast<void(__fastcall*)(void*, int)>(getFuncAddr((int)Func::StateCreateWorld::amplificationSliderCallback))(user, value);
		}
		inline static void biomeSizeSliderCallback(void* user, int value)
		{
			return reinterpret_cast<void(__fastcall*)(void*, int)>(getFuncAddr((int)Func::StateCreateWorld::biomeSizeSliderCallback))(user, value);
		}
		inline static void caveCheckboxCallback(void* user, bool checked)
		{
			return reinterpret_cast<void(__fastcall*)(void*, bool)>(getFuncAddr((int)Func::StateCreateWorld::caveCheckboxCallback))(user, checked);
		}
		inline static void caveSizeSliderCallback(void* user, int value)
		{
			return reinterpret_cast<void(__fastcall*)(void*, int)>(getFuncAddr((int)Func::StateCreateWorld::caveSizeSliderCallback))(user, value);
		}
		inline static void createNewWorld(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StateCreateWorld::createNewWorld))(user);
		}
		inline static void createWorldCancel(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StateCreateWorld::createWorldCancel))(user);
		}
		inline static void updateAmplificationSliderText()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::StateCreateWorld::updateAmplificationSliderText))();
		}
		inline static void updateBiomeSizeSliderText()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::StateCreateWorld::updateBiomeSizeSliderText))();
		}
		inline static void updatecaveSizeSliderText()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::StateCreateWorld::updatecaveSizeSliderText))();
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)
		{
			return reinterpret_cast<void(__fastcall*)(void*, const glm::ivec4&, const glm::ivec2&)>(getFuncAddr((int)Func::StateCreateWorld::viewportCallback))(user, pos, scroll);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D)
		{
			return reinterpret_cast<void(__thiscall*)(StateCreateWorld * self, const glm::ivec2&, const glm::ivec2&)>(getFuncAddr((int)Func::StateCreateWorld::updateProjection))(this, size, translate2D);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void(__thiscall*)(StateCreateWorld * self, StateManager&, int, int, int)>(getFuncAddr((int)Func::StateCreateWorld::mouseButtonInput))(this, s, button, action, mods);
		}
		bool handleCreateButton() 
		{
			return reinterpret_cast<bool (__thiscall*)(StateCreateWorld* self)>(getFuncAddr((int)Func::StateCreateWorld::handleCreateButton))(this);
		}
	};
}

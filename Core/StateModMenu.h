#pragma once

#include "../4dm.h"

#include "Counter.h"
#include "BetterText.h"
#include "ModElement.h"

namespace fdm::Core
{
	// this is a mess
	class StateModMenu : public State
	{
	public:
		template<typename T>
		inline static bool compareSets(const std::set<T>& a, const std::set<T>& b)
		{
			return a.size() == b.size() & std::equal(a.begin(), a.end(), b.begin(), b.end());
		}

		inline static StateModMenu& instanceObj = *reinterpret_cast<StateModMenu*>(getDataAddr((int)Data::Core::StateModMenu::instanceObj));

		QuadRenderer qr;
		const Shader* qs;
		const Shader* tex2DShader;
		const Shader* textShader;
		FontRenderer font;

		glm::mat4 proj2D;
		bool updateViewFlag = true;

		gui::Interface ui;
		gui::Text title;
		gui::Button closeBtn;
		TexRenderer closeBtnTex;
		gui::Image closeBtnImg;
		gui::Text loadedModsCount;
		gui::ContentBox modList;
		gui::ContentBox modInfo;
		bool initializedNewSelectedMods = false;
		inline static std::set<ModID>& newSelectedMods = *reinterpret_cast<std::set<ModID>*>(getDataAddr((int)Data::Core::StateModMenu::newSelectedMods));
		gui::Text warningToRestartTheGame;
		ModElement* modToView;
		bool dontForgetToUpdateFunnyBoxes = false;

		StateModMenu() {}

		void updateProjection()
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu* self)>(getFuncAddr((int)Func::Core::StateModMenu::updateProjection))(this);
		}
		inline static void viewportCallbackFunc(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)
		{
			reinterpret_cast<void(__fastcall*)(void* user, const glm::ivec4 & pos, const glm::ivec2 & scroll)>(getFuncAddr((int)Func::Core::StateModMenu::viewportCallbackFunc))(user, pos, scroll);
		}
		inline static void closeBtnCallback(void* user)
		{
			reinterpret_cast<void(__fastcall*)(void* user)>(getFuncAddr((int)Func::Core::StateModMenu::closeBtnCallback))(user);
		}
		void modSelectionCallback(ModElement* mod)
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, ModElement * mod)>(getFuncAddr((int)Func::Core::StateModMenu::modSelectionCallback))(this, mod);
		}
		void init(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager& s)>(getFuncAddr((int)Func::Core::StateModMenu::init))(this, s);
		}
		inline static void enableCheckboxCallback(void* user, bool checked)
		{
			reinterpret_cast<void(__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::Core::StateModMenu::enableCheckboxCallback))(user, checked);
		}
		void update(StateManager& s, double dt) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s, double dt)>(getFuncAddr((int)Func::Core::StateModMenu::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s)>(getFuncAddr((int)Func::Core::StateModMenu::render))(this, s);
		}
		void resume(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s)>(getFuncAddr((int)Func::Core::StateModMenu::resume))(this, s);
		}
		void updateFunnyBoxes(int w, int h)
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, int w, int h)>(getFuncAddr((int)Func::Core::StateModMenu::updateFunnyBoxes))(this, w, h);
		}
		void windowResize(StateManager& s, int w, int h) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s, int w, int h)>(getFuncAddr((int)Func::Core::StateModMenu::windowResize))(this, s, w, h);
		}
		void mouseInput(StateManager& s, double xPos, double yPos) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s, double xPos, double yPos)>(getFuncAddr((int)Func::Core::StateModMenu::mouseInput))(this, s, xPos, yPos);
		}
		void scrollInput(StateManager& s, double xOff, double yOff) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s, double xOff, double yOff)>(getFuncAddr((int)Func::Core::StateModMenu::scrollInput))(this, s, xOff, yOff);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::Core::StateModMenu::keyInput))(this, s, key, scancode, action, mods);
		}
		void mouseButtonInput(StateManager& s, int btn, int action, int mods) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s, int btn, int action, int mods)>(getFuncAddr((int)Func::Core::StateModMenu::mouseButtonInput))(this, s, btn, action, mods);
		}
		void close(StateManager& s) override
		{
			reinterpret_cast<void(__thiscall*)(StateModMenu * self, StateManager & s)>(getFuncAddr((int)Func::Core::StateModMenu::close))(this, s);
		}
	};
}

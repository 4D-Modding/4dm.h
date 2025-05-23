#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateSettings : public State 
	{
	public:
		inline static const int DEFAULT_WINDOW_WIDTH = 1024; 
		inline static const int DEFAULT_WINDOW_HEIGHT = 768; 
		inline static StateSettings& instanceObj = *reinterpret_cast<StateSettings*>(getDataAddr((int)Data::StateSettings::instanceObj));
		FontRenderer font; // 0x8
		QuadRenderer qr; // 0xA8
		Shader* qs; // 0xD0
		gui::Interface ui; // 0xD8
		bool updateViewFlag; // 0x140
		PAD(0x7);
		gui::Text settingsTitleText; // 0x148
		gui::ContentBox mainContentBox; // 0x1A0
		int mainContentHeight; // 0x220
		PAD(0x4);
		gui::Button okButton; // 0x228
		gui::Button openControlsButton; // 0x280
		gui::Button fullscreenButton; // 0x2D8
		gui::Slider renderDistanceSlider; // 0x330
		gui::Slider scrollSensitivitySlider; // 0x388
		gui::Slider lookSensitivitySlider; // 0x3E0
		gui::CheckBox xInvertCheckBox; // 0x438
		gui::CheckBox yInvertCheckBox; // 0x490
		gui::Slider difficultySlider; // 0x4E8
		gui::Slider fovSlider; // 0x540
		gui::CheckBox smoothLightingCheckBox; // 0x598
		gui::CheckBox shadowsCheckBox; // 0x5F0
		gui::CheckBox lightsCheckBox; // 0x648
		gui::Text audioText; // 0x6A0
		gui::Slider globalVolumeSlider; // 0x6F8
		gui::Slider musicVolumeSlider; // 0x750
		gui::Slider creatureVolumeSlider; // 0x7A8
		gui::Slider ambienceVolumeSlider; // 0x800
		gui::Text multiplayerText; // 0x858
		gui::CheckBox chatCheckBox; // 0x8B0
		gui::CheckBox nametagsCheckBox; // 0x908
		gui::CheckBox skinsCheckBox; // 0x960
		gui::Button secretButton; // 0x9B8
		int prevWindowWidth; // 0xA10
		int prevWindowHeight; // 0xA14
		bool fullscreen; // 0xA18
		bool smoothLighting; // 0xA19
		bool shadows; // 0xA1A
		bool lights; // 0xA1B
		bool lightingOptionsChanged; // 0xA1C
		inline static constexpr const int maxRenderDistance = 12;
		inline static constexpr const int defaultRenderDistance = 4;
		PAD(0x3);
		int currentRenderDistance; // 0xA20
		inline static constexpr const int maxScrollSensitivity = 200;
		inline static constexpr const int defaultScrollSensitivity = 100;
		int currentScrollSensitivity; // 0xA24
		bool xInvert; // 0xA28
		bool yInvert; // 0xA29
		inline static constexpr const int maxLookSensitivity = 4;
		inline static constexpr const int defaultLookSensitivity = 2;
		PAD(0x2);
		int currentLookSensitivity; // 0xA2C
		inline static constexpr const int minFOV = 30;
		inline static constexpr const int maxFOV = 149;
		inline static constexpr const int defaultFOV = 55;
		int currentFOV; // 0xA30
		inline static constexpr const int maxVolume = 100;
		inline static constexpr const int defaultVolume = 70;
		int currentGlobalVolume; // 0xA34
		int currentMusicVolume; // 0xA38
		int currentCreatureVolume; // 0xA3C
		int currentAmbienceVolume; // 0xA40
		inline static constexpr const int minDifficulty = 0;
		inline static constexpr const int maxDifficulty = 2;
		inline static constexpr const int defaultDifficulty = 1;
		int currentDifficulty; // 0xA44
		bool chat; // 0xA48
		bool nametags; // 0xA49
		bool skins; // 0xA4A
		PAD(0x5);
		gui::Interface controls; // 0xA50
		bool controlsMenuOpened; // 0xAB8
		PAD(0x7);
		gui::Text controlsTitleText; // 0xAC0
		gui::ContentBox controlsContentBox; // 0xB18
		gui::Button controlsOkButton; // 0xB98
		gui::Text controlsText; // 0xBF0

		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateSettings::updateProjection))(this, size, translate2D);
		}
		~StateSettings() 
		{
			reinterpret_cast<void(__thiscall*)(StateSettings* self)>(getFuncAddr((int)Func::StateSettings::destr_StateSettings))(this);
		}
		StateSettings() 
		{
			reinterpret_cast<void(__thiscall*)(StateSettings* self)>(getFuncAddr((int)Func::StateSettings::StateSettings))(this);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void(__thiscall*)(StateSettings * self, StateManager&, double)>(getFuncAddr((int)Func::StateSettings::update))(this, s, dt);
		}
		const nlohmann::json& getSetting(const stl::string& settingName, const nlohmann::json& settings, const nlohmann::json& defaultSettings)
		{
			return reinterpret_cast<const nlohmann::json& (__thiscall*)(StateSettings* self, const stl::string& settingName, const nlohmann::json& settings, const nlohmann::json& defaultSettings)>(getFuncAddr((int)Func::StateSettings::getSetting))(this, settingName, settings, defaultSettings);
		}
		inline static void okButtonCallback(void* user)
		{
			return reinterpret_cast<void(__fastcall*)(void*)>(getFuncAddr((int)Func::StateSettings::okButtonCallback))(user);
		}
		inline static void renderDistanceSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::renderDistanceSliderCallback))(user, value);
		}
		inline static void scrollSensitivitySliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::scrollSensitivitySliderCallback))(user, value);
		}
		inline static void lookSensitivitySliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::lookSensitivitySliderCallback))(user, value);
		}
		inline static void xInvertCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::xInvertCheckBoxCallback))(user, checked);
		}
		inline static void yInvertCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::yInvertCheckBoxCallback))(user, checked);
		}
		inline static void fovSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::fovSliderCallback))(user, value);
		}
		inline static void globalVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::globalVolumeSliderCallback))(user, value);
		}
		inline static void musicVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::musicVolumeSliderCallback))(user, value);
		}
		inline static void creatureVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::creatureVolumeSliderCallback))(user, value);
		}
		inline static void ambienceVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::ambienceVolumeSliderCallback))(user, value);
		}
		inline static void controlsButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSettings::controlsButtonCallback))(user);
		}
		inline static void controlsOkButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSettings::controlsOkButtonCallback))(user);
		}
		inline static void fullscreenButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSettings::fullscreenButtonCallback))(user);
		}
		inline static void difficultySliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(getFuncAddr((int)Func::StateSettings::difficultySliderCallback))(user, value);
		}
		inline static void smoothLightingCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::smoothLightingCheckBoxCallback))(user, checked);
		}
		inline static void shadowsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::shadowsCheckBoxCallback))(user, checked);
		}
		inline static void lightsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::lightsCheckBoxCallback))(user, checked);
		}
		inline static void chatCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::chatCheckBoxCallback))(user, checked);
		}
		inline static void nametagsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::nametagsCheckBoxCallback))(user, checked);
		}
		inline static void skinsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(getFuncAddr((int)Func::StateSettings::skinsCheckBoxCallback))(user, checked);
		}
		inline static void secretButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSettings::secretButtonCallback))(user);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::StateSettings::viewportCallback))(user, pos, scroll);
		}
		void updateStateGame() 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self)>(getFuncAddr((int)Func::StateSettings::updateStateGame))(this);
		}
		void updateVolume() 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self)>(getFuncAddr((int)Func::StateSettings::updateVolume))(this);
		}
		void load(GLFWwindow* window) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, GLFWwindow* window)>(getFuncAddr((int)Func::StateSettings::load))(this, window);
		}
		void save() 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self)>(getFuncAddr((int)Func::StateSettings::save))(this);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s)>(getFuncAddr((int)Func::StateSettings::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s)>(getFuncAddr((int)Func::StateSettings::close))(this, s);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s)>(getFuncAddr((int)Func::StateSettings::render))(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateSettings::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateSettings::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateSettings::mouseButtonInput))(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::StateSettings::keyInput))(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateSettings::windowResize))(this, s, width, height);
		}
		void updateRenderDistance(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(getFuncAddr((int)Func::StateSettings::updateRenderDistance))(this, value);
		}
		void updateFOV(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(getFuncAddr((int)Func::StateSettings::updateFOV))(this, value);
		}
		void updateCreatureVolume(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(getFuncAddr((int)Func::StateSettings::updateCreatureVolume))(this, value);
		}
		void updateAmbienceVolume(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(getFuncAddr((int)Func::StateSettings::updateAmbienceVolume))(this, value);
		}
		void updateDifficulty(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(getFuncAddr((int)Func::StateSettings::updateDifficulty))(this, value);
		}
		void setFullscreenMode(GLFWwindow* window, bool fullscreenMode) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, GLFWwindow* window, bool fullscreenMode)>(getFuncAddr((int)Func::StateSettings::setFullscreenMode))(this, window, fullscreenMode);
		}
	};
}

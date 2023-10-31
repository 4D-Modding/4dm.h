#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateSettings : public State 
	{
	public:
		inline static const int DEFAULT_WINDOW_WIDTH = 1024; 
		inline static const int DEFAULT_WINDOW_HEIGHT = 768; 
		inline static StateSettings* instanceObj = reinterpret_cast<StateSettings*>((base + 0x2BFAE0));
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
		inline static const int maxRenderDistance = 12; 
		inline static const int defaultRenderDistance = 4; 
		PAD(0x3);
		int currentRenderDistance; // 0xA20
		inline static const int maxScrollSensitivity = 200; 
		inline static const int defaultScrollSensitivity = 100; 
		int currentScrollSensitivity; // 0xA24
		bool xInvert; // 0xA28
		bool yInvert; // 0xA29
		inline static const int maxLookSensitivity = 4; 
		inline static const int defaultLookSensitivity = 2; 
		PAD(0x2);
		int currentLookSensitivity; // 0xA2C
		inline static const int minFOV = 30; 
		inline static const int maxFOV = 149; 
		inline static const int defaultFOV = 55; 
		int currentFOV; // 0xA30
		inline static const int maxVolume = 100; 
		inline static const int defaultVolume = 70; 
		int currentGlobalVolume; // 0xA34
		int currentMusicVolume; // 0xA38
		int currentCreatureVolume; // 0xA3C
		int currentAmbienceVolume; // 0xA40
		inline static const int minDifficulty = NULL; 
		inline static const int maxDifficulty = 2; 
		inline static const int defaultDifficulty = 1; 
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
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(FUNC_STATESETTINGS_UPDATEPROJECTION)(this, size, translate2D);
		}
		~StateSettings() 
		{
			reinterpret_cast<void(__thiscall*)(StateSettings* self)>(FUNC_STATESETTINGS_DESTR_STATESETTINGS)(this);
		}
		StateSettings() 
		{
			reinterpret_cast<void(__thiscall*)(StateSettings* self)>(FUNC_STATESETTINGS_STATESETTINGS)(this);
		}
		nlohmann::json getSetting(std::string& settingName, nlohmann::json& settings, const nlohmann::json& defaultSettings) 
		{
			return reinterpret_cast<nlohmann::json (__thiscall*)(StateSettings* self, std::string& settingName, nlohmann::json& settings, const nlohmann::json& defaultSettings)>(FUNC_STATESETTINGS_GETSETTING)(this, settingName, settings, defaultSettings);
		}
		inline static void renderDistanceSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_RENDERDISTANCESLIDERCALLBACK)(user, value);
		}
		inline static void scrollSensitivitySliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_SCROLLSENSITIVITYSLIDERCALLBACK)(user, value);
		}
		inline static void lookSensitivitySliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_LOOKSENSITIVITYSLIDERCALLBACK)(user, value);
		}
		inline static void xInvertCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_XINVERTCHECKBOXCALLBACK)(user, checked);
		}
		inline static void yInvertCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_YINVERTCHECKBOXCALLBACK)(user, checked);
		}
		inline static void fovSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_FOVSLIDERCALLBACK)(user, value);
		}
		inline static void globalVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_GLOBALVOLUMESLIDERCALLBACK)(user, value);
		}
		inline static void musicVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_MUSICVOLUMESLIDERCALLBACK)(user, value);
		}
		inline static void creatureVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_CREATUREVOLUMESLIDERCALLBACK)(user, value);
		}
		inline static void ambienceVolumeSliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_AMBIENCEVOLUMESLIDERCALLBACK)(user, value);
		}
		inline static void controlsButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESETTINGS_CONTROLSBUTTONCALLBACK)(user);
		}
		inline static void controlsOkButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESETTINGS_CONTROLSOKBUTTONCALLBACK)(user);
		}
		inline static void fullscreenButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESETTINGS_FULLSCREENBUTTONCALLBACK)(user);
		}
		inline static void difficultySliderCallback(void* user, int value) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, int value)>(FUNC_STATESETTINGS_DIFFICULTYSLIDERCALLBACK)(user, value);
		}
		inline static void smoothLightingCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_SMOOTHLIGHTINGCHECKBOXCALLBACK)(user, checked);
		}
		inline static void shadowsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_SHADOWSCHECKBOXCALLBACK)(user, checked);
		}
		inline static void lightsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_LIGHTSCHECKBOXCALLBACK)(user, checked);
		}
		inline static void chatCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_CHATCHECKBOXCALLBACK)(user, checked);
		}
		inline static void nametagsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_NAMETAGSCHECKBOXCALLBACK)(user, checked);
		}
		inline static void skinsCheckBoxCallback(void* user, bool checked) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, bool checked)>(FUNC_STATESETTINGS_SKINSCHECKBOXCALLBACK)(user, checked);
		}
		inline static void secretButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESETTINGS_SECRETBUTTONCALLBACK)(user);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(FUNC_STATESETTINGS_VIEWPORTCALLBACK)(user, pos, scroll);
		}
		void updateStateGame() 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self)>(FUNC_STATESETTINGS_UPDATESTATEGAME)(this);
		}
		void updateVolume() 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self)>(FUNC_STATESETTINGS_UPDATEVOLUME)(this);
		}
		void load(GLFWwindow* window) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, GLFWwindow* window)>(FUNC_STATESETTINGS_LOAD)(this, window);
		}
		void save() 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self)>(FUNC_STATESETTINGS_SAVE)(this);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s)>(FUNC_STATESETTINGS_INIT)(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s)>(FUNC_STATESETTINGS_CLOSE)(this, s);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s)>(FUNC_STATESETTINGS_RENDER)(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, double xpos, double ypos)>(FUNC_STATESETTINGS_MOUSEINPUT)(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, double xoffset, double yoffset)>(FUNC_STATESETTINGS_SCROLLINPUT)(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, int button, int action, int mods)>(FUNC_STATESETTINGS_MOUSEBUTTONINPUT)(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, int key, int scancode, int action, int mods)>(FUNC_STATESETTINGS_KEYINPUT)(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, StateManager& s, int width, int height)>(FUNC_STATESETTINGS_WINDOWRESIZE)(this, s, width, height);
		}
		void updateRenderDistance(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(FUNC_STATESETTINGS_UPDATERENDERDISTANCE)(this, value);
		}
		void updateFOV(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(FUNC_STATESETTINGS_UPDATEFOV)(this, value);
		}
		void updateCreatureVolume(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(FUNC_STATESETTINGS_UPDATECREATUREVOLUME)(this, value);
		}
		void updateAmbienceVolume(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(FUNC_STATESETTINGS_UPDATEAMBIENCEVOLUME)(this, value);
		}
		void updateDifficulty(int value) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, int value)>(FUNC_STATESETTINGS_UPDATEDIFFICULTY)(this, value);
		}
		void setFullscreenMode(GLFWwindow* window, bool fullscreenMode) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSettings* self, GLFWwindow* window, bool fullscreenMode)>(FUNC_STATESETTINGS_SETFULLSCREENMODE)(this, window, fullscreenMode);
		}
	};
}

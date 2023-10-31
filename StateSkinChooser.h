#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateSkinChooser : public State 
	{
	public:
		inline static const std::string* defaultSkinPath = reinterpret_cast<const std::string*>((base + 0x2C0F40));
		inline static StateSkinChooser* instanceObj = reinterpret_cast<StateSkinChooser*>((base + 0x2C0F60));
		FontRenderer font; // 0x8
		QuadRenderer qr; // 0xA8
		Shader* qs; // 0xD0
		gui::Interface ui; // 0xD8
		bool updateViewFlag; // 0x140
		PAD(0x7);
		gui::Button okButton; // 0x148
		gui::Button chooseFileButton; // 0x1A0
		gui::Button resetOrientation; // 0x1F8
		gui::Button resetPosition; // 0x250
		std::string skinPath; // 0x2A8
		PlayerSkin skin; // 0x2C8
		PlayerSkinRenderer skinRenderer; // 0x418
		PlayerSkinViewer skinViewer; // 0x9A8

		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, double xpos, double ypos)>(FUNC_STATESKINCHOOSER_MOUSEINPUT)(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, double xoffset, double yoffset)>(FUNC_STATESKINCHOOSER_SCROLLINPUT)(this, s, xoffset, yoffset);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, uint32_t key, uint32_t scancode, int action, int mods)>(FUNC_STATESKINCHOOSER_KEYINPUT)(this, s, key, scancode, action, mods);
		}
		StateSkinChooser() 
		{
			reinterpret_cast<void(__thiscall*)(StateSkinChooser* self)>(FUNC_STATESKINCHOOSER_STATESKINCHOOSER)(this);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(FUNC_STATESKINCHOOSER_UPDATEPROJECTION)(this, size, translate2D);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(FUNC_STATESKINCHOOSER_VIEWPORTCALLBACK)(user, pos, scroll);
		}
		inline static void chooseFileButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(FUNC_STATESKINCHOOSER_CHOOSEFILEBUTTONCALLBACK)(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s)>(FUNC_STATESKINCHOOSER_INIT)(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s)>(FUNC_STATESKINCHOOSER_CLOSE)(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, double dt)>(FUNC_STATESKINCHOOSER_UPDATE)(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s)>(FUNC_STATESKINCHOOSER_RENDER)(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, int width, int height)>(FUNC_STATESKINCHOOSER_WINDOWRESIZE)(this, s, width, height);
		}
		void fileDrop(StateManager& s, int path_count, const char* *paths) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, int path_count, const char* *paths)>(FUNC_STATESKINCHOOSER_FILEDROP)(this, s, path_count, paths);
		}
		Connection::OutMessage getSkinMessage() 
		{
			Connection::OutMessage result;
			return reinterpret_cast<Connection::OutMessage (__thiscall*)(StateSkinChooser* self, Connection::OutMessage* result)>(FUNC_STATESKINCHOOSER_GETSKINMESSAGE)(this, &result);
		}
		bool loadSkin(path* p) 
		{
			return reinterpret_cast<bool (__thiscall*)(StateSkinChooser* self, path* p)>(FUNC_STATESKINCHOOSER_LOADSKIN)(this, p);
		}
	};
}

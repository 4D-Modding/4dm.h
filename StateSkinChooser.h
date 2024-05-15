#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateSkinChooser : public State 
	{
	public:
		inline static const stl::string* defaultSkinPath = reinterpret_cast<const stl::string*>((base + 0x2C0F40));
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
		stl::string skinPath; // 0x2A8
		PlayerSkin skin; // 0x2C8
		PlayerSkinRenderer skinRenderer; // 0x418
		PlayerSkinViewer skinViewer; // 0x9A8

		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateSkinChooser::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateSkinChooser::scrollInput))(this, s, xoffset, yoffset);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, uint32_t key, uint32_t scancode, int action, int mods)>(getFuncAddr((int)Func::StateSkinChooser::keyInput))(this, s, key, scancode, action, mods);
		}
		StateSkinChooser() 
		{
			reinterpret_cast<void(__thiscall*)(StateSkinChooser* self)>(getFuncAddr((int)Func::StateSkinChooser::StateSkinChooser))(this);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateSkinChooser::updateProjection))(this, size, translate2D);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::StateSkinChooser::viewportCallback))(user, pos, scroll);
		}
		inline static void chooseFileButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateSkinChooser::chooseFileButtonCallback))(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s)>(getFuncAddr((int)Func::StateSkinChooser::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s)>(getFuncAddr((int)Func::StateSkinChooser::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateSkinChooser::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s)>(getFuncAddr((int)Func::StateSkinChooser::render))(this, s);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateSkinChooser::windowResize))(this, s, width, height);
		}
		void fileDrop(StateManager& s, int path_count, const char* *paths) override
		{
			return reinterpret_cast<void (__thiscall*)(StateSkinChooser* self, StateManager& s, int path_count, const char* *paths)>(getFuncAddr((int)Func::StateSkinChooser::fileDrop))(this, s, path_count, paths);
		}
		Connection::OutMessage getSkinMessage() 
		{
			Connection::OutMessage result;
			reinterpret_cast<Connection::OutMessage* (__thiscall*)(StateSkinChooser* self, Connection::OutMessage* result)>(getFuncAddr((int)Func::StateSkinChooser::getSkinMessage))(this, &result);
			return result;
		}
		bool loadSkin(const stl::path& p) 
		{
			return reinterpret_cast<bool (__thiscall*)(StateSkinChooser* self, const stl::path& p)>(getFuncAddr((int)Func::StateSkinChooser::loadSkin))(this, p);
		}
	};
}

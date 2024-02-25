#pragma once

#include "4dm.h"

namespace fdm 
{
	class StateMultiplayer : public State 
	{
	public:
		inline static StateMultiplayer* instanceObj = reinterpret_cast<StateMultiplayer*>((base + 0x2BF0D0));
		FontRenderer font; // 0x8
		QuadRenderer qr; // 0xA8
		Shader* qs; // 0xD0
		std::shared_ptr<Connection::Client> client; // 0xD8
		std::unique_ptr<WorldClient> world; // 0xE8
		bool loggedIn; // 0xF0
		PAD(0x3);
		int queuePos; // 0xF4
		gui::Interface ui1; // 0xF8
		gui::Interface* currentUI; // 0x160
		Connection::Client::Status currentStatus; // 0x168
		PAD(0x4);
		gui::Text serverAddressLabel; // 0x170
		gui::TextInput serverAddressInput; // 0x1C8
		gui::Text displayNameLabel; // 0x258
		gui::TextInput displayNameInput; // 0x2B0
		gui::Text uuidLabel; // 0x340
		gui::TextInput uuidInput; // 0x398
		gui::Button uuidCopyButton; // 0x428
		gui::Text uuidDescription; // 0x480
		gui::Button cancelButton; // 0x4D8
		gui::Button joinButton; // 0x530
		gui::Button changeSkinButton; // 0x588
		gui::Interface ui2; // 0x5E0
		gui::Button connectionErrorOkButton; // 0x648
		gui::Text connectionStatusText; // 0x6A0
		bool updateViewFlag; // 0x6F8

		~StateMultiplayer() 
		{
			reinterpret_cast<void(__thiscall*)(StateMultiplayer* self)>(getFuncAddr((int)Func::StateMultiplayer::destr_StateMultiplayer))(this);
		}
		StateMultiplayer() 
		{
			reinterpret_cast<void(__thiscall*)(StateMultiplayer* self)>(getFuncAddr((int)Func::StateMultiplayer::StateMultiplayer))(this);
		}
		void updateProjection(const glm::ivec2& size, const glm::ivec2& translate2D) 
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, const glm::ivec2& size, const glm::ivec2& translate2D)>(getFuncAddr((int)Func::StateMultiplayer::updateProjection))(this, size, translate2D);
		}
		inline static void cancelButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateMultiplayer::cancelButtonCallback))(user);
		}
		inline static void changeSkinButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateMultiplayer::changeSkinButtonCallback))(user);
		}
		inline static void joinButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateMultiplayer::joinButtonCallback))(user);
		}
		inline static void viewportCallback(void* user, const glm::ivec4& pos, const glm::ivec2& scroll) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user, const glm::ivec4& pos, const glm::ivec2& scroll)>(getFuncAddr((int)Func::StateMultiplayer::viewportCallback))(user, pos, scroll);
		}
		inline static void uuidCopyButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateMultiplayer::uuidCopyButtonCallback))(user);
		}
		void init(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s)>(getFuncAddr((int)Func::StateMultiplayer::init))(this, s);
		}
		void close(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s)>(getFuncAddr((int)Func::StateMultiplayer::close))(this, s);
		}
		void update(StateManager& s, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, double dt)>(getFuncAddr((int)Func::StateMultiplayer::update))(this, s, dt);
		}
		void render(StateManager& s) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s)>(getFuncAddr((int)Func::StateMultiplayer::render))(this, s);
		}
		void mouseInput(StateManager& s, double xpos, double ypos) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, double xpos, double ypos)>(getFuncAddr((int)Func::StateMultiplayer::mouseInput))(this, s, xpos, ypos);
		}
		void scrollInput(StateManager& s, double xoffset, double yoffset) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, double xoffset, double yoffset)>(getFuncAddr((int)Func::StateMultiplayer::scrollInput))(this, s, xoffset, yoffset);
		}
		void mouseButtonInput(StateManager& s, int button, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, int button, int action, int mods)>(getFuncAddr((int)Func::StateMultiplayer::mouseButtonInput))(this, s, button, action, mods);
		}
		void keyInput(StateManager& s, int key, int scancode, int action, int mods) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, int key, int scancode, int action, int mods)>(getFuncAddr((int)Func::StateMultiplayer::keyInput))(this, s, key, scancode, action, mods);
		}
		void windowResize(StateManager& s, int width, int height) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, int width, int height)>(getFuncAddr((int)Func::StateMultiplayer::windowResize))(this, s, width, height);
		}
		void charInput(StateManager& s, uint32_t codepoint) override
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, StateManager& s, uint32_t codepoint)>(getFuncAddr((int)Func::StateMultiplayer::charInput))(this, s, codepoint);
		}
		void rejoin(std::shared_ptr<Connection::Client> client, const std::unique_ptr<WorldClient>& world) 
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self, std::shared_ptr<Connection::Client> client, const std::unique_ptr<WorldClient>& world)>(getFuncAddr((int)Func::StateMultiplayer::rejoin))(this, client, world);
		}
		void connect() 
		{
			return reinterpret_cast<void (__thiscall*)(StateMultiplayer* self)>(getFuncAddr((int)Func::StateMultiplayer::connect))(this);
		}
		inline static void connectionErrorOkButtonCallback(void* user) 
		{
			return reinterpret_cast<void (__fastcall*)(void* user)>(getFuncAddr((int)Func::StateMultiplayer::connectionErrorOkButtonCallback))(user);
		}
	};
}

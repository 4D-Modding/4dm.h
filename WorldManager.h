#pragma once

#include "4dm.h"
#include "StateManager.h"

namespace fdm 
{
	class WorldManager : public World 
	{
	public:
		std::atomic<int> numChunksLoaded; // 0x168
		Frustum frustum; // 0x16C
		std::atomic<bool> smoothLighting; // 0x1CC
		std::atomic<bool> shadows; // 0x1CD
		std::atomic<bool> lights; // 0x1CE

		~WorldManager() override
		{
			reinterpret_cast<void(__thiscall*)(WorldManager* self)>(getFuncAddr((int)Func::WorldManager::destr_WorldManager))(this);
		}
		void updateRenderFrustum(const glm::mat4& p) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldManager* self, const glm::mat4& p)>(getFuncAddr((int)Func::WorldManager::updateRenderFrustum))(this, p);
		}
		void setBlockUpdate(const glm::ivec4& block, uint8_t value) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldManager* self, const glm::ivec4& block, uint8_t value)>(getFuncAddr((int)Func::WorldManager::setBlockUpdate))(this, block, value);
		}
		

		virtual void render(const m4::Mat5& MV, bool glasses, glm::vec3 worldColor)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, const m4::Mat5 & MV, bool glasses, glm::vec3 worldColor)>(getFuncAddr((int)Func::WorldManager::render))(this, MV, glasses, worldColor);
		}
		virtual void updateLocal(StateManager& s, Player* player, double dt)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, StateManager&, Player*, double)>(getFuncAddr((int)Func::WorldManager::updateLocal))(this, s, player, dt);
		}
		virtual void cleanupLocal(Player* player)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, Player*)>(getFuncAddr((int)Func::WorldManager::cleanupLocal))(this, player);
		}
		virtual void setRenderDistanceLocal(Player* player, unsigned char distance) {}
		virtual void setDifficultyLocal(Player* player, int difficulty)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, Player*, int)>(getFuncAddr((int)Func::WorldManager::setDifficultyLocal))(this, player, difficulty);
		}
		virtual void setSkinVisibility(bool visible)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, bool)>(getFuncAddr((int)Func::WorldManager::setSkinVisibility))(this, visible);
		}
		virtual void localPlayerInit(Player* player) {}
		virtual void localPlayerRespawn(StateManager&, Player*) {}
		virtual void sendChatMessage(Player* player, const stl::string& message)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, Player*, const stl::string&)>(getFuncAddr((int)Func::WorldManager::sendChatMessage))(this, player, message);
		}
		virtual void handleLightingOptionsUpdate() {}
	};
}

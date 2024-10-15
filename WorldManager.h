#pragma once

#include "4dm.h"
#include "StateManager.h"

namespace fdm 
{
	class WorldManager : public World 
	{
	public:
		std::atomic_int numChunksLoaded; // 0x168
		Frustum frustum; // 0x16C
		std::atomic_bool smoothLighting; // 0x1CC
		std::atomic_bool shadows; // 0x1CD
		std::atomic_bool lights; // 0x1CE

		~WorldManager() override
		{
			reinterpret_cast<void(__thiscall*)(WorldManager* self)>(getFuncAddr((int)Func::WorldManager::destr_WorldManager))(this);
		}
		void updateRenderFrustum(const glm::mat4& p) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldManager* self, const glm::mat4& p)>(getFuncAddr((int)Func::WorldManager::updateRenderFrustum))(this, p);
		}
		bool setBlockUpdate(const glm::ivec4& block, unsigned char value) override
		{
			return reinterpret_cast<bool (__thiscall*)(WorldManager* self, const glm::ivec4& block, unsigned char value)>(getFuncAddr((int)Func::WorldManager::setBlockUpdate))(this, block, value);
		}
		

		virtual void render(const m4::Mat5& MV, bool glasses, glm::vec3 worldColor)
		{
			return reinterpret_cast<void(__thiscall*)(WorldManager * self, const m4::Mat5 & MV, bool glasses, glm::vec3 worldColor)>(getFuncAddr((int)Func::WorldManager::render))(this, MV, glasses, worldColor);
		}
		virtual void updateLocal(StateManager& s, Player* player, double dt) {}
		virtual void cleanupLocal(Player* player) {}
		virtual void setRenderDistanceLocal(Player* player, unsigned char distance) {}
		virtual void setDifficultyLocal(Player* player, int diff) {}
		virtual void setSkinVisibility(bool visible) {}
		virtual void localPlayerInit(Player* player) {}
		virtual void localPlayerRespawn(StateManager&, Player*) {}
		virtual void sendChatMessage(Player* player, const stl::string&) {}
		virtual void handleLightingOptionsUpdate() {}
	};
}

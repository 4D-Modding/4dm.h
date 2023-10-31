#pragma once

#include "4dm.h"

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
			return reinterpret_cast<void(__thiscall*)(WorldManager* self)>(FUNC_WORLDMANAGER_DESTR_WORLDMANAGER)(this);
		}
		void updateRenderFrustum(const glm::mat4& p) 
		{
			return reinterpret_cast<void (__thiscall*)(WorldManager* self, const glm::mat4& p)>(FUNC_WORLDMANAGER_UPDATERENDERFRUSTUM)(this, p);
		}
		void setBlockUpdate(const glm::ivec4& block, unsigned char value) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldManager* self, const glm::ivec4& block, unsigned char value)>(FUNC_WORLDMANAGER_SETBLOCKUPDATE)(this, block, value);
		}
		void render(const m4::Mat5& MV, bool glasses, glm::vec3& worldColor) override
		{
			return reinterpret_cast<void (__thiscall*)(WorldManager* self, const m4::Mat5& MV, bool glasses, glm::vec3& worldColor)>(FUNC_WORLDMANAGER_RENDER)(this, MV, glasses, worldColor);
		}
	};
}
#pragma once

#include "4dm.h"

namespace fdm 
{
	class EntityAlidade : public Entity 
	{
	public:
		struct VertInfo 
		{
			glm::vec4 vert; 
			glm::vec4 normal; // 0x10

		};
		struct SPInfo 
		{
			int edges; 
			PAD(0x4);
			std::vector<float> sinVert; // 0x8
			std::vector<float> cosVert; // 0x20

			SPInfo() 
			{
				reinterpret_cast<void(__thiscall*)(EntityAlidade::SPInfo* self)>(FUNC_ENTITYALIDADE_SPINFO_SPINFO)(this);
			}
			~SPInfo() 
			{
				reinterpret_cast<void(__thiscall*)(EntityAlidade::SPInfo* self)>(FUNC_ENTITYALIDADE_SPINFO_DESTR_SPINFO)(this);
			}
		};
		inline static MeshRenderer *telescopeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278828)); 
		inline static MeshRenderer *baseRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278888)); 
		inline static MeshRenderer *supportRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278868)); 
		inline static MeshRenderer *semicircleRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278848)); 
		inline static MeshRenderer *wireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278808)); 
		Hitbox hitbox; // 0x20
		inline static const float HEALTH_MAX = 10.f; 
		float health; // 0x70
		glm::vec4 pos; // 0x74
		glm::ivec4 currentBlock; // 0x84
		m4::Mat5 orientation; // 0x94

		std::string getName() override
		{
			std::string result;
			return reinterpret_cast<std::string (__thiscall*)(EntityAlidade* self, std::string* result)>(FUNC_ENTITYALIDADE_GETNAME)(this, &result);
			return result;
		}
		void update(World* world, double dt) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityAlidade* self, World* world, double dt)>(FUNC_ENTITYALIDADE_UPDATE)(this, world, dt);
		}
		void render(const World* world, const m4::Mat5& MV, bool glasses) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityAlidade* self, const World* world, const m4::Mat5& MV, bool glasses)>(FUNC_ENTITYALIDADE_RENDER)(this, world, MV, glasses);
		}
		nlohmann::json saveAttributes() override
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(EntityAlidade* self, nlohmann::json* result)>(FUNC_ENTITYALIDADE_SAVEATTRIBUTES)(this, &result);
			return result;
		}
		glm::vec4 getPos() override
		{
			glm::vec4 result;
			return reinterpret_cast<glm::vec4 (__thiscall*)(EntityAlidade* self, glm::vec4* result)>(FUNC_ENTITYALIDADE_GETPOS)(this, &result);
			return result;
		}
		void setPos(const glm::vec4& pos) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityAlidade* self, const glm::vec4& pos)>(FUNC_ENTITYALIDADE_SETPOS)(this, pos);
		}
		void takeDamage(float damage, World* world) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityAlidade* self, float damage, World* world)>(FUNC_ENTITYALIDADE_TAKEDAMAGE)(this, damage, world);
		}
		bool action(World* world, Entity* actor, int action, const nlohmann::json& details) override
		{
			return reinterpret_cast<bool (__thiscall*)(EntityAlidade* self, World* world, Entity* actor, int action, const nlohmann::json & details)>(FUNC_ENTITYALIDADE_ACTION)(this, world, actor, action, details);
		}
		void postAction(World* world, Entity* actor, int action) override
		{
			return reinterpret_cast<void (__thiscall*)(EntityAlidade* self, World* world, Entity* actor, int action)>(FUNC_ENTITYALIDADE_POSTACTION)(this, world, actor, action);
		}
		inline static void generateSpherinder(MeshRenderer* r, int edges, float height, double diameter) 
		{
			return reinterpret_cast<void (__fastcall*)(MeshRenderer* r, int edges, float height, double diameter)>(FUNC_ENTITYALIDADE_GENERATESPHERINDER)(r, edges, height, diameter);
		}
		inline static void generateSpherinderHollow(MeshRenderer* r, int edges, float height, double diameter, float holeDiameter) 
		{
			return reinterpret_cast<void (__fastcall*)(MeshRenderer* r, int edges, float height, double diameter, float holeDiameter)>(FUNC_ENTITYALIDADE_GENERATESPHERINDERHOLLOW)(r, edges, height, diameter, holeDiameter);
		}
		inline static void generateSemicircle(MeshRenderer* r, int edges, float diameter, float innerThickness, float sideThickness) 
		{
			return reinterpret_cast<void (__fastcall*)(MeshRenderer* r, int edges, float diameter, float innerThickness, float sideThickness)>(FUNC_ENTITYALIDADE_GENERATESEMICIRCLE)(r, edges, diameter, innerThickness, sideThickness);
		}
	};
}

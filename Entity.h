#pragma once

#include "4dm.h"
#include "FontRenderer.h"
#include "TexRenderer.h"
#include "World.h"

namespace fdm 
{
	class Entity 
	{
	public:
		struct Ray 
		{
			float length; 
			glm::vec4 start; // 0x4
			glm::vec4 end; // 0x14
			glm::vec4 dir; // 0x24
			glm::vec4 dirInv; // 0x34

		};
		inline static const float MAX_HITBOX_RADIUS = 3.f; 
		PAD(0x1); // --> inline static boost::uuids::string_generator idParser = NULL
		PAD(0x8); // --> inline static boost::uuids::random_generator_pure *uuidGenerator = reinterpret_cast<boost::uuids::random_generator_pure*>((base + 0x2BDFC8))
		PAD(0x1); // --> inline static boost::uuids::string_generator *uuidParser = reinterpret_cast<boost::uuids::string_generator*>((base + 0x29B3E0))
		inline static TexRenderer* ftr = NULL; 
		inline static FontRenderer* fr = NULL; 
		inline static nlohmann::json* blueprints = reinterpret_cast<nlohmann::json*>((base + 0x2BE5A8));
		uuid id; // 0x8
		bool dead; // 0x18

		inline static bool loadEntityInfo() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(FUNC_ENTITY_LOADENTITYINFO)();
		}
		inline static std::unique_ptr<Entity> createFromJson(nlohmann::json& j) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)( nlohmann::json& j)>(FUNC_ENTITY_CREATEFROMJSON)(j);
		}
		inline static std::unique_ptr<Entity> createWithAttributes(std::string& entityName, std::string& pos, nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(std::string& entityName, std::string& pos, nlohmann::json& attributes)>(FUNC_ENTITY_CREATEWITHATTRIBUTES)(entityName, pos, attributes);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json (__thiscall*)(Entity* self, nlohmann::json* result)>(FUNC_ENTITY_SAVE)(this, &result);
			return result;
		}
		inline static std::unique_ptr<Entity,std::default_delete<Entity> > instantiateEntity(const std::string& itemName, const uuid& id, glm::vec4& pos, const std::string& type, nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Entity,std::default_delete<Entity> > (__fastcall*)(const std::string& itemName, const uuid& id, glm::vec4& pos, const std::string& type, nlohmann::json& attributes)>(FUNC_ENTITY_INSTANTIATEENTITY)(itemName, id, pos, type, attributes);
		}
		inline static nlohmann::json combineEntityAttributes(nlohmann::json& baseAttributes, nlohmann::json& additions) 
		{
			return reinterpret_cast<nlohmann::json (__fastcall*)(nlohmann::json& baseAttributes, nlohmann::json& additions)>(FUNC_ENTITY_COMBINEENTITYATTRIBUTES)(baseAttributes, additions);
		}
		~Entity()
		{
			reinterpret_cast<void(__thiscall*)(Entity* self)>(FUNC_ENTITY_DESTR_ENTITY)(this);
		}


		// VIRTUAL FUNCS

		virtual std::string getName() = NULL;
		virtual void update(World* world, double dt) = NULL;
		virtual void render(const World* world, const m4::Mat5& MV, bool glasses) = NULL;
		virtual nlohmann::json saveAttributes() = NULL;
		virtual nlohmann::json getServerUpdateAttributes() = NULL;
		virtual void applyServerUpdate(const nlohmann::json& j, World* world) = NULL;
		virtual glm::vec4 getPos() = NULL;
		virtual void setPos(const glm::vec4 & pos) = NULL;
		virtual bool shouldSave() = NULL;
		virtual bool isClickable() = NULL;
		virtual bool isBlockEntity() = NULL;
		virtual bool isIntersectingRay(const Entity::Ray& ray) = NULL;
		virtual void takeDamage(float damage, World* world) = NULL;
		virtual bool action(World* world, Entity* actor, int action, const nlohmann::json& details) = NULL;
		virtual void postAction(World* world, Entity* actor, int action) = NULL;
		virtual float deathTimer() = NULL;
	};
}

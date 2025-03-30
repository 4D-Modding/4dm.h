#pragma once

#include "4dm.h"
#include "FontRenderer.h"
#include "TexRenderer.h"
#include "World.h"
#include "m4.h"

namespace fdm 
{
	class World;
	class TexRenderer;
	class FontRenderer;
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
		inline static constexpr const float MAX_HITBOX_RADIUS = 3.0f;
		
		//inline static boost::uuids::string_generator& idParser = *reinterpret_cast<boost::uuids::string_generator*>(getDataAddr((int)Data::Entity::idParser));
		//inline static boost::uuids::random_generator_pure& uuidGenerator = *reinterpret_cast<boost::uuids::random_generator_pure*>(getDataAddr((int)Data::Entity::uuidGenerator));
		//inline static boost::uuids::string_generator& uuidParser = *reinterpret_cast<boost::uuids::string_generator*>(getDataAddr((int)Data::Entity::uuidParser));

		inline static nlohmann::json& blueprints = *reinterpret_cast<nlohmann::json*>(getDataAddr((int)Data::Entity::blueprints));
		stl::uuid id; // 0x8
		bool dead; // 0x18

		Entity(){}

		// only available for server
		nlohmann::json getServerUpdate()
		{
			return reinterpret_cast<nlohmann::json(__thiscall*)(Entity * self)>(getFuncAddr((int)Func::Entity::getServerUpdate))(this);
		}

		inline static bool loadEntityInfo() 
		{
			return reinterpret_cast<bool (__fastcall*)()>(getFuncAddr((int)Func::Entity::loadEntityInfo))();
		}
		inline static std::unique_ptr<Entity> createFromJson(const nlohmann::json& j) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(const nlohmann::json& j)>(getFuncAddr((int)Func::Entity::createFromJson))(j);
		}
		inline static std::unique_ptr<Entity> createWithAttributes(const stl::string& entityName, const glm::vec4& pos, const nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(const stl::string&, const glm::vec4&, const nlohmann::json&)>(getFuncAddr((int)Func::Entity::createWithAttributes))(entityName, pos, attributes);
		}
		nlohmann::json save() 
		{
			nlohmann::json result;
			return reinterpret_cast<nlohmann::json& (__thiscall*)(Entity* self, nlohmann::json* result)>(getFuncAddr((int)Func::Entity::save))(this, &result);
			return result;
		}
		inline static std::unique_ptr<Entity> instantiateEntity(const stl::string& entityName, const stl::uuid& id, const glm::vec4& pos, const stl::string& type, const nlohmann::json& attributes) 
		{
			return reinterpret_cast<std::unique_ptr<Entity> (__fastcall*)(const stl::string&, const stl::uuid&, const glm::vec4&, const stl::string&, const nlohmann::json&)>(getFuncAddr((int)Func::Entity::instantiateEntity))(entityName, id, pos, type, attributes);
		}
		inline static nlohmann::json combineEntityAttributes(const nlohmann::json& baseAttributes, const nlohmann::json& additions) 
		{
			return reinterpret_cast<nlohmann::json (__fastcall*)(const nlohmann::json& baseAttributes, const nlohmann::json& additions)>(getFuncAddr((int)Func::Entity::combineEntityAttributes))(baseAttributes, additions);
		}
		virtual ~Entity()
		{
			reinterpret_cast<void(__thiscall*)(Entity* self)>(getFuncAddr((int)Func::Entity::destr_Entity))(this);
		}

		inline static void audioInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::Entity::audioInit))();
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::Entity::renderInit))();
		}

		// VIRTUAL FUNCS

		virtual stl::string getName() { return ""; }
		virtual void update(World* world, double dt) {}
		virtual void render(const World* world, const m4::Mat5& MV, bool glasses) {}
		virtual nlohmann::json saveAttributes() { return NULL; }
		virtual nlohmann::json getServerUpdateAttributes() { return NULL; }
		virtual void applyServerUpdate(const nlohmann::json& j, World* world) {}
		virtual glm::vec4 getPos() { return {}; }
		virtual void setPos(const glm::vec4 & pos) {}
		virtual bool shouldSave() { return false; }
		virtual bool isClickable() { return false; }
		virtual bool isBlockEntity() { return false; }
		virtual bool isIntersectingRay(const Entity::Ray& ray) { return false; }
		virtual void takeDamage(float damage, World* world) {}
		virtual bool action(World* world, Entity* actor, int action, const nlohmann::json& details) { return false; }
		virtual void postAction(World* world, Entity* actor, int action)
		{
			return reinterpret_cast<void(__thiscall*)(Entity * self, World*, Entity*, int)>(getFuncAddr((int)Func::Entity::postAction))(this, world, actor, action);
		}
		virtual float deathTimer() { return NULL; }
	};
}

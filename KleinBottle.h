#pragma once

#include "4dm.h"

namespace fdm 
{
	class KleinBottle : public Mesh 
	{
	public:
		std::vector<glm::vec4,std::allocator<glm::vec4 > > verts; // 0x8
		std::vector<glm::vec3,std::allocator<glm::vec3 > > colors; // 0x20

		void buffData(int buffIndex) override
		{
			return reinterpret_cast<void (__thiscall*)(KleinBottle* self, int buffIndex)>(FUNC_KLEINBOTTLE_BUFFDATA)(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) override
		{
			return reinterpret_cast<int (__thiscall*)(KleinBottle* self, int buffIndex, int attrIndex)>(FUNC_KLEINBOTTLE_ATTRSIZE)(this, buffIndex, attrIndex);
		}
		KleinBottle(int edges, float tubeRaduis, float tubeCenterRadius, const glm::vec3& colorA, const glm::vec3& colorB) 
		{
			return reinterpret_cast<void(__thiscall*)(KleinBottle* self, int edges, float tubeRaduis, float tubeCenterRadius, const glm::vec3& colorA, const glm::vec3& colorB)>(FUNC_KLEINBOTTLE_KLEINBOTTLE)(this, edges, tubeRaduis, tubeCenterRadius, colorA, colorB);
		}
		int buffSize(int buffIndex) override
		{
			return reinterpret_cast<int (__thiscall*)(KleinBottle* self, int buffIndex)>(FUNC_KLEINBOTTLE_BUFFSIZE)(this, buffIndex);
		}
		~KleinBottle() 
		{
			return reinterpret_cast<void(__thiscall*)(KleinBottle* self)>(FUNC_KLEINBOTTLE_DESTR_KLEINBOTTLE)(this);
		}
	};
}

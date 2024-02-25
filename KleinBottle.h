#pragma once

#include "4dm.h"

namespace fdm 
{
	class KleinBottle : public Mesh 
	{
	public:
		std::vector<glm::vec4> verts; // 0x8
		std::vector<glm::vec3> colors; // 0x20

		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const KleinBottle* self, int buffIndex)>(getFuncAddr((int)Func::KleinBottle::buffData))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const KleinBottle* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::KleinBottle::attrSize))(this, buffIndex, attrIndex);
		}
		KleinBottle(int edges, float tubeRaduis, float tubeCenterRadius, const glm::vec3& colorA, const glm::vec3& colorB) 
		{
			reinterpret_cast<void(__thiscall*)(KleinBottle* self, int edges, float tubeRaduis, float tubeCenterRadius, const glm::vec3& colorA, const glm::vec3& colorB)>(getFuncAddr((int)Func::KleinBottle::KleinBottle))(this, edges, tubeRaduis, tubeCenterRadius, colorA, colorB);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const KleinBottle* self, int buffIndex)>(getFuncAddr((int)Func::KleinBottle::buffSize))(this, buffIndex);
		}
		~KleinBottle() 
		{
			reinterpret_cast<void(__thiscall*)(KleinBottle* self)>(getFuncAddr((int)Func::KleinBottle::destr_KleinBottle))(this);
		}
	};
}

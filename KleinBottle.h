#pragma once

#include "4dm.h"

namespace fdm 
{
	class KleinBottle : public Mesh 
	{
	public:
		std::vector<glm::vec4> verts; // 0x8
		std::vector<glm::vec3> colors; // 0x20

		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const KleinBottle * self, int)>(getFuncAddr((int)Func::KleinBottle::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const KleinBottle * self, int, int)>(getFuncAddr((int)Func::KleinBottle::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const KleinBottle * self, int, int)>(getFuncAddr((int)Func::KleinBottle::attrStride))(this, buffIndex, attrIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const KleinBottle * self, int, int)>(getFuncAddr((int)Func::KleinBottle::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const KleinBottle * self)>(getFuncAddr((int)Func::KleinBottle::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const KleinBottle * self, int)>(getFuncAddr((int)Func::KleinBottle::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const KleinBottle * self, int)>(getFuncAddr((int)Func::KleinBottle::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const KleinBottle * self)>(getFuncAddr((int)Func::KleinBottle::vertCount))(this);
		}
		KleinBottle(int edges, float tubeRaduis, float tubeCenterRadius, const glm::vec3& colorA, const glm::vec3& colorB) 
		{
			reinterpret_cast<void(__thiscall*)(KleinBottle* self, int edges, float tubeRaduis, float tubeCenterRadius, const glm::vec3& colorA, const glm::vec3& colorB)>(getFuncAddr((int)Func::KleinBottle::KleinBottle))(this, edges, tubeRaduis, tubeCenterRadius, colorA, colorB);
		}
		~KleinBottle() 
		{
			reinterpret_cast<void(__thiscall*)(KleinBottle* self)>(getFuncAddr((int)Func::KleinBottle::destr_KleinBottle))(this);
		}
	};
}

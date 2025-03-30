#pragma once

#include "4dm.h"

namespace fdm 
{
	class PentachoronHollow : public Mesh 
	{
	public:
		struct VertData 
		{
			glm::vec4 s; 
			glm::vec3 t; // 0x10
		};
		std::vector<PentachoronHollow::VertData> vertices; // 0x8

		PentachoronHollow(float distance) 
		{
			reinterpret_cast<void(__thiscall*)(PentachoronHollow* self, float distance)>(getFuncAddr((int)Func::PentachoronHollow::PentachoronHollow))(this, distance);
		}
		void addTetSide(const glm::vec4* simp_ptr, const glm::vec4* inner, int i0, int i1, int i2)
		{
			return reinterpret_cast<void (__thiscall*)(PentachoronHollow* self, const glm::vec4 * simp_ptr, const glm::vec4 * inner, int i0, int i1, int i2)>(getFuncAddr((int)Func::PentachoronHollow::addTetSide))(this, simp_ptr, inner, i0, i1, i2);
		}
		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const PentachoronHollow * self, int)>(getFuncAddr((int)Func::PentachoronHollow::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const PentachoronHollow * self, int, int)>(getFuncAddr((int)Func::PentachoronHollow::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attriIdex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const PentachoronHollow * self, int, int)>(getFuncAddr((int)Func::PentachoronHollow::attrStride))(this, buffIndex, attriIdex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const PentachoronHollow * self, int, int)>(getFuncAddr((int)Func::PentachoronHollow::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const PentachoronHollow * self)>(getFuncAddr((int)Func::PentachoronHollow::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const PentachoronHollow * self, int)>(getFuncAddr((int)Func::PentachoronHollow::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const PentachoronHollow * self, int)>(getFuncAddr((int)Func::PentachoronHollow::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const PentachoronHollow * self)>(getFuncAddr((int)Func::PentachoronHollow::vertCount))(this);
		}
	};
}

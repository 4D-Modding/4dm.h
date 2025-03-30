#pragma once

#include "4dm.h"

namespace fdm 
{
	class Coil : public Mesh 
	{
	public:
		std::vector<glm::vec4> verts; // 0x8
		std::vector<float> normals; // 0x20

		Coil(int n, int s, float r, float w, float h) 
		{
			reinterpret_cast<void(__thiscall*)(Coil* self, int n, int s, float r, float w, float h)>(getFuncAddr((int)Func::Coil::Coil))(this, n, s, r, w, h);
		}
		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Coil * self, int)>(getFuncAddr((int)Func::Coil::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Coil * self, int, int)>(getFuncAddr((int)Func::Coil::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Coil * self, int, int)>(getFuncAddr((int)Func::Coil::attrStride))(this, buffIndex, attrIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const Coil * self, int, int)>(getFuncAddr((int)Func::Coil::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const Coil * self)>(getFuncAddr((int)Func::Coil::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const Coil * self, int)>(getFuncAddr((int)Func::Coil::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Coil * self, int)>(getFuncAddr((int)Func::Coil::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const Coil * self)>(getFuncAddr((int)Func::Coil::vertCount))(this);
		}
	};
}

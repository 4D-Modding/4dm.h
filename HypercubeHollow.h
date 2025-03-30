#pragma once

#include "4dm.h"

namespace fdm 
{
	class HypercubeHollow : public Mesh 
	{
	public:
		struct VertData 
		{
			glm::vec4 s; 
			glm::vec3 t; // 0x10

		};
		std::vector<HypercubeHollow::VertData> vertices; // 0x8

		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const HypercubeHollow * self, int)>(getFuncAddr((int)Func::HypercubeHollow::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const HypercubeHollow * self, int, int)>(getFuncAddr((int)Func::HypercubeHollow::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const HypercubeHollow * self, int, int)>(getFuncAddr((int)Func::HypercubeHollow::attrStride))(this, buffIndex, attrIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const HypercubeHollow * self, int, int)>(getFuncAddr((int)Func::HypercubeHollow::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const HypercubeHollow * self)>(getFuncAddr((int)Func::HypercubeHollow::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const HypercubeHollow * self, int)>(getFuncAddr((int)Func::HypercubeHollow::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const HypercubeHollow * self, int)>(getFuncAddr((int)Func::HypercubeHollow::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const HypercubeHollow * self)>(getFuncAddr((int)Func::HypercubeHollow::vertCount))(this);
		}
		HypercubeHollow(float distance) 
		{
			reinterpret_cast<void(__thiscall*)(HypercubeHollow* self, float distance)>(getFuncAddr((int)Func::HypercubeHollow::HypercubeHollow))(this, distance);
		}
		void addCubeSide(const glm::vec4* cube_ptr, const glm::vec4* inner, int i0, int i1, int i2, int i3) 
		{
			return reinterpret_cast<void (__thiscall*)(HypercubeHollow* self, const glm::vec4* cube_ptr, const glm::vec4* inner, int i0, int i1, int i2, int i3)>(getFuncAddr((int)Func::HypercubeHollow::addCubeSide))(this, cube_ptr, inner, i0, i1, i2, i3);
		}
	};
}

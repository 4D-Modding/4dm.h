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

		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const HypercubeHollow* self, int buffIndex, int attrIndex)>(FUNC_HYPERCUBEHOLLOW_ATTRSIZE)(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attriIdex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const HypercubeHollow* self, int buffIndex, int attriIdex)>(FUNC_HYPERCUBEHOLLOW_ATTRSTRIDE)(this, buffIndex, attriIdex);
		}
		HypercubeHollow(float distance) 
		{
			reinterpret_cast<void(__thiscall*)(HypercubeHollow* self, float distance)>(FUNC_HYPERCUBEHOLLOW_HYPERCUBEHOLLOW)(this, distance);
		}
		void addCubeSide(const glm::vec4* cube_ptr, const glm::vec4* inner, int i0, int i1, int i2, int i3) 
		{
			return reinterpret_cast<void (__thiscall*)(HypercubeHollow* self, const glm::vec4* cube_ptr, const glm::vec4* inner, int i0, int i1, int i2, int i3)>(FUNC_HYPERCUBEHOLLOW_ADDCUBESIDE)(this, cube_ptr, inner, i0, i1, i2, i3);
		}
	};
}

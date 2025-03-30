#pragma once

#include "4dm.h"

namespace fdm 
{
	class Sphere : public Mesh 
	{
	public:
		std::vector<glm::vec4> s; // 0x8
		std::vector<glm::vec3> t; // 0x20
		Sphere(int edges)
		{
			reinterpret_cast<void(__thiscall*)(Sphere * self, int)>(getFuncAddr((int)Func::Sphere::Sphere))(this, edges);
		}
		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Sphere * self, int)>(getFuncAddr((int)Func::Sphere::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Sphere * self, int, int)>(getFuncAddr((int)Func::Sphere::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Sphere * self, int, int)>(getFuncAddr((int)Func::Sphere::attrStride))(this, buffIndex, attrIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const Sphere * self, int, int)>(getFuncAddr((int)Func::Sphere::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const Sphere * self)>(getFuncAddr((int)Func::Sphere::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const Sphere * self, int)>(getFuncAddr((int)Func::Sphere::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Sphere * self, int)>(getFuncAddr((int)Func::Sphere::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const Sphere * self)>(getFuncAddr((int)Func::Sphere::vertCount))(this);
		}
		inline static void generateCirclePolygons(int wi, std::vector<glm::vec4>& verts, std::vector<glm::vec3>& tuvs, const std::vector<float>& sinVert, const std::vector<float>& cosVert)
		{
			return reinterpret_cast<void(__fastcall*)(int, std::vector<glm::vec4>&, std::vector<glm::vec3>&, const std::vector<float>&, const std::vector<float>&)>(getFuncAddr((int)Func::Sphere::generateCirclePolygons))(wi, verts, tuvs, sinVert, cosVert);
		}
	};
}

#pragma once

#include "4dm.h"

namespace fdm 
{
	class Sphere : public Mesh 
	{
	public:
		std::vector<glm::vec4> s; // 0x8
		std::vector<glm::vec3> t; // 0x20

		int vertCount() const override
		{
			return reinterpret_cast<int (__thiscall*)(const Sphere* self)>(getFuncAddr((int)Func::Sphere::vertCount))(this);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const Sphere* self, int buffIndex)>(getFuncAddr((int)Func::Sphere::buffSize))(this, buffIndex);
		}
		Sphere(int edges) 
		{
			reinterpret_cast<void(__thiscall*)(Sphere* self, int edges)>(getFuncAddr((int)Func::Sphere::Sphere))(this, edges);
		}
		inline static void generateCirclePolygons(int wi, std::vector<glm::vec4>* verts, std::vector<glm::vec3>* tuvs, const std::vector<float>* sinVert, const std::vector<float>* cosVert) 
		{
			return reinterpret_cast<void (__fastcall*)(int wi, std::vector<glm::vec4>* verts, std::vector<glm::vec3>* tuvs, const std::vector<float>* sinVert, const std::vector<float>* cosVert)>(getFuncAddr((int)Func::Sphere::generateCirclePolygons))(wi, verts, tuvs, sinVert, cosVert);
		}
	};
}

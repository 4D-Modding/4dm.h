#pragma once

#include "4dm.h"

namespace fdm 
{
	class Sphere : public Mesh 
	{
	public:
		std::vector<glm::vec4,std::allocator<glm::vec4 > > s; // 0x8
		std::vector<glm::vec3,std::allocator<glm::vec3 > > t; // 0x20

		int vertCount() override
		{
			return reinterpret_cast<int (__thiscall*)(Sphere* self)>(FUNC_SPHERE_VERTCOUNT)(this);
		}
		int buffSize(int buffIndex) override
		{
			return reinterpret_cast<int (__thiscall*)(Sphere* self, int buffIndex)>(FUNC_SPHERE_BUFFSIZE)(this, buffIndex);
		}
		Sphere(int edges) 
		{
			return reinterpret_cast<void(__thiscall*)(Sphere* self, int edges)>(FUNC_SPHERE_SPHERE)(this, edges);
		}
		inline static void generateCirclePolygons(int wi, std::vector<glm::vec4>* verts, std::vector<glm::vec3>* tuvs, const std::vector<float>* sinVert, const std::vector<float>* cosVert) 
		{
			return reinterpret_cast<void (__fastcall*)(int wi, std::vector<glm::vec4>* verts, std::vector<glm::vec3>* tuvs, const std::vector<float>* sinVert, const std::vector<float>* cosVert)>(FUNC_SPHERE_GENERATECIRCLEPOLYGONS)(wi, verts, tuvs, sinVert, cosVert);
		}
	};
}
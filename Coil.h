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
			reinterpret_cast<void(__thiscall*)(Coil* self, int n, int s, float r, float w, float h)>(FUNC_COIL_COIL)(this, n, s, r, w, h);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const Coil* self, int buffIndex)>(FUNC_COIL_BUFFSIZE)(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const Coil* self, int buffIndex, int attrIndex)>(FUNC_COIL_ATTRSIZE)(this, buffIndex, attrIndex);
		}
	};
}

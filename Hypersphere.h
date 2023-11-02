#pragma once

#include "4dm.h"

namespace fdm 
{
	class Hypersphere : public Mesh 
	{
	public:
		struct VertInfo 
		{
			std::vector<glm::vec4> s; 
			std::vector<glm::vec3> t; // 0x18

			VertInfo() 
			{
				reinterpret_cast<void(__thiscall*)(Hypersphere::VertInfo* self)>(FUNC_HYPERSPHERE_VERTINFO_VERTINFO)(this);
			}
			~VertInfo() 
			{
				reinterpret_cast<void(__thiscall*)(Hypersphere::VertInfo* self)>(FUNC_HYPERSPHERE_VERTINFO_DESTR_VERTINFO)(this);
			}
			void add(const glm::vec4& vert, MeshBuilder::AttrInfo* tuv) 
			{
				return reinterpret_cast<void (__thiscall*)(Hypersphere::VertInfo* self, const glm::vec4& vert, MeshBuilder::AttrInfo* tuv)>(FUNC_HYPERSPHERE_VERTINFO_ADD)(this, vert, tuv);
			}
			void add(const Hypersphere::VertInfo* v, int index) 
			{
				return reinterpret_cast<void (__thiscall*)(Hypersphere::VertInfo* self, const Hypersphere::VertInfo* v, int index)>(FUNC_HYPERSPHERE_VERTINFO_ADD_A)(this, v, index);
			}
		};
		struct HSInfo 
		{
			int edges; 
			PAD(0x4);
			std::vector<float> sinVert; // 0x8
			std::vector<float> cosVert; // 0x20

		};
		Hypersphere::VertInfo v; // 0x8

		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const Hypersphere* self, int buffIndex)>(FUNC_HYPERSPHERE_ATTRCOUNT)(this, buffIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(const Hypersphere* self, int buffIndex, int attrIndex)>(FUNC_HYPERSPHERE_ATTRTYPE)(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int (__thiscall*)(const Hypersphere* self)>(FUNC_HYPERSPHERE_BUFFCOUNT)(this);
		}
		Hypersphere(int edges) 
		{
			reinterpret_cast<void(__thiscall*)(Hypersphere* self, int edges)>(FUNC_HYPERSPHERE_HYPERSPHERE)(this, edges);
		}
		Hypersphere(int edges, float distance) 
		{
			reinterpret_cast<void(__thiscall*)(Hypersphere* self, int edges, float distance)>(FUNC_HYPERSPHERE_HYPERSPHERE_A)(this, edges, distance);
		}
		inline static void generateSpherePolygons(Hypersphere::VertInfo* triangles, Hypersphere::VertInfo* trapezoids, const Hypersphere::HSInfo* hsi, int wi) 
		{
			return reinterpret_cast<void (__fastcall*)(Hypersphere::VertInfo* triangles, Hypersphere::VertInfo* trapezoids, const Hypersphere::HSInfo* hsi, int wi)>(FUNC_HYPERSPHERE_GENERATESPHEREPOLYGONS)(triangles, trapezoids, hsi, wi);
		}
		void addWedgeSide(const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2) 
		{
			return reinterpret_cast<void (__thiscall*)(Hypersphere* self, const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2)>(FUNC_HYPERSPHERE_ADDWEDGESIDE)(this, outer, inner, i0, i1, i2);
		}
		void addCubeSide(const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2, int i3) 
		{
			return reinterpret_cast<void (__thiscall*)(Hypersphere* self, const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2, int i3)>(FUNC_HYPERSPHERE_ADDCUBESIDE)(this, outer, inner, i0, i1, i2, i3);
		}
	};
}

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
				reinterpret_cast<void(__thiscall*)(Hypersphere::VertInfo* self)>(getFuncAddr((int)Func::Hypersphere_Nested::VertInfo::VertInfo))(this);
			}
			~VertInfo() 
			{
				reinterpret_cast<void(__thiscall*)(Hypersphere::VertInfo* self)>(getFuncAddr((int)Func::Hypersphere_Nested::VertInfo::destr_VertInfo))(this);
			}
			void add(const glm::vec4& vert, MeshBuilder::AttrInfo* tuv) 
			{
				return reinterpret_cast<void (__thiscall*)(Hypersphere::VertInfo* self, const glm::vec4& vert, MeshBuilder::AttrInfo* tuv)>(getFuncAddr((int)Func::Hypersphere_Nested::VertInfo::add))(this, vert, tuv);
			}
			void add(const Hypersphere::VertInfo* v, int index) 
			{
				return reinterpret_cast<void (__thiscall*)(Hypersphere::VertInfo* self, const Hypersphere::VertInfo* v, int index)>(getFuncAddr((int)Func::Hypersphere_Nested::VertInfo::addA))(this, v, index);
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
			return reinterpret_cast<int (__thiscall*)(const Hypersphere* self, int buffIndex)>(getFuncAddr((int)Func::Hypersphere::attrCount))(this, buffIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t (__thiscall*)(const Hypersphere* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::Hypersphere::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int (__thiscall*)(const Hypersphere* self)>(getFuncAddr((int)Func::Hypersphere::buffCount))(this);
		}
		Hypersphere(int edges) 
		{
			reinterpret_cast<void(__thiscall*)(Hypersphere* self, int edges)>(getFuncAddr((int)Func::Hypersphere::Hypersphere))(this, edges);
		}
		Hypersphere(int edges, float distance) 
		{
			reinterpret_cast<void(__thiscall*)(Hypersphere* self, int edges, float distance)>(getFuncAddr((int)Func::Hypersphere::HypersphereA))(this, edges, distance);
		}
		inline static void generateSpherePolygons(Hypersphere::VertInfo* triangles, Hypersphere::VertInfo* trapezoids, const Hypersphere::HSInfo* hsi, int wi) 
		{
			return reinterpret_cast<void (__fastcall*)(Hypersphere::VertInfo* triangles, Hypersphere::VertInfo* trapezoids, const Hypersphere::HSInfo* hsi, int wi)>(getFuncAddr((int)Func::Hypersphere::generateSpherePolygons))(triangles, trapezoids, hsi, wi);
		}
		void addWedgeSide(const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2) 
		{
			return reinterpret_cast<void (__thiscall*)(Hypersphere* self, const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2)>(getFuncAddr((int)Func::Hypersphere::addWedgeSide))(this, outer, inner, i0, i1, i2);
		}
		void addCubeSide(const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2, int i3) 
		{
			return reinterpret_cast<void (__thiscall*)(Hypersphere* self, const Hypersphere::VertInfo* outer, const Hypersphere::VertInfo* inner, int i0, int i1, int i2, int i3)>(getFuncAddr((int)Func::Hypersphere::addCubeSide))(this, outer, inner, i0, i1, i2, i3);
		}
	};
}

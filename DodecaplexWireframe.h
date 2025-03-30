#pragma once

#include "4dm.h"

namespace fdm 
{
	class DodecaplexWireframe : public Mesh 
	{
	public:
		struct Face 
		{
			glm::vec3 center; 
			glm::vec3 edges[5]; // 0xC
			glm::vec3 verts[5]; // 0x48
			glm::vec3 normal; // 0x84

		};
		struct Face4D 
		{
			glm::vec4 center; 
			glm::vec4 edges[5]; // 0x10
			glm::vec4 verts[5]; // 0x60

		};
		struct Cell 
		{
			glm::vec4 center; 
			DodecaplexWireframe::Face4D faces[12]; // 0x10
			glm::vec4 normal; // 0x850

		};
		inline static constexpr const float radius = 3.702459f; 
		std::vector<glm::vec4> v; // 0x8

		void generateMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(DodecaplexWireframe* self)>(getFuncAddr((int)Func::DodecaplexWireframe::generateMesh))(this);
		}
		void addFaces(DodecaplexWireframe::Face* face, std::vector<DodecaplexWireframe::Face>& list, int recurse_limit) 
		{
			return reinterpret_cast<void (__thiscall*)(DodecaplexWireframe* self, DodecaplexWireframe::Face* face, std::vector<DodecaplexWireframe::Face>& list, int recurse_limit)>(getFuncAddr((int)Func::DodecaplexWireframe::addFaces))(this, face, list, recurse_limit);
		}
		void addCells(DodecaplexWireframe::Cell* cell, std::vector<DodecaplexWireframe::Cell>& list, int recurse_limit) 
		{
			return reinterpret_cast<void (__thiscall*)(DodecaplexWireframe* self, DodecaplexWireframe::Cell* cell, std::vector<DodecaplexWireframe::Cell>& list, int recurse_limit)>(getFuncAddr((int)Func::DodecaplexWireframe::addCells))(this, cell, list, recurse_limit);
		}
		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const DodecaplexWireframe * self, int)>(getFuncAddr((int)Func::DodecaplexWireframe::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const DodecaplexWireframe * self, int, int)>(getFuncAddr((int)Func::DodecaplexWireframe::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const DodecaplexWireframe * self, int, int)>(getFuncAddr((int)Func::DodecaplexWireframe::attrStride))(this, buffIndex, attrIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const DodecaplexWireframe * self, int, int)>(getFuncAddr((int)Func::DodecaplexWireframe::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const DodecaplexWireframe * self)>(getFuncAddr((int)Func::DodecaplexWireframe::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const DodecaplexWireframe * self, int)>(getFuncAddr((int)Func::DodecaplexWireframe::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const DodecaplexWireframe * self, int)>(getFuncAddr((int)Func::DodecaplexWireframe::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const DodecaplexWireframe * self)>(getFuncAddr((int)Func::DodecaplexWireframe::vertCount))(this);
		}
		const void* indexBuffData() const { return nullptr; }
		int indexBuffSize() const { return 0; }
	};
}

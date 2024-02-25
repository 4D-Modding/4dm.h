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
			glm::vec3* edges; // 0xC
			glm::vec3* verts; // 0x48
			glm::vec3 normal; // 0x84

		};
		struct Face4D 
		{
			glm::vec4 center; 
			glm::vec4* edges; // 0x10
			glm::vec4* verts; // 0x60

		};
		struct Cell 
		{
			glm::vec4 center; 
			DodecaplexWireframe::Face4D* faces; // 0x10
			glm::vec4 normal; // 0x850

		};
		inline static const float radius = 3.702459f; 
		std::vector<glm::vec4> v; // 0x8

		void generateMesh() 
		{
			return reinterpret_cast<void (__thiscall*)(DodecaplexWireframe* self)>(getFuncAddr((int)Func::DodecaplexWireframe::generateMesh))(this);
		}
		void addFaces(DodecaplexWireframe::Face* face, std::vector<DodecaplexWireframe::Face>* list, int recurse_limit) 
		{
			return reinterpret_cast<void (__thiscall*)(DodecaplexWireframe* self, DodecaplexWireframe::Face* face, std::vector<DodecaplexWireframe::Face>* list, int recurse_limit)>(getFuncAddr((int)Func::DodecaplexWireframe::addFaces))(this, face, list, recurse_limit);
		}
		void addCells(DodecaplexWireframe::Cell* cell, std::vector<DodecaplexWireframe::Cell>* list, int recurse_limit) 
		{
			return reinterpret_cast<void (__thiscall*)(DodecaplexWireframe* self, DodecaplexWireframe::Cell* cell, std::vector<DodecaplexWireframe::Cell>* list, int recurse_limit)>(getFuncAddr((int)Func::DodecaplexWireframe::addCells))(this, cell, list, recurse_limit);
		}
	};
}

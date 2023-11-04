#pragma once

#include "4dm.h"
#include "DodecaplexWireframe.h"

namespace fdm 
{
	class Dodecaplex : public Mesh 
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
			Dodecaplex::Face4D* faces; // 0x10
			glm::vec4 normal; // 0x850

		};
		inline static const float radius = 3.702459f; 
		std::vector<glm::vec4> v; // 0x8
		std::vector<glm::vec3> t; // 0x20
		bool usingNormals; // 0x38
		PAD(0x7);
		std::vector<glm::vec4> n; // 0x40

		int buffCount() const override
		{
			return reinterpret_cast<int (__thiscall*)(const Dodecaplex* self)>(FUNC_DODECAPLEX_BUFFCOUNT)(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const Dodecaplex* self, int buffIndex)>(FUNC_DODECAPLEX_BUFFDATA)(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const Dodecaplex* self, int buffIndex)>(FUNC_DODECAPLEX_BUFFSIZE)(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const Dodecaplex* self, int buffIndex, int attrIndex)>(FUNC_DODECAPLEX_ATTRSIZE)(this, buffIndex, attrIndex);
		}
		void generateMesh(bool hollow, float distance, bool generateInner, const glm::vec3& colors, bool spider) 
		{
			return reinterpret_cast<void (__thiscall*)(Dodecaplex* self, bool hollow, float distance, bool generateInner, const glm::vec3& colors, bool spider)>(FUNC_DODECAPLEX_GENERATEMESH)(this, hollow, distance, generateInner, colors, spider);
		}
		void generateCellColors(std::vector<glm::vec3>& colors) 
		{
			return reinterpret_cast<void (__thiscall*)(Dodecaplex* self, std::vector<glm::vec3>& colors)>(FUNC_DODECAPLEX_GENERATECELLCOLORS)(this, colors);
		}
		void addFaces(Dodecaplex::Face* face, std::vector<DodecaplexWireframe::Face>* list, int recurse_limit) 
		{
			return reinterpret_cast<void (__thiscall*)(Dodecaplex* self, Dodecaplex::Face* face, std::vector<DodecaplexWireframe::Face>* list, int recurse_limit)>(FUNC_DODECAPLEX_ADDFACES)(this, face, list, recurse_limit);
		}
		void addCells(Dodecaplex::Cell* cell, std::vector<DodecaplexWireframe::Cell>* list, int recurse_limit) 
		{
			return reinterpret_cast<void (__thiscall*)(Dodecaplex* self, Dodecaplex::Cell* cell, std::vector<DodecaplexWireframe::Cell>* list, int recurse_limit)>(FUNC_DODECAPLEX_ADDCELLS)(this, cell, list, recurse_limit);
		}
		~Dodecaplex() 
		{
			reinterpret_cast<void(__thiscall*)(Dodecaplex* self)>(FUNC_DODECAPLEX_DESTR_DODECAPLEX)(this);
		}

		int attrCount(int buffIndex) const { return 0; }
		unsigned int attrType(int buffIndex, int attrIndex) const { return 0; }
		int attrStride(int buffIndex, int attrIndex) const { return 0; }
		int vertCount() const { return 0; }
		const void* indexBuffData() const { return nullptr; }
		int indexBuffSize() const { return 0; }
	};
}

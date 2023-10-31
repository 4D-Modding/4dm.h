#pragma once

#include "4dm.h"

namespace fdm 
{
	class MeshRenderer 
	{
	public:
		uint32_t VAO; 
		PAD(0x4);
		uint32_t* VBOs; // 0x8
		uint32_t indexVBO; // 0x10
		int vertexCount; // 0x14
		int bufferCount; // 0x18
		uint32_t mode; // 0x1C

		MeshRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(MeshRenderer* self)>(FUNC_MESHRENDERER_MESHRENDERER)(this);
		}
		void setMesh(Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, Mesh* mesh)>(FUNC_MESHRENDERER_SETMESH)(this, mesh);
		}
		void updateMesh(Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, Mesh* mesh)>(FUNC_MESHRENDERER_UPDATEMESH)(this, mesh);
		}
		~MeshRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(MeshRenderer* self)>(FUNC_MESHRENDERER_DESTR_MESHRENDERER)(this);
		}
		void render() 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self)>(FUNC_MESHRENDERER_RENDER)(this);
		}
		void init(Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, Mesh* mesh)>(FUNC_MESHRENDERER_INIT)(this, mesh);
		}
		void cleanup() 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self)>(FUNC_MESHRENDERER_CLEANUP)(this);
		}
		void initAttrs(Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, Mesh* mesh)>(FUNC_MESHRENDERER_INITATTRS)(this, mesh);
		}
	};
}

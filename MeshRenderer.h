#pragma once

#include "4dm.h"

namespace fdm 
{
	class MeshRenderer 
	{
	public:
		uint32_t VAO = 0; 
		PAD(0x4);
		uint32_t* VBOs = nullptr; // 0x8
		uint32_t indexVBO = 0; // 0x10
		int vertexCount = 0; // 0x14
		int bufferCount = 0; // 0x18
		uint32_t mode = GL_LINES_ADJACENCY; // 0x1C

		MeshRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(MeshRenderer* self)>(getFuncAddr((int)Func::MeshRenderer::MeshRenderer))(this);
		}
		MeshRenderer(const MeshRenderer& other) = delete;
		MeshRenderer& operator=(const MeshRenderer& other) = delete;
		MeshRenderer(MeshRenderer&& other) noexcept
		{
			VAO = other.VAO;
			VBOs = other.VBOs;
			indexVBO = other.indexVBO;
			vertexCount = other.vertexCount;
			bufferCount = other.bufferCount;
			mode = other.mode;

			other.VAO = 0;
			other.VBOs = nullptr;
			other.indexVBO = 0;
			other.vertexCount = 0;
			other.bufferCount = 0;
			other.mode = GL_LINES_ADJACENCY;
		}
		MeshRenderer& operator=(MeshRenderer&& other) noexcept
		{
			VAO = other.VAO;
			VBOs = other.VBOs;
			indexVBO = other.indexVBO;
			vertexCount = other.vertexCount;
			bufferCount = other.bufferCount;
			mode = other.mode;

			other.VAO = 0;
			other.VBOs = nullptr;
			other.indexVBO = 0;
			other.vertexCount = 0;
			other.bufferCount = 0;
			other.mode = GL_LINES_ADJACENCY;

			return *this;
		}
		void setMesh(const Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, const Mesh* mesh)>(getFuncAddr((int)Func::MeshRenderer::setMesh))(this, mesh);
		}
		void updateMesh(const Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, const Mesh* mesh)>(getFuncAddr((int)Func::MeshRenderer::updateMesh))(this, mesh);
		}
		~MeshRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(MeshRenderer* self)>(getFuncAddr((int)Func::MeshRenderer::destr_MeshRenderer))(this);
		}
		void render() const
		{
			return reinterpret_cast<void (__thiscall*)(const MeshRenderer* self)>(getFuncAddr((int)Func::MeshRenderer::render))(this);
		}
		void init(const Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, const Mesh* mesh)>(getFuncAddr((int)Func::MeshRenderer::init))(this, mesh);
		}
		void cleanup() 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self)>(getFuncAddr((int)Func::MeshRenderer::cleanup))(this);
		}
		void initAttrs(const Mesh* mesh) 
		{
			return reinterpret_cast<void (__thiscall*)(MeshRenderer* self, const Mesh* mesh)>(getFuncAddr((int)Func::MeshRenderer::initAttrs))(this, mesh);
		}
		MeshRenderer(const Mesh* mesh)
		{
			init(mesh);
		}
	};
}

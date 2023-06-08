#pragma once
#ifndef MESHRENDERER_H
#define MESHRENDERER_H
#include "4dm.h"
namespace fdm
{
	class MeshRenderer
	{
	public:
		unsigned int VAO;
		PAD(1 * sizeof(long));
		unsigned int* VBOs;
		unsigned int indexVBO;
		int vertexCount;
		int bufferCount;
		unsigned int mode;

		MeshRenderer()
		{
			reinterpret_cast<void(__thiscall*)(MeshRenderer * self)>(FUNC_MESHRENDERER_MESHRENDERER)(this);
		}
		void setMesh(Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, Mesh * mesh)>(FUNC_MESHRENDERER_SETMESH)(this, mesh);
		}
		void updateMesh(Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, Mesh * mesh)>(FUNC_MESHRENDERER_UPDATEMESH)(this, mesh);
		}
		~MeshRenderer()
		{
			reinterpret_cast<void(__thiscall*)(MeshRenderer * self)>(FUNC_MESHRENDERER_DMESHRENDERER)(this);
		}
		MeshRenderer* operator=(MeshRenderer* other)
		{
			return reinterpret_cast<MeshRenderer * (__thiscall*)(MeshRenderer * self, MeshRenderer * other)>(FUNC_MESHRENDERER_OPERATOR_EQ)(this, other);
		}
		void render()
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self)>(FUNC_MESHRENDERER_RENDER)(this);
		}
		void init(Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, Mesh * mesh)>(FUNC_MESHRENDERER_INIT)(this, mesh);
		}
		void cleanup()
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self)>(FUNC_MESHRENDERER_CLEANUP)(this);
		}
		void initAttrs(Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, Mesh * mesh)>(FUNC_MESHRENDERER_INITATTRS)(this, mesh);
		}

		/* // these RE-s are perfectly fine but i decided to not use em lol
		
		MeshRenderer()
		{
			mode = 10;
			VAO = NULL;
			VBOs = nullptr;
			indexVBO = NULL;
			bufferCount = 0;
		}
		void setMesh(const Mesh* mesh)
		{
			if (VAO) 
				cleanup();
			init(mesh);
		}
		void updateMesh(const Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, const Mesh * mesh)>(base + idaOffsetFix(0x77130))(this, mesh);
		}
		~MeshRenderer()
		{
			if (VAO) 
				cleanup();
		}
		MeshRenderer* operator=(MeshRenderer* other)
		{
			return reinterpret_cast<MeshRenderer * (__thiscall*)(MeshRenderer * self, MeshRenderer * other)>(base + idaOffsetFix(0x772B0))(this, other);
		}
		void render()
		{
			glBindVertexArray(VAO);
			if (indexVBO)
			{
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBO);
				glDrawElements(mode, vertexCount, GL_UNSIGNED_INT, nullptr);
				glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, NULL);
			}
			else
				glDrawArrays(mode, 0, vertexCount);
			glBindBuffer(GL_ARRAY_BUFFER, NULL);
			glBindVertexArray(NULL);
		}
		void init(const Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, const Mesh * mesh)>(base + idaOffsetFix(0x773F0))(this, mesh);
		}
		void cleanup()
		{
			glBindVertexArray(VAO);
			glDeleteBuffers(bufferCount, VBOs);
			delete(VBOs);
			VBOs = nullptr;
			glDeleteBuffers(1, &indexVBO);
			indexVBO = NULL;
			glDeleteVertexArrays(1, &VAO);
			VAO = NULL;
			vertexCount = 0;
		}
		void initAttrs(const Mesh* mesh)
		{
			return reinterpret_cast<void(__thiscall*)(MeshRenderer * self, const Mesh * mesh)>(base + idaOffsetFix(0x77570))(this, mesh);
		}

		*/
	};
}
#endif
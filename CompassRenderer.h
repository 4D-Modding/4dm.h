#pragma once

#include "4dm.h"

namespace fdm 
{
	class CompassRenderer 
	{
	public:
		struct VertInfo 
		{
			glm::vec4 vert; 
			glm::vec3 color; // 0x10
			float normalComp; // 0x1C

		};
		inline static MeshBuilder* hypercubeTetMesh = reinterpret_cast<MeshBuilder*>((base + 0x278A68));
		inline static MeshRenderer* hypercubeTetRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278B60));
		inline static MeshRenderer* hypercubeHollowRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278B40));
		inline static MeshBuilder* cubeTetMesh = reinterpret_cast<MeshBuilder*>((base + 0x278960));
		inline static MeshRenderer* cubeTetRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278A48));
		inline static MeshBuilder* cubeTriangleMesh = reinterpret_cast<MeshBuilder*>((base + 0x2789D8));
		inline static MeshRenderer* cubeTriangleRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278908));
		inline static MeshBuilder* cubeWireframeMesh = reinterpret_cast<MeshBuilder*>((base + 0x278A10));
		inline static MeshRenderer* cubeWireframeRenderer = reinterpret_cast<MeshRenderer*>((base + 0x278998));
		inline static glm::vec3* line = reinterpret_cast<glm::vec3*>((base + 0x278440));
		inline static MeshBuilder* lineMesh = reinterpret_cast<MeshBuilder*>((base + 0x278928));
		inline static MeshRenderer* lineRenderer = reinterpret_cast<MeshRenderer*>((base + 0x2789B8));
		inline static FontRenderer* fr = reinterpret_cast<FontRenderer*>((base + 0x278AA0));
		inline static glm::vec4 *pd = reinterpret_cast<glm::vec4*>((base + 0x278480)); 
		inline static glm::vec4 *left = reinterpret_cast<glm::vec4*>((base + 0x278470)); 
		inline static glm::vec4 *over = reinterpret_cast<glm::vec4*>((base + 0x278460)); 
		inline static glm::vec4 *pos = reinterpret_cast<glm::vec4*>((base + 0x29B3D0)); 
		inline static glm::vec2 *rotation3D = reinterpret_cast<glm::vec2*>((base + 0x278458)); 
		inline static int* wWidth = reinterpret_cast<int*>((base + 0x29B3C8));
		inline static int* wHeight = reinterpret_cast<int*>((base + 0x29B3CC));

		inline static void renderHand(const glm::mat4& mat) 
		{
			return reinterpret_cast<void (__fastcall*)(const glm::mat4& mat)>(getFuncAddr((int)Func::CompassRenderer::renderHand))(mat);
		}
		inline static void renderItemDrop(const m4::Mat5& mat, const glm::vec4& lightDir) 
		{
			return reinterpret_cast<void (__fastcall*)(const m4::Mat5& mat, const glm::vec4& lightDir)>(getFuncAddr((int)Func::CompassRenderer::renderItemDrop))(mat, lightDir);
		}
	};
}

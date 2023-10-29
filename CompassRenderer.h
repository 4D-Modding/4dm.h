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
		inline static constexpr MeshBuilder hypercubeTetMesh = *reinterpret_cast<MeshBuilder*>((base + 0x278A68)); 
		inline static constexpr MeshRenderer hypercubeTetRenderer = *reinterpret_cast<MeshRenderer*>((base + 0x278B60)); 
		inline static constexpr MeshRenderer hypercubeHollowRenderer = *reinterpret_cast<MeshRenderer*>((base + 0x278B40)); 
		inline static constexpr MeshBuilder cubeTetMesh = *reinterpret_cast<MeshBuilder*>((base + 0x278960)); 
		inline static constexpr MeshRenderer cubeTetRenderer = *reinterpret_cast<MeshRenderer*>((base + 0x278A48)); 
		inline static constexpr MeshBuilder cubeTriangleMesh = *reinterpret_cast<MeshBuilder*>((base + 0x2789D8)); 
		inline static constexpr MeshRenderer cubeTriangleRenderer = *reinterpret_cast<MeshRenderer*>((base + 0x278908)); 
		inline static constexpr MeshBuilder cubeWireframeMesh = *reinterpret_cast<MeshBuilder*>((base + 0x278A10)); 
		inline static constexpr MeshRenderer cubeWireframeRenderer = *reinterpret_cast<MeshRenderer*>((base + 0x278998)); 
		inline static constexpr glm::vec3* line = *reinterpret_cast<glm::vec3**>((base + 0x278440)); 
		inline static constexpr MeshBuilder lineMesh = *reinterpret_cast<MeshBuilder*>((base + 0x278928)); 
		inline static constexpr MeshRenderer lineRenderer = *reinterpret_cast<MeshRenderer*>((base + 0x2789B8)); 
		inline static constexpr FontRenderer fr = *reinterpret_cast<FontRenderer*>((base + 0x278AA0)); 
		inline static constexpr glm::vec4 pd = *reinterpret_cast<glm::vec4*>((base + 0x278480)); 
		inline static constexpr glm::vec4 left = *reinterpret_cast<glm::vec4*>((base + 0x278470)); 
		inline static constexpr glm::vec4 over = *reinterpret_cast<glm::vec4*>((base + 0x278460)); 
		inline static constexpr glm::vec4 pos = *reinterpret_cast<glm::vec4*>((base + 0x29B3D0)); 
		inline static constexpr glm::vec2 rotation3D = *reinterpret_cast<glm::vec2*>((base + 0x278458)); 
		inline static constexpr int wWidth = *reinterpret_cast<int*>((base + 0x29B3C8)); 
		inline static constexpr int wHeight = *reinterpret_cast<int*>((base + 0x29B3CC)); 

		inline static void renderHand(const glm::mat4& mat) 
		{
			return reinterpret_cast<void (__fastcall*)(const glm::mat4& mat)>(FUNC_COMPASSRENDERER_RENDERHAND)(mat);
		}
		inline static void renderItemDrop(const m4::Mat5* mat, const glm::vec4& lightDir) 
		{
			return reinterpret_cast<void (__fastcall*)(const m4::Mat5* mat, const glm::vec4& lightDir)>(FUNC_COMPASSRENDERER_RENDERITEMDROP)(mat, lightDir);
		}
	};
}

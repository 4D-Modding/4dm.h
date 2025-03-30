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
		inline static MeshBuilder& hypercubeTetMesh = *reinterpret_cast<MeshBuilder*>(getDataAddr((int)Data::CompassRenderer::hypercubeTetMesh));
		inline static MeshRenderer& hypercubeTetRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::CompassRenderer::hypercubeTetRenderer));
		inline static MeshRenderer& hypercubeHollowRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::CompassRenderer::hypercubeHollowRenderer));
		inline static MeshBuilder& cubeTetMesh = *reinterpret_cast<MeshBuilder*>(getDataAddr((int)Data::CompassRenderer::cubeTetMesh));
		inline static MeshRenderer& cubeTetRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::CompassRenderer::cubeTetRenderer));
		inline static MeshBuilder& cubeTriangleMesh = *reinterpret_cast<MeshBuilder*>(getDataAddr((int)Data::CompassRenderer::cubeTriangleMesh));
		inline static MeshRenderer& cubeTriangleRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::CompassRenderer::cubeTriangleRenderer));
		inline static MeshBuilder& cubeWireframeMesh = *reinterpret_cast<MeshBuilder*>(getDataAddr((int)Data::CompassRenderer::cubeWireframeMesh));
		inline static MeshRenderer& cubeWireframeRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::CompassRenderer::cubeWireframeRenderer));
		inline static std::array<glm::vec3, 2>& line = *reinterpret_cast<std::array<glm::vec3, 2>*>(getDataAddr((int)Data::CompassRenderer::line));
		inline static MeshBuilder& lineMesh = *reinterpret_cast<MeshBuilder*>(getDataAddr((int)Data::CompassRenderer::lineMesh));
		inline static MeshRenderer& lineRenderer = *reinterpret_cast<MeshRenderer*>(getDataAddr((int)Data::CompassRenderer::lineRenderer));
		inline static FontRenderer& fr = *reinterpret_cast<FontRenderer*>(getDataAddr((int)Data::CompassRenderer::fr));
		inline static glm::vec4& pd = *reinterpret_cast<glm::vec4*>(getDataAddr((int)Data::CompassRenderer::pd));
		inline static glm::vec4& left = *reinterpret_cast<glm::vec4*>(getDataAddr((int)Data::CompassRenderer::left));
		inline static glm::vec4& over = *reinterpret_cast<glm::vec4*>(getDataAddr((int)Data::CompassRenderer::over));
		inline static glm::vec4& pos = *reinterpret_cast<glm::vec4*>(getDataAddr((int)Data::CompassRenderer::pos));
		inline static glm::vec2& rotation3D = *reinterpret_cast<glm::vec2*>(getDataAddr((int)Data::CompassRenderer::rotation3D));
		inline static int& wWidth = *reinterpret_cast<int*>(getDataAddr((int)Data::CompassRenderer::wWidth));
		inline static int& wHeight = *reinterpret_cast<int*>(getDataAddr((int)Data::CompassRenderer::wHeight));

		inline static void generateItemMesh()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::CompassRenderer::generateItemMesh))();
		}
		inline static void renderHand(const glm::mat4& mat)
		{
			return reinterpret_cast<void(__fastcall*)(const glm::mat4&)>(getFuncAddr((int)Func::CompassRenderer::renderHand))(mat);
		}
		inline static void renderInit()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::CompassRenderer::renderInit))();
		}
		inline static void renderItemDrop(const m4::Mat5& mat, const glm::vec4& lightDir)
		{
			return reinterpret_cast<void(__fastcall*)(const m4::Mat5&, const glm::vec4&)>(getFuncAddr((int)Func::CompassRenderer::renderItemDrop))(mat, lightDir);
		}
		inline static void renderText()
		{
			return reinterpret_cast<void(__fastcall*)()>(getFuncAddr((int)Func::CompassRenderer::renderText))();
		}
	};
}

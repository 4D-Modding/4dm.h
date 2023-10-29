#pragma once

#include "4dm.h"

namespace fdm 
{
	class PlayerSkin 
	{
	public:
		struct MeshBounds 
		{
			const glm::u8vec3 upperBound; 
			const glm::u8vec3 lowerBound; // 0x3
			const glm::u8vec3 origin; // 0x6
			uint32_t zOffset; // 0x9

		};
		class SkinMesh : public Mesh 
		{
			struct Pixel 
			{
				uint32_t r; 
				uint32_t g; // 0x1
				uint32_t b; // 0x2
				uint32_t a; // 0x3

			};
			struct VertInfo 
			{
				glm::vec4 vert; 
				glm::vec3 tuv; // 0x10
				int normalComp; // 0x1C

			};
			struct FaceInfo 
			{
				glm::u8vec3 upperBound; 
				glm::u8vec3 lowerBound; // 0x3

			};
			std::vector<PlayerSkin::SkinMesh::VertInfo,std::allocator<PlayerSkin::SkinMesh::VertInfo> > verts; // 0x8
			std::vector<uint32_t,std::allocator<uint32_t> > indices; // 0x20

			int vertCount() override
			{
				return reinterpret_cast<int (__thiscall*)(PlayerSkin::SkinMesh* self)>(FUNC_PLAYERSKIN_SKINMESH_VERTCOUNT)(this);
			}
			~SkinMesh() 
			{
				return reinterpret_cast<void(__thiscall*)(PlayerSkin::SkinMesh* self)>(FUNC_PLAYERSKIN_SKINMESH_DESTR_SKINMESH)(this);
			}
			void generate(const PlayerSkin::SkinMesh::Pixel* data, PlayerSkin::SkinMesh* meshBounds) 
			{
				return reinterpret_cast<void (__thiscall*)(PlayerSkin::SkinMesh* self, const PlayerSkin::SkinMesh::Pixel* data, PlayerSkin::SkinMesh* meshBounds)>(FUNC_PLAYERSKIN_SKINMESH_GENERATE)(this, data, meshBounds);
			}
			int buffSize(int buffIndex) override
			{
				return reinterpret_cast<int (__thiscall*)(PlayerSkin::SkinMesh* self, int buffIndex)>(FUNC_PLAYERSKIN_SKINMESH_BUFFSIZE)(this, buffIndex);
			}
			int attrCount() override
			{
				return reinterpret_cast<int (__thiscall*)(PlayerSkin::SkinMesh* self)>(FUNC_PLAYERSKIN_SKINMESH_ATTRCOUNT)(this);
			}
			uint32_t attrType(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<uint32_t (__thiscall*)(PlayerSkin::SkinMesh* self, int buffIndex, int attrIndex)>(FUNC_PLAYERSKIN_SKINMESH_ATTRTYPE)(this, buffIndex, attrIndex);
			}
			int attrSize(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int (__thiscall*)(PlayerSkin::SkinMesh* self, int buffIndex, int attrIndex)>(FUNC_PLAYERSKIN_SKINMESH_ATTRSIZE)(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) override
			{
				return reinterpret_cast<int (__thiscall*)(PlayerSkin::SkinMesh* self, int buffIndex, int attrIndex)>(FUNC_PLAYERSKIN_SKINMESH_ATTRSTRIDE)(this, buffIndex, attrIndex);
			}
			void addPixelToFace(std::hash<glm::u8vec2 >, std::equal_to<glm::u8vec2 >, std::allocator<std::pair<glm::u8vec2 const, PlayerSkin::SkinMesh::FaceInfo> > >* faceMap, const glm::i8vec2& compPos, const glm::u8vec3& pos) 
			{
				return reinterpret_cast<void (__thiscall*)(PlayerSkin::SkinMesh* self, std::hash<glm::u8vec2 >, std::equal_to<glm::u8vec2 >, std::allocator<std::pair<glm::u8vec2 const, PlayerSkin::SkinMesh::FaceInfo> > >* faceMap, const glm::i8vec2& compPos, const glm::u8vec3& pos)>(FUNC_PLAYERSKIN_SKINMESH_ADDPIXELTOFACE)(this, >, >, const, faceMap, compPos, pos);
			}
		};
		inline static const int WIDTH = 24; 
		inline static const int HEIGHT = 48; 
		inline static const int DEPTH = 42; 
		inline static constexpr PlayerSkin::MeshBounds* meshBounds = *reinterpret_cast<PlayerSkin::MeshBounds**>((base + 0x2B2F10)); 
		Tex2D tex; 
		MeshRenderer* meshComps; // 0x10

		bool load(std::string& path) 
		{
			return reinterpret_cast<bool (__thiscall*)(PlayerSkin* self, std::string& path)>(FUNC_PLAYERSKIN_LOAD)(this, path);
		}
		bool generateMesh(const PlayerSkin::SkinMesh::Pixel* data, int texWidth, int texHeight) 
		{
			return reinterpret_cast<bool (__thiscall*)(PlayerSkin* self, const PlayerSkin::SkinMesh::Pixel* data, int texWidth, int texHeight)>(FUNC_PLAYERSKIN_GENERATEMESH)(this, data, texWidth, texHeight);
		}
		~PlayerSkin() 
		{
			return reinterpret_cast<void(__thiscall*)(PlayerSkin* self)>(FUNC_PLAYERSKIN_DESTR_PLAYERSKIN)(this);
		}
	};
}

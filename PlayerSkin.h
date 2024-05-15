#pragma once

#include "4dm.h"

namespace fdm 
{
	class PlayerSkin 
	{
	public:
		enum MeshComp : int
		{
			HEAD = 0x0,
			TORSO = 0x1,
			UPPER_ARM_L = 0x2,
			UPPER_ARM_R = 0x3,
			FOREARM_L = 0x4,
			FOREARM_R = 0x5,
			THIGH_L = 0x6,
			THIGH_R = 0x7,
			LOWER_LEG_L = 0x8,
			LOWER_LEG_R = 0x9,
			MESH_COMP_COUNT = 0xA
		};
		struct MeshBounds 
		{
			const glm::u8vec3 upperBound; 
			const glm::u8vec3 lowerBound; // 0x3
			const glm::u8vec3 origin; // 0x6
			uint32_t zOffset; // 0x9

		};
		class SkinMesh : public Mesh 
		{
		public:
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
			std::vector<PlayerSkin::SkinMesh::VertInfo> verts; // 0x8
			std::vector<uint32_t> indices; // 0x20

			int vertCount() const override
			{
				return reinterpret_cast<int (__thiscall*)(const PlayerSkin::SkinMesh* self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::vertCount))(this);
			}
			~SkinMesh() 
			{
				reinterpret_cast<void(__thiscall*)(PlayerSkin::SkinMesh* self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::destr_SkinMesh))(this);
			}
			void generate(const PlayerSkin::SkinMesh::Pixel* data, PlayerSkin::SkinMesh* meshBounds) 
			{
				return reinterpret_cast<void (__thiscall*)(PlayerSkin::SkinMesh* self, const PlayerSkin::SkinMesh::Pixel* data, PlayerSkin::SkinMesh* meshBounds)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::generate))(this, data, meshBounds);
			}
			int buffSize(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const PlayerSkin::SkinMesh* self, int buffIndex)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::buffSize))(this, buffIndex);
			}
			int attrCount(int buffIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const PlayerSkin::SkinMesh* self, int buffIndex)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrCount))(this, buffIndex);
			}
			uint32_t attrType(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<uint32_t (__thiscall*)(const PlayerSkin::SkinMesh* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrType))(this, buffIndex, attrIndex);
			}
			int attrSize(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const PlayerSkin::SkinMesh* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrSize))(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int (__thiscall*)(const PlayerSkin::SkinMesh* self, int buffIndex, int attrIndex)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrStride))(this, buffIndex, attrIndex);
			}
			void addPixelToFace(std::unordered_map<glm::u8vec2, FaceInfo>& faceMap, const glm::i8vec2& compPos, const glm::u8vec3& pos) 
			{
				return reinterpret_cast<void (__thiscall*)(PlayerSkin::SkinMesh* self, std::unordered_map<glm::u8vec2, FaceInfo>& faceMap, const glm::i8vec2& compPos, const glm::u8vec3& pos)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::addPixelToFace))(this, faceMap, compPos, pos);
			}
		};
		inline static const int WIDTH = 24; 
		inline static const int HEIGHT = 48; 
		inline static const int DEPTH = 42; 
		inline static const PlayerSkin::MeshBounds meshBounds[MESH_COMP_COUNT] =
		{
		  {
			{ { 18u }, { 12u }, { 12u } },
			{ { 6u }, { 0u }, { 0u } },
			{ { 12u }, { 11u }, { 8u } },
			0u
		  },
		  {
			{ { 21u }, { 32u }, { 42u } },
			{ { 3u }, { 8u }, { 27u } },
			{ { 12u }, { 20u }, { 33u } },
			27u
		  },
		  {
			{ { 24u }, { 23u }, { 27u } },
			{ { 15u }, { 8u }, { 15u } },
			{ { 17u }, { 13u }, { 21u } },
			13u
		  },
		  {
			{ { 9u }, { 23u }, { 27u } },
			{ { 0u }, { 8u }, { 15u } },
			{ { 6u }, { 13u }, { 21u } },
			13u
		  },
		  {
			{ { 24u }, { 33u }, { 14u } },
			{ { 15u }, { 18u }, { 2u } },
			{ { 20u }, { 20u }, { 8u } },
			0u
		  },
		  {
			{ { 9u }, { 33u }, { 14u } },
			{ { 0u }, { 18u }, { 2u } },
			{ { 4u }, { 20u }, { 8u } },
			0u
		  },
		  {
			{ { 21u }, { 38u }, { 26u } },
			{ { 12u }, { 23u }, { 14u } },
			{ { 14u }, { 27u }, { 19u } },
			13u
		  },
		  {
			{ { 12u }, { 38u }, { 26u } },
			{ { 3u }, { 23u }, { 14u } },
			{ { 9u }, { 27u }, { 19u } },
			13u
		  },
		  {
			{ { 21u }, { 48u }, { 12u } },
			{ { 12u }, { 33u }, { 0u } },
			{ { 15u }, { 36u }, { 7u } },
			0u
		  },
		  {
			{ { 12u }, { 48u }, { 12u } },
			{ { 3u }, { 33u }, { 0u } },
			{ { 8u }, { 36u }, { 7u } },
			0u
		  }
		};
		Tex2D tex; 
		MeshRenderer meshComps[MESH_COMP_COUNT]; // 0x10

		bool load(stl::string& path) 
		{
			return reinterpret_cast<bool (__thiscall*)(PlayerSkin* self, stl::string& path)>(getFuncAddr((int)Func::PlayerSkin::load))(this, path);
		}
		bool generateMesh(const PlayerSkin::SkinMesh::Pixel* data, int texWidth, int texHeight) 
		{
			return reinterpret_cast<bool (__thiscall*)(PlayerSkin* self, const PlayerSkin::SkinMesh::Pixel* data, int texWidth, int texHeight)>(getFuncAddr((int)Func::PlayerSkin::generateMesh))(this, data, texWidth, texHeight);
		}
		~PlayerSkin() 
		{
			reinterpret_cast<void(__thiscall*)(PlayerSkin* self)>(getFuncAddr((int)Func::PlayerSkin::destr_PlayerSkin))(this);
		}
	};
}

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
			uint8_t zOffset; // 0x9

		};
		class SkinMesh : public Mesh 
		{
		public:
			struct Pixel 
			{
				uint8_t r; 
				uint8_t g; // 0x1
				uint8_t b; // 0x2
				uint8_t a; // 0x3

			};
			struct VertInfo 
			{
				glm::vec4 vert; 
				glm::vec3 tuv; // 0x10
				int8_t normalComp; // 0x1C

			};
			struct FaceInfo 
			{
				glm::u8vec3 upperBound; 
				glm::u8vec3 lowerBound; // 0x3

			};
			std::vector<PlayerSkin::SkinMesh::VertInfo> verts; // 0x8
			std::vector<uint32_t> indices; // 0x20

			~SkinMesh() 
			{
				reinterpret_cast<void(__thiscall*)(PlayerSkin::SkinMesh* self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::destr_SkinMesh))(this);
			}
			void generate(const PlayerSkin::SkinMesh::Pixel* data, PlayerSkin::SkinMesh* meshBounds) 
			{
				return reinterpret_cast<void (__thiscall*)(PlayerSkin::SkinMesh* self, const PlayerSkin::SkinMesh::Pixel* data, PlayerSkin::SkinMesh* meshBounds)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::generate))(this, data, meshBounds);
			}
			int attrCount(int buffIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self, int)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrCount))(this, buffIndex);
			}
			int attrSize(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self, int, int)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrSize))(this, buffIndex, attrIndex);
			}
			int attrStride(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self, int, int)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrStride))(this, buffIndex, attrIndex);
			}
			uint32_t attrType(int buffIndex, int attrIndex) const override
			{
				return reinterpret_cast<uint32_t(__thiscall*)(const PlayerSkin::SkinMesh * self, int, int)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::attrType))(this, buffIndex, attrIndex);
			}
			int buffCount() const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::buffCount))(this);
			}
			const void* buffData(int buffIndex) const override
			{
				return reinterpret_cast<const void* (__thiscall*)(const PlayerSkin::SkinMesh * self, int)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::buffData))(this, buffIndex);
			}
			int buffSize(int buffIndex) const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self, int)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::buffSize))(this, buffIndex);
			}
			void generate(const PlayerSkin::SkinMesh::Pixel* data, const PlayerSkin::MeshBounds& meshBounds)
			{
				return reinterpret_cast<void(__thiscall*)(PlayerSkin::SkinMesh * self, const PlayerSkin::SkinMesh::Pixel*, const PlayerSkin::MeshBounds&)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::generate))(this, data, meshBounds);
			}
			const void* indexBuffData() const override
			{
				return reinterpret_cast<const void* (__thiscall*)(const PlayerSkin::SkinMesh * self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::indexBuffData))(this);
			}
			int indexBuffSize() const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::indexBuffSize))(this);
			}
			int vertCount() const override
			{
				return reinterpret_cast<int(__thiscall*)(const PlayerSkin::SkinMesh * self)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::vertCount))(this);
			}
			void addPixelToFace(std::unordered_map<glm::u8vec2, FaceInfo>& faceMap, const glm::i8vec2& compPos, const glm::u8vec3& pos) 
			{
				return reinterpret_cast<void (__thiscall*)(PlayerSkin::SkinMesh* self, std::unordered_map<glm::u8vec2, FaceInfo>& faceMap, const glm::i8vec2& compPos, const glm::u8vec3& pos)>(getFuncAddr((int)Func::PlayerSkin::SkinMesh::addPixelToFace))(this, faceMap, compPos, pos);
			}
		};
		inline static const int WIDTH = 24; 
		inline static const int HEIGHT = 48; 
		inline static const int DEPTH = 42; 
		inline static std::array<const PlayerSkin::MeshBounds, 10>& meshBounds = *reinterpret_cast<std::array<const PlayerSkin::MeshBounds, 10>*>(getDataAddr((int)Data::PlayerSkin::meshBounds));

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

#pragma once

#include "4dm.h"

namespace fdm 
{
	class Skybox : public Mesh 
	{
	public:
		inline static Skybox& instance = *reinterpret_cast<Skybox*>(getDataAddr((int)Data::Skybox::instance));
		inline static constexpr const int VERTEX_COUNT = 36;
		inline static std::array<glm::vec3, VERTEX_COUNT>& verts = *reinterpret_cast<std::array<glm::vec3, VERTEX_COUNT>*>(getDataAddr((int)Data::Skybox::verts));
		inline static std::array<glm::vec2, VERTEX_COUNT>& uv = *reinterpret_cast<std::array<glm::vec2, VERTEX_COUNT>*>(getDataAddr((int)Data::Skybox::uv));

		int attrCount(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Skybox * self, int)>(getFuncAddr((int)Func::Skybox::attrCount))(this, buffIndex);
		}
		int attrSize(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Skybox * self, int, int)>(getFuncAddr((int)Func::Skybox::attrSize))(this, buffIndex, attrIndex);
		}
		int attrStride(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Skybox * self, int, int)>(getFuncAddr((int)Func::Skybox::attrStride))(this, buffIndex, attrIndex);
		}
		uint32_t attrType(int buffIndex, int attrIndex) const override
		{
			return reinterpret_cast<uint32_t(__thiscall*)(const Skybox * self, int, int)>(getFuncAddr((int)Func::Skybox::attrType))(this, buffIndex, attrIndex);
		}
		int buffCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const Skybox * self)>(getFuncAddr((int)Func::Skybox::buffCount))(this);
		}
		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const Skybox * self, int)>(getFuncAddr((int)Func::Skybox::buffData))(this, buffIndex);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int(__thiscall*)(const Skybox * self, int)>(getFuncAddr((int)Func::Skybox::buffSize))(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int(__thiscall*)(const Skybox * self)>(getFuncAddr((int)Func::Skybox::vertCount))(this);
		}
	};
}

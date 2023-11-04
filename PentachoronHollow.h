#pragma once

#include "4dm.h"

namespace fdm 
{
	class PentachoronHollow : public Mesh 
	{
	public:
		struct VertData 
		{
			glm::vec4 s; 
			glm::vec3 t; // 0x10

		};
		std::vector<PentachoronHollow::VertData> vertices; // 0x8

		const void* buffData(int buffIndex) const override
		{
			return reinterpret_cast<const void* (__thiscall*)(const PentachoronHollow* self, int buffIndex)>(FUNC_PENTACHORONHOLLOW_BUFFDATA)(this, buffIndex);
		}
		PentachoronHollow(float distance) 
		{
			reinterpret_cast<void(__thiscall*)(PentachoronHollow* self, float distance)>(FUNC_PENTACHORONHOLLOW_PENTACHORONHOLLOW)(this, distance);
		}
		int buffSize(int buffIndex) const override
		{
			return reinterpret_cast<int (__thiscall*)(const PentachoronHollow* self, int buffIndex)>(FUNC_PENTACHORONHOLLOW_BUFFSIZE)(this, buffIndex);
		}
		int vertCount() const override
		{
			return reinterpret_cast<int (__thiscall*)(const PentachoronHollow* self)>(FUNC_PENTACHORONHOLLOW_VERTCOUNT)(this);
		}
		void addTetSide(const glm::vec4& simp_ptr, const glm::vec4& inner, int i0, int i1, int i2) 
		{
			return reinterpret_cast<void (__thiscall*)(PentachoronHollow* self, const glm::vec4& simp_ptr, const glm::vec4& inner, int i0, int i1, int i2)>(FUNC_PENTACHORONHOLLOW_ADDTETSIDE)(this, simp_ptr, inner, i0, i1, i2);
		}
	};
}

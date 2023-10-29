#pragma once

#include "4dm.h"

namespace fdm 
{
	class QuadRenderer 
	{
	public:
		Shader* shader; 
		uint32_t VAO; // 0x8
		uint32_t* buffers; // 0xC
		uint32_t mode; // 0x1C
		uint32_t elementCount; // 0x20

		~QuadRenderer() 
		{
			return reinterpret_cast<void(__thiscall*)(QuadRenderer* self)>(FUNC_QUADRENDERER_DESTR_QUADRENDERER)(this);
		}
		bool init() 
		{
			return reinterpret_cast<bool (__thiscall*)(QuadRenderer* self)>(FUNC_QUADRENDERER_INIT)(this);
		}
		void setColor(float r, float g, float b, int a) 
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, float r, float g, float b, int a)>(FUNC_QUADRENDERER_SETCOLOR)(this, r, g, b, a);
		}
		void setPos(uint32_t x, int y, int w, int h) 
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, uint32_t x, int y, int w, int h)>(FUNC_QUADRENDERER_SETPOS)(this, x, y, w, h);
		}
	};
}

#pragma once

#include "4dm.h"

namespace fdm 
{
	class TexRenderer 
	{
	public:
		Tex2D* texture; 
		Shader* shader; // 0x8
		uint32_t VAO; // 0x10
		uint32_t* buffers; // 0x14

		~TexRenderer() 
		{
			return reinterpret_cast<void(__thiscall*)(TexRenderer* self)>(FUNC_TEXRENDERER_DESTR_TEXRENDERER)(this);
		}
		TexRenderer operator=(TexRenderer* other) 
		{
			return reinterpret_cast<TexRenderer (__thiscall*)(TexRenderer* self, TexRenderer* other)>(FUNC_TEXRENDERER_OPERATOREQ)(this, other);
		}
		bool init() 
		{
			return reinterpret_cast<bool (__thiscall*)(TexRenderer* self)>(FUNC_TEXRENDERER_INIT)(this);
		}
		void setClip(int x, int y, uint32_t w, uint32_t h) 
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, int x, int y, uint32_t w, uint32_t h)>(FUNC_TEXRENDERER_SETCLIP)(this, x, y, w, h);
		}
		void setColor(float r, float g, float b, int a) 
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, float r, float g, float b, int a)>(FUNC_TEXRENDERER_SETCOLOR)(this, r, g, b, a);
		}
		void setPos(uint32_t x, int y, int w, int h) 
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, uint32_t x, int y, int w, int h)>(FUNC_TEXRENDERER_SETPOS)(this, x, y, w, h);
		}
	};
}

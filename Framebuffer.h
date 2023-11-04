#pragma once

#include "4dm.h"

namespace fdm 
{
	class Framebuffer 
	{
	public:
		uint32_t framebuffer; 
		Tex2D tex2D; // 0x4
		Tex2D depthTex2D; // 0x14
		PAD(0x4);
		TexRenderer texRenderer; // 0x28

		~Framebuffer() 
		{
			reinterpret_cast<void(__thiscall*)(Framebuffer* self)>(FUNC_FRAMEBUFFER_DESTR_FRAMEBUFFER)(this);
		}
		void render() 
		{
			return reinterpret_cast<void (__thiscall*)(Framebuffer* self)>(FUNC_FRAMEBUFFER_RENDER)(this);
		}
		void init(GLsizei width, GLsizei height, bool alphaChannel) 
		{
			return reinterpret_cast<void (__thiscall*)(Framebuffer* self, GLsizei width, GLsizei height, bool alphaChannel)>(FUNC_FRAMEBUFFER_INIT)(this, width, height, alphaChannel);
		}
		void cleanup() 
		{
			return reinterpret_cast<void (__thiscall*)(Framebuffer* self)>(FUNC_FRAMEBUFFER_CLEANUP)(this);
		}
	};
}

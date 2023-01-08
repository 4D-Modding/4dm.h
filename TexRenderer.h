#pragma once
#ifndef TEXRENDERER_H
#define TEXRENDERER_H
#include "4dm.h"
namespace fdm 
{
	class Tex2D;
	class Shader;
	class TexRenderer
	{
	public:
		const Tex2D* texture;
		const Shader* shader;
		unsigned int VAO;
		unsigned int buffers[5];

		~TexRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(TexRenderer*)>(
				base + idaOffsetFix(0x92750)
				)(this);
		}
		TexRenderer operator=(TexRenderer& other) 
		{
			return reinterpret_cast<TexRenderer(__thiscall*)(TexRenderer*, TexRenderer&)>(
				base + idaOffsetFix(0x92790)
				)(this, other);
		}
		bool init() 
		{
			return reinterpret_cast<bool(__thiscall*)(TexRenderer*)>(
				base + idaOffsetFix(0x92840)
				)(this);
		}
		void setClip(int x, int y, unsigned int w, unsigned int h)
		{
			return reinterpret_cast<void(__thiscall*)(TexRenderer*, int, int, unsigned int, unsigned int)>(
				base + idaOffsetFix(0x92D20)
				)(this, x, y, w, h);
		}
		void setColor(float r, float g, float b, float a)
		{
			return reinterpret_cast<void(__thiscall*)(TexRenderer*, float, float, float, float)>(
				base + idaOffsetFix(0x92E50)
				)(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void(__thiscall*)(TexRenderer*, int, int, int, int)>(
				base + idaOffsetFix(0x92F30)
				)(this, x, y, w, h);
		}
	};
}
#endif
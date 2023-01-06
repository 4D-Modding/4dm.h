#pragma once
#ifndef QUADRENDERER_H
#define QUADRENDERER_H
#include "4dm.h"
namespace fdm
{
	class Shader;
	class QuadRenderer
	{
	public:
		const Shader* shader;
		unsigned int VAO;
		unsigned int buffers[4];
		unsigned int mode;
		unsigned int elementCount;
		~QuadRenderer()
		{
			glBindVertexArray(this->VAO);
			glDeleteBuffers(4, this->buffers);
			glDeleteVertexArrays(1, &this->VAO);
		}
		bool init(void) 
		{
			return reinterpret_cast<bool(__thiscall*)(QuadRenderer*)>(
				base + idaOffsetFix(0x855C0)
				)(this);
		}
		void setColor(float r, float g, float b, float a)
		{
			return reinterpret_cast<void(__thiscall*)(QuadRenderer*, float, float, float, float)>(
				base + idaOffsetFix(0x859D0)
				)(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void(__thiscall*)(QuadRenderer*, int, int, int, int)>(
				base + idaOffsetFix(0x85AB0)
				)(this, x, y, w, h);
		}
	};
}
#endif
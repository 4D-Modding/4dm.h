#pragma once

#include "4dm.h"

namespace fdm 
{
	class Shader;
	class QuadRenderer 
	{
	public:
		const Shader* shader; 
		unsigned int VAO; // 0x8
		unsigned int buffers[4]; // 0xC
		unsigned int mode; // 0x1C
		unsigned int elementCount; // 0x20

		~QuadRenderer()
		{
			glBindVertexArray(this->VAO);
			glDeleteBuffers(4, this->buffers);
			glDeleteVertexArrays(1, &this->VAO);
		}
		QuadRenderer() {}
		QuadRenderer(const Shader* shader)
		{
			this->shader = shader;
		}
		bool init() 
		{
			return reinterpret_cast<bool (__thiscall*)(QuadRenderer* self)>(FUNC_QUADRENDERER_INIT)(this);
		}
		void setColor(float r, float g, float b, float a) 
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, float r, float g, float b, float a)>(FUNC_QUADRENDERER_SETCOLOR)(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, int x, int y, int w, int h)>(FUNC_QUADRENDERER_SETPOS)(this, x, y, w, h);
		}

		// thx compiler for removing that and thx to mashpoe for telling me that it exists
		void render()
		{
			if (mode != 4)
			{
				if (VAO)
				{
					int data[5] = { 0, 1, 2, 2, 3 };
					glBindVertexArray(VAO);
					glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
					glBufferData(GL_ARRAY_BUFFER, 24, data, GL_STATIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, NULL);
				}
				mode = 4;
				elementCount = 6;
			}
			glUseProgram(shader->id());
			glBindVertexArray(VAO);
			glDrawElements(mode, elementCount, GL_UNSIGNED_INT, 0);
			glBindVertexArray(NULL);
		}

		// my variant
		void render(const glm::vec4& color, const glm::ivec2& pos, const glm::ivec2& size)
		{
			setColor(color.r, color.g, color.b, color.a);
			setPos(pos.x, pos.y, size.x, size.y);
			render();
		}
	};
}

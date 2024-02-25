#pragma once

#include "4dm.h"

namespace fdm 
{
	class Shader;
	class QuadRenderer 
	{
	public:
		const Shader* shader = nullptr;
		unsigned int VAO = 0; // 0x8
		unsigned int buffers[4] = { 0 }; // 0xC
		unsigned int mode = 4; // 0x1C
		unsigned int elementCount = 6; // 0x20

		~QuadRenderer()
		{
			if (VAO)
			{
				glBindVertexArray(this->VAO);
				glDeleteBuffers(4, this->buffers);
				glDeleteVertexArrays(1, &this->VAO);
			}
		}
		QuadRenderer() {}
		QuadRenderer(const Shader* shader)
		{
			this->shader = shader;
		}
		bool init() 
		{
			return reinterpret_cast<bool (__thiscall*)(QuadRenderer* self)>(getFuncAddr((int)Func::QuadRenderer::init))(this);
		}
		void setColor(float r, float g, float b, float a)
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, float r, float g, float b, float a)>(getFuncAddr((int)Func::QuadRenderer::setColor))(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, int x, int y, int w, int h)>(getFuncAddr((int)Func::QuadRenderer::setPos))(this, x, y, w, h);
		}

		// thx compiler for removing that and thx to mashpoe for telling me that it exists
		void render()
		{
			if (mode != 4)
			{
				if (VAO)
				{
					constexpr const int data[6] = { 0, 1, 2, 2, 3, 0 };
					glBindVertexArray(VAO);
					glBindBuffer(GL_ARRAY_BUFFER, buffers[0]);
					glBufferData(GL_ARRAY_BUFFER, 24, data, GL_STATIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, NULL);
				}
				mode = 4;
				elementCount = 6;
			}
			shader->use();
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

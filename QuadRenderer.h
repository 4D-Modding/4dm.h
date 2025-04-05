#pragma once

#include "4dm.h"

namespace fdm 
{
	class Shader;
	class QuadRenderer 
	{
	public:
		enum Mode : int
		{
			MODE_FILL = GL_TRIANGLES,
			MODE_LINES = GL_LINE_LOOP,
		};
		enum bufferIndex : int
		{
			VBO_INDEX = 0,
			VBO_VERTEX = 1,
			VBO_COLOR = 2,
			VBO_MODEL = 3,
			VBO_COUNT = 4,
		};

		const Shader* shader = nullptr;
		uint32_t VAO = 0; // 0x8
		uint32_t buffers[VBO_COUNT] = { 0 }; // 0xC
		uint32_t mode = MODE_FILL; // 0x1C
		uint32_t elementCount = 6; // 0x20

		~QuadRenderer()
		{
			if (VAO)
			{
				glBindVertexArray(this->VAO);
				glDeleteBuffers(VBO_COUNT, this->buffers);
				glDeleteVertexArrays(1, &this->VAO);
			}
		}
		QuadRenderer() {}
		QuadRenderer(const Shader* shader)
		{
			this->shader = shader;
		}
		QuadRenderer(const QuadRenderer& other) = delete;
		QuadRenderer& operator=(const QuadRenderer& other) = delete;
		QuadRenderer(QuadRenderer&& other) noexcept
		{
			shader = other.shader;
			VAO = other.VAO;
			mode = other.mode;
			elementCount = other.elementCount;
			std::memcpy(buffers, other.buffers, sizeof(buffers));

			other.shader = nullptr;
			other.VAO = 0;
			other.mode = MODE_FILL;
			other.elementCount = 6;
			std::memset(other.buffers, 0, sizeof(buffers));
		}
		QuadRenderer& operator=(QuadRenderer&& other) noexcept
		{
			shader = other.shader;
			VAO = other.VAO;
			mode = other.mode;
			elementCount = other.elementCount;
			std::memcpy(buffers, other.buffers, sizeof(buffers));

			other.shader = nullptr;
			other.VAO = 0;
			other.mode = MODE_FILL;
			other.elementCount = 6;
			std::memset(other.buffers, 0, sizeof(buffers));

			return *this;
		}
		bool init()
		{
			return reinterpret_cast<bool (__thiscall*)(QuadRenderer* self)>(getFuncAddr((int)Func::QuadRenderer::init))(this);
		}
		void setColor(const glm::vec4 (&colors)[4])
		{
			glBindVertexArray(VAO);

			glBindBuffer(GL_ARRAY_BUFFER, buffers[VBO_COLOR]);
			glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, colors, GL_STATIC_DRAW);

			glBindVertexArray(0);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}
		void setColor(float r, float g, float b, float a)
		{
			setColor(
				{
					{r, g, b, a},
					{r, g, b, a},
					{r, g, b, a},
					{r, g, b, a}
				});
			//return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, float r, float g, float b, float a)>(getFuncAddr((int)Func::QuadRenderer::setColor))(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(QuadRenderer* self, int x, int y, int w, int h)>(getFuncAddr((int)Func::QuadRenderer::setPos))(this, x, y, w, h);
		}
		// mash thx so much
		void setQuadRendererMode(GLuint mode)
		{
			if (mode == this->mode)
			{
				return;
			}

			if (mode == MODE_FILL)
			{
				constexpr GLuint indices[] = {
					0, 1, 2, // first triangle
					2, 3, 0  // second triangle
				};

				if (this->VAO != 0)
				{
					glBindVertexArray(this->VAO);
					glBindBuffer(GL_ARRAY_BUFFER, this->buffers[VBO_INDEX]);
					glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}

				this->mode = GL_TRIANGLES;
				this->elementCount = 6;
			}
			else
			{
				if (this->VAO != 0)
				{
					constexpr GLuint indices[] = {
						0, 1, 2, 3
					};

					glBindVertexArray(this->VAO);
					glBindBuffer(GL_ARRAY_BUFFER, this->buffers[VBO_INDEX]);
					glBufferData(GL_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
					glBindBuffer(GL_ARRAY_BUFFER, 0);
				}

				this->mode = GL_LINE_LOOP;
				this->elementCount = 4;
			}
		}
		void render()
		{
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

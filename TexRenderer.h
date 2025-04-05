#pragma once

#include "4dm.h"

namespace fdm 
{
	class TexRenderer 
	{
	public:
		enum bufferIndex : int
		{
			VBO_INDEX = 0,
			VBO_VERTEX = 1,
			VBO_TEX_COORD = 2,
			VBO_MODEL = 3,
			VBO_COLOR = 4,
			VBO_COUNT = 5,
		};
		const Tex2D* texture = nullptr; 
		const Shader* shader = nullptr; // 0x8
		uint32_t VAO = 0; // 0x10
		uint32_t buffers[VBO_COUNT]{ 0 }; // 0x14

		~TexRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(TexRenderer* self)>(getFuncAddr((int)Func::TexRenderer::destr_TexRenderer))(this);
		}
		TexRenderer() {}
		TexRenderer(const Tex2D* texture, const Shader* shader)
		{
			this->texture = texture;
			this->shader = shader;
		}
		TexRenderer(const TexRenderer& other) = delete;
		TexRenderer& operator=(const TexRenderer& other) = delete;
		TexRenderer(TexRenderer&& other) noexcept
		{
			texture = other.texture;
			shader = other.shader;
			VAO = other.VAO;
			std::memcpy(buffers, other.buffers, sizeof(buffers));

			other.texture = nullptr;
			other.shader = nullptr;
			other.VAO = 0;
			std::memset(other.buffers, 0, sizeof(buffers));
		}
		TexRenderer& operator=(TexRenderer&& other) noexcept
		{
			reinterpret_cast<TexRenderer& (__thiscall*)(TexRenderer* self, TexRenderer& other)>(getFuncAddr((int)Func::TexRenderer::operatorEq))(this, other);
			return *this;
		}
		bool init() 
		{
			return reinterpret_cast<bool (__thiscall*)(TexRenderer* self)>(getFuncAddr((int)Func::TexRenderer::init))(this);
		}
		void setClip(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, int x, int y, int w, int h)>(getFuncAddr((int)Func::TexRenderer::setClip))(this, x, y, w, h);
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
			//return reinterpret_cast<void (__thiscall*)(TexRenderer* self, float r, float g, float b, float a)>(getFuncAddr((int)Func::TexRenderer::setColor))(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, int x, int y, int w, int h)>(getFuncAddr((int)Func::TexRenderer::setPos))(this, x, y, w, h);
		}
		// thx compiler for removing that and thx to mashpoe for telling me that it exists
		void render()
		{
			glUseProgram(shader->id());
			texture->use();
			glBindVertexArray(VAO);
			glDrawElements(4, 6, GL_UNSIGNED_INT, NULL);
			glBindVertexArray(0);
			glBindTexture(GL_TEXTURE_2D, 0);
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

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
		TexRenderer(){}
		TexRenderer(const Tex2D* texture, const Shader* shader)
		{
			this->texture = texture;
			this->shader = shader;
		}
		TexRenderer* operator=(TexRenderer* other) noexcept
		{
			glBindVertexArray(this->VAO);
			glDeleteBuffers(5, this->buffers);
			glDeleteVertexArrays(1, &this->VAO);

			this->texture = other->texture;
			other->texture = 0;
			this->shader = other->shader;
			other->shader = 0;
			this->VAO = other->VAO;
			other->VAO = 0;
			this->buffers[0] = other->buffers[0];
			other->buffers[0] = 0;
			this->buffers[1] = other->buffers[1];
			other->buffers[1] = 0;
			this->buffers[2] = other->buffers[2];
			other->buffers[2] = 0;
			this->buffers[3] = other->buffers[3];
			other->buffers[3] = 0;
			this->buffers[4] = other->buffers[4];
			other->buffers[4] = 0;

			return this;
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
		// thx compiler for removing that and thx to mashpoe for telling me that it exists
		void render()
		{
			glActiveTexture(GL_TEXTURE0);
			glUseProgram(shader->id());
			glBindTexture(GL_TEXTURE_2D, texture->ID);
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
#endif
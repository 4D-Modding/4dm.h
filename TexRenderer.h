#pragma once

#include "4dm.h"

namespace fdm 
{
	class TexRenderer 
	{
	public:
		const Tex2D* texture; 
		const Shader* shader; // 0x8
		uint32_t VAO; // 0x10
		uint32_t buffers[5]; // 0x14

		~TexRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(TexRenderer* self)>(FUNC_TEXRENDERER_DESTR_TEXRENDERER)(this);
		}
		TexRenderer& operator=(TexRenderer& other) 
		{
			reinterpret_cast<TexRenderer& (__thiscall*)(TexRenderer* self, TexRenderer& other)>(FUNC_TEXRENDERER_OPERATOREQ)(this, other);
			return *this;
		}
		bool init() 
		{
			return reinterpret_cast<bool (__thiscall*)(TexRenderer* self)>(FUNC_TEXRENDERER_INIT)(this);
		}
		void setClip(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, int x, int y, int w, int h)>(FUNC_TEXRENDERER_SETCLIP)(this, x, y, w, h);
		}
		void setColor(float r, float g, float b, float a) 
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, float r, float g, float b, float a)>(FUNC_TEXRENDERER_SETCOLOR)(this, r, g, b, a);
		}
		void setPos(int x, int y, int w, int h)
		{
			return reinterpret_cast<void (__thiscall*)(TexRenderer* self, int x, int y, int w, int h)>(FUNC_TEXRENDERER_SETPOS)(this, x, y, w, h);
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

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
			reinterpret_cast<void(__thiscall*)(Framebuffer* self)>(getFuncAddr((int)Func::Framebuffer::destr_Framebuffer))(this);
		}
		const Shader* getShader()
		{
			return texRenderer.shader;
		}
		void setShader(const Shader* shader)
		{
			texRenderer.shader = shader;
		}
		void render() 
		{
			const Shader* s = getShader();
			s->use();
			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, depthTex2D.ID);
			glUniform1i(glGetUniformLocation(s->id(), "depth"), 1);
			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, tex2D.ID);
			glUniform1i(glGetUniformLocation(s->id(), "texture"), 0);

			texRenderer.render();
		}
		void init(GLsizei width, GLsizei height, bool alphaChannel) 
		{
			return reinterpret_cast<void (__thiscall*)(Framebuffer* self, GLsizei width, GLsizei height, bool alphaChannel)>(getFuncAddr((int)Func::Framebuffer::init))(this, width, height, alphaChannel);
		}
		void cleanup() 
		{
			return reinterpret_cast<void (__thiscall*)(Framebuffer* self)>(getFuncAddr((int)Func::Framebuffer::cleanup))(this);
		}
	};
}

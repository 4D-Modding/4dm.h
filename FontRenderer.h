#pragma once

#include "4dm.h"

#include "Tex2D.h"
#include "Shader.h"

namespace fdm 
{
	class Shader;
	class Tex2D;
	class FontRenderer 
	{
	public:
		stl::string text; 
		glm::ivec2 charSize; // 0x20
		int fontSize; // 0x28
		glm::ivec2 pos; // 0x2C
		glm::vec4 color; // 0x34
		glm::mat4 model; // 0x44
		bool centered; // 0x84
		PAD(0x3);
		const Tex2D* texture; // 0x88
		const Shader* shader; // 0x90
		unsigned int VAO; // 0x98
		unsigned int charVBO; // 0x9C

		FontRenderer(const Tex2D* texture, const Shader* shader) 
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer* self, const Tex2D* texture, const Shader* shader)>(getFuncAddr((int)Func::FontRenderer::FontRenderer))(this, texture, shader);
		}
		FontRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer* self)>(getFuncAddr((int)Func::FontRenderer::FontRendererA))(this);
		}
		void setText(const stl::string& text) 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self, const stl::string& text)>(getFuncAddr((int)Func::FontRenderer::setText))(this, text);
		}
		void render() 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self)>(getFuncAddr((int)Func::FontRenderer::render))(this);
		}
		void updateModel() 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self)>(getFuncAddr((int)Func::FontRenderer::updateModel))(this);
		}
		void move(FontRenderer& other) 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self, FontRenderer& other)>(getFuncAddr((int)Func::FontRenderer::move))(this, other);
		}
	};
}

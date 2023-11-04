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
		std::string text; 
		glm::ivec2 charSize; // 0x20
		int fontSize; // 0x28
		glm::ivec2 pos; // 0x2C
		glm::vec4 color; // 0x34
		glm::mat4 model; // 0x44
		bool centered; // 0x84
		PAD(0x3);
		Tex2D* texture; // 0x88
		Shader* shader; // 0x90
		uint32_t VAO; // 0x98
		uint32_t charVBO; // 0x9C

		FontRenderer(const Tex2D* texture, const Shader* shader) 
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer* self, const Tex2D* texture, const Shader* shader)>(FUNC_FONTRENDERER_FONTRENDERER)(this, texture, shader);
		}
		FontRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer* self)>(FUNC_FONTRENDERER_FONTRENDERER_A)(this);
		}
		void setText(const std::string& text) 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self, const std::string& text)>(FUNC_FONTRENDERER_SETTEXT)(this, text);
		}
		void render() 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self)>(FUNC_FONTRENDERER_RENDER)(this);
		}
		void updateModel() 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self)>(FUNC_FONTRENDERER_UPDATEMODEL)(this);
		}
		void move(FontRenderer& other) 
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer* self, FontRenderer& other)>(FUNC_FONTRENDERER_MOVE)(this, other);
		}
	};
}

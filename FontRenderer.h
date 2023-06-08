#pragma once
#ifndef FONTRENDERER_H
#define FONTRENDERER_H
#include "4dm.h"
namespace fdm
{
	class Tex2D;
	class Shader;

	class FontRenderer
	{
	public:
		std::string text;
		glm::ivec2 charSize;
		int fontSize = 1;
		glm::ivec2 pos;
		glm::vec4 color{1.0f};
		glm::mat4 model;
		bool centered;
		PAD(3);
		const Tex2D* texture;
		const Shader* shader;
		unsigned int VAO;
		unsigned int charVBO;

		FontRenderer(){}
		FontRenderer(const Tex2D* texture, const Shader* shader) {
			reinterpret_cast<void(__thiscall*)(FontRenderer*, const Tex2D*, const Shader*)>(
				FUNC_FONTRENDERER_FONTRENDERER
				)(this, texture, shader);
		}
		FontRenderer* operator=(FontRenderer* other) 
		{
			return reinterpret_cast<FontRenderer*(__thiscall*)(FontRenderer*, FontRenderer*)>(
				FUNC_FONTRENDERER_OPERATOR_EQ
				)(this, other);
		}
		void setText(const std::string& text)
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer*, const std::string&)>(
				FUNC_FONTRENDERER_SETTEXT
				)(this, text);
		}
		void render(void) 
		{
			return reinterpret_cast<void(__thiscall*)(FontRenderer*)>(
				FUNC_FONTRENDERER_RENDER
				)(this);
		}
		void updateModel(void)
		{
			return reinterpret_cast<void(__thiscall*)(FontRenderer*)>(
				FUNC_FONTRENDERER_UPDATEMODEL
				)(this);
		}
	};
}
#endif
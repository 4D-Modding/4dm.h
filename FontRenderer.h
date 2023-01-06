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
		int fontSize;
		glm::ivec2 pos;
		glm::vec4 color;
		glm::mat4x4 model;
		bool centered;
		PAD(3);
		const Tex2D* texture;
		const Shader* shader;
		unsigned int VAO;
		unsigned int charVBO;

		FontRenderer(const Tex2D* texture, const Shader* shader) {
			reinterpret_cast<void(__thiscall*)(FontRenderer*, const Tex2D*, const Shader*)>(
				base + idaOffsetFix(0x4F8F0)
				)(this, texture, shader);
		}
		FontRenderer* operator=(FontRenderer* other) 
		{
			return reinterpret_cast<FontRenderer*(__thiscall*)(FontRenderer*, FontRenderer*)>(
				base + idaOffsetFix(0x4FA90)
				)(this, other);
		}
		void setText(const std::string& text)
		{
			return reinterpret_cast<void (__thiscall*)(FontRenderer*, const std::string&)>(
				base + idaOffsetFix(0x4FBA0)
				)(this, text);
		}
		void render(void) 
		{
			return reinterpret_cast<void(__thiscall*)(FontRenderer*)>(
				base + idaOffsetFix(0x4FC30)
				)(this);
		}
		void updateModel(void)
		{
			return reinterpret_cast<void(__thiscall*)(FontRenderer*)>(
				base + idaOffsetFix(0x4FD50)
				)(this);
		}
	};
}
#endif
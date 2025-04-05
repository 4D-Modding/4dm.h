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
		stl::string text = "";
		glm::ivec2 charSize{ 8, 8 }; // 0x20
		int fontSize = 1; // 0x28
		glm::ivec2 pos{ 0, 0 }; // 0x2C
		glm::vec4 color{ 1 }; // 0x34
		glm::mat4 model{ 1 }; // 0x44
		bool centered = false; // 0x84
		PAD(0x3);
		const Tex2D* texture = nullptr; // 0x88
		const Shader* shader = nullptr; // 0x90
		uint32_t VAO = 0; // 0x98
		uint32_t charVBO = 0; // 0x9C

		FontRenderer(const Tex2D* texture, const Shader* shader) 
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer* self, const Tex2D* texture, const Shader* shader)>(getFuncAddr((int)Func::FontRenderer::FontRenderer))(this, texture, shader);
		}
		FontRenderer() 
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer* self)>(getFuncAddr((int)Func::FontRenderer::FontRendererA))(this);
		}
		FontRenderer(const FontRenderer& other) = delete;
		FontRenderer& operator=(const FontRenderer& other) = delete;
		FontRenderer(FontRenderer&& other) noexcept
		{
			text = other.text;
			charSize = other.charSize;
			fontSize = other.fontSize;
			pos = other.pos;
			color = other.color;
			model = other.model;
			centered = other.centered;
			texture = other.texture;
			shader = other.shader;
			VAO = other.VAO;
			charVBO = other.charVBO;

			other.text = "";
			other.charSize = { 8, 8 };
			other.fontSize = 1;
			other.pos = { 0, 0 };
			other.color = glm::vec4{ 1 };
			other.model = glm::mat4{ 1 };
			other.centered = false;
			other.texture = nullptr;
			other.shader = nullptr;
			other.VAO = 0;
			other.charVBO = 0;
		}
		FontRenderer& operator=(FontRenderer&& other) noexcept
		{
			text = other.text;
			charSize = other.charSize;
			fontSize = other.fontSize;
			pos = other.pos;
			color = other.color;
			model = other.model;
			centered = other.centered;
			texture = other.texture;
			shader = other.shader;
			VAO = other.VAO;
			charVBO = other.charVBO;

			other.text = "";
			other.charSize = { 8, 8 };
			other.fontSize = 1;
			other.pos = { 0, 0 };
			other.color = glm::vec4{ 1 };
			other.model = glm::mat4{ 1 };
			other.centered = false;
			other.texture = nullptr;
			other.shader = nullptr;
			other.VAO = 0;
			other.charVBO = 0;

			return *this;
		}
		~FontRenderer()
		{
			reinterpret_cast<void(__thiscall*)(FontRenderer * self)>(getFuncAddr((int)Func::FontRenderer::destr_FontRenderer))(this);
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

#pragma once
#ifndef SHADER_H
#define SHADER_H
#include "4dm.h"
namespace fdm
{
	class Shader
	{
	public:
		enum shaderType
		{
			VERTEX_SHADER = 0xffff8b31,
			GEOMETRY_SHADER = 0xffff8dd9,
			FRAGMENT_SHADER = 0xffff8b30,
		};
		unsigned int ID;
		bool load(const std::string& vertexPath, const std::string& fragmentPath) 
		{
			return reinterpret_cast<bool(__thiscall*)(Shader*, const std::string & vertexPath, const std::string & fragmentPath)>(
				base + idaOffsetFix(0x8A140)
				)(this, vertexPath, fragmentPath);
		}
		unsigned int compileShader(const std::string& path, shaderType type) 
		{
			return reinterpret_cast<unsigned int(__thiscall*)(Shader*, const std::string & path, shaderType fragmentPath)>(
				base + idaOffsetFix(0x8A270)
				)(this, path, type);
		}
	};
}
#endif
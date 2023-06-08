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
				FUNC_SHADER_LOAD
				)(this, vertexPath, fragmentPath);
		}
		unsigned int compileShader(const std::string& path, shaderType type) 
		{
			return reinterpret_cast<unsigned int(__thiscall*)(Shader*, const std::string & path, shaderType fragmentPath)>(
				FUNC_SHADER_COMPILESHADER
				)(this, path, type);
		}
		bool load(const std::string& vertexPath, const std::string& fragmentPath) const
		{
			return reinterpret_cast<bool(__thiscall*)(const Shader*, const std::string & vertexPath, const std::string & fragmentPath)>(
				FUNC_SHADER_LOAD
				)(this, vertexPath, fragmentPath);
		}
		unsigned int compileShader(const std::string& path, shaderType type) const
		{
			return reinterpret_cast<unsigned int(__thiscall*)(const Shader*, const std::string & path, shaderType fragmentPath)>(
				FUNC_SHADER_COMPILESHADER
				)(this, path, type);
		}
		unsigned int id() const
		{
			return ID;
		}
		void use() const
		{
			glUseProgram(ID);
		}
		unsigned int id()
		{
			return ID;
		}
		void use()
		{
			glUseProgram(ID);
		}
	};
}
#endif
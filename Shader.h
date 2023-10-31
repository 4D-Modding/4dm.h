#pragma once

#include "4dm.h"

namespace fdm
{
	class Shader
	{
	public:
		enum shaderType
		{
			VERTEX_SHADER = 0x8B31,
			GEOMETRY_SHADER = 0x8DD9,
			FRAGMENT_SHADER = 0x8B30
		};
		unsigned int ID;
		bool load(const std::string& vertexPath, const std::string& fragmentPath) 
		{
			return reinterpret_cast<bool(__thiscall*)(Shader*, const std::string & vertexPath, const std::string & fragmentPath)>(
				FUNC_SHADER_LOAD
				)(this, vertexPath, fragmentPath);
		}
		// thank you mashed potatoes for this
		bool load(const std::string& vertexPath, const std::string& geometryPath, const std::string& fragmentPath)
		{
			if (ID != 0)
			{
				glDeleteProgram(ID);
			}

			unsigned int vertex = compileShader(vertexPath, VERTEX_SHADER);
			unsigned int geometry = compileShader(geometryPath, GEOMETRY_SHADER);
			unsigned int fragment = compileShader(fragmentPath, FRAGMENT_SHADER);

			if (vertex != 0 && geometry != 0 && fragment != 0)
			{
				// shader Program
				ID = glCreateProgram();
				glAttachShader(ID, vertex);
				glAttachShader(ID, geometry);
				glAttachShader(ID, fragment);
				glLinkProgram(ID);
				// print linking errors if any
				int success;
				char infoLog[512];
				glGetProgramiv(ID, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(ID, 512, NULL, infoLog);
					std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
				}
			}

			// delete the shaders as they're linked into our program now and no longer necessary
			glDeleteShader(vertex);
			glDeleteShader(geometry);
			glDeleteShader(fragment);

			return ID != 0;
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
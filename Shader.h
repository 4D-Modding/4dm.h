#pragma once

#include "4dm.h"

namespace fdm
{
	class Shader
	{
	public:
		enum shaderType
		{
			VERTEX_SHADER = GL_VERTEX_SHADER,
			GEOMETRY_SHADER = GL_GEOMETRY_SHADER,
			FRAGMENT_SHADER = GL_FRAGMENT_SHADER
		};
		unsigned int ID;
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
		bool load(const std::string& vertexPath, const std::string& fragmentPath)
		{
			return reinterpret_cast<bool(__thiscall*)(Shader*, const std::string & vertexPath, const std::string & fragmentPath)>(
				getFuncAddr((int)Func::Shader::load)
				)(this, vertexPath, fragmentPath);
		}
		unsigned int compileShader(const std::string& path, shaderType type) const
		{
			return reinterpret_cast<unsigned int(__thiscall*)(const Shader*, const std::string & path, shaderType fragmentPath)>(
				getFuncAddr((int)Func::Shader::compileShader)
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
	};
}

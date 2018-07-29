#include "shader.h"
#include <iostream>
#include <GL\glew.h>
#include <fstream>
#include <sstream>
#include <string>

#include "../util/errorLogging.h"

Shader::Shader(const std::string& filePath)
{
	ShaderProgramSource source = ParseShader(filePath);
	m_shader = CreateShader(source.VertexSource, source.FragmentSource);
}

Shader::~Shader()
{
	glDeleteProgram(m_shader);
}

void Shader::SetUniformMat4(const std::string & uniformName, glm::mat4 matrix, bool normalized)
{
	int location = GetLocation(uniformName);
	GLCALL(glUniformMatrix4fv(location, 1, normalized, &matrix[0][0]));
}

void Shader::SetUniformInt1(const std::string & uniformName, int value)
{
	int location = GetLocation(uniformName);
	GLCALL(glUniform1i(location, value));
}

void Shader::BindShader()
{
	glUseProgram(m_shader);
}

void Shader::UnbindShader()
{
	glUseProgram(m_shader);
}

unsigned int Shader::CreateShader(const std::string & vertexShader, const std::string & fragmentShader)
{
	unsigned int program = glCreateProgram();
	unsigned int vs = CompileShader(GL_VERTEX_SHADER, vertexShader);
	unsigned int fs = CompileShader(GL_FRAGMENT_SHADER, fragmentShader);

	GLCALL(glAttachShader(program, vs));
	GLCALL(glAttachShader(program, fs));
	GLCALL(glLinkProgram(program));
	GLCALL(glValidateProgram(program));

	GLCALL(glDeleteShader(vs));
	GLCALL(glDeleteShader(fs));

	return program;
}

unsigned int Shader::CompileShader(unsigned int type, const std::string & source)
{
	unsigned int id = glCreateShader(type);
	const char* src = source.c_str();
	GLCALL(glShaderSource(id, 1, &src, nullptr));
	GLCALL(glCompileShader(id));

	// Error Handling
	int result;
	GLCALL(glGetShaderiv(id, GL_COMPILE_STATUS, &result));
	if (result == GL_FALSE) {
		int messageLength;
		GLCALL(glGetShaderiv(id, GL_INFO_LOG_LENGTH, &messageLength));
		char* message = (char*) alloca(messageLength * sizeof(char));
		GLCALL(glGetShaderInfoLog(id, messageLength, &messageLength, message));
		std::cout << "Failed to compile" << std::endl;
		std::cout << message << std::endl;
		return 0;
	}

	return id;
}

ShaderProgramSource Shader::ParseShader(const std::string & filePath)
{
	enum class ShaderType {
		NONE = -1, VERTEX = 0, FRAGMENT = 1
	};
	std::ifstream stream(filePath);

	std::string line;
	std::stringstream ss[2];
	ShaderType type = ShaderType::NONE;

	while (getline(stream, line)) {
		if (line.find("#shader") != std::string::npos) {
			if (line.find("vertex") != std::string::npos)
				type = ShaderType::VERTEX;
			else if (line.find("fragment") != std::string::npos)
				type = ShaderType::FRAGMENT;
		}
		else {
			ss[(int)type] << line << "\n";
		}
	}

	return { ss[0].str(), ss[1].str() };
}

int Shader::GetLocation(const std::string & uniformName)
{
	GLCALL(int location = glGetUniformLocation(m_shader, uniformName.c_str()));
	return location;
}

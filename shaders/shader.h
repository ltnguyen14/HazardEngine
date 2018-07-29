#pragma once
#include <string>
#include <glm.hpp>

struct ShaderProgramSource {
	std::string VertexSource;
	std::string FragmentSource;
};

class Shader {

public:
	Shader(const std::string& filePath);
	~Shader();

	void SetUniformMat4(const std::string& uniformName, glm::mat4 matrix, bool normalized = false);
	void SetUniformInt1(const std::string& uniformName, int value);

	void BindShader();
	void UnbindShader();
	unsigned int m_shader;

private:
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);

	unsigned int CompileShader(unsigned int type, const std::string& source);

	ShaderProgramSource ParseShader(const std::string& filePath);

private:
	int GetLocation(const std::string& uniformName);
};
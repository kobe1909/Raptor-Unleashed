#include "Shader.h"
#include "components/BaseComponent.h"

#include <GL/glew.h>
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>

Shader::Shader(std::string vertexPath, std::string fragmentPath) : m_vertexPath(vertexPath), m_fragmentPath(fragmentPath) {
	m_RendererID = CreateShader();
}

Shader::~Shader() {
}

void Shader::Bind() const {
	glUseProgram(m_RendererID);
}

void Shader::UnBind() const {
	glUseProgram(0);
}

unsigned int Shader::CreateShader() {
	unsigned int vs = CompileShader(m_vertexPath, GL_VERTEX_SHADER);
	unsigned int fs = CompileShader(m_fragmentPath, GL_FRAGMENT_SHADER);
	
	unsigned int program = glCreateProgram();

	glAttachShader(program, vs);
	glAttachShader(program, fs);
	glLinkProgram(program);
	glValidateProgram(program);

	glDeleteShader(vs);
	glDeleteShader(fs);

	return program;
}

unsigned int Shader::CompileShader(std::string filepath, unsigned int type) {
	// read shader file
	std::stringstream shaderStringStream;
	std::ifstream stream(filepath);
	std::string line;
	
	while (getline(stream, line)) {
		shaderStringStream << line << '\n';
	}

	std::string shader = shaderStringStream.str();

	// create shader
	unsigned int id = glCreateShader(type);
	const char* src = shader.c_str();
	glShaderSource(id, 1, &src, nullptr);
	glCompileShader(id);

	int result;
	glGetShaderiv(id, GL_COMPILE_STATUS, &result);
	if (result == GL_FALSE) {
		int length;
		glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
		char* message = (char*)alloca(length * sizeof(char));
		glGetShaderInfoLog(id, length, &length, message);
		std::cout << "Failed to compile " << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << " shader!" << std::endl;
		std::cout << message << std::endl;
		glDeleteShader(id);
		return 0;
	}

	return id;
}


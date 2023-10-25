#include "Shader.h"

Shader::Shader() : m_RendererID(0) {

}

void Shader::CreateShader() {

}

void Shader::CompileShader() {

}

void Shader::ParseShader() {

}


void Shader::Bind() const {
	glUseProgram(m_RendererID);
}

void Shader::UnBind() const {
	glUseProgram(0);
}
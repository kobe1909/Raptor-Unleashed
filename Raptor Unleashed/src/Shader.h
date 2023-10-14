#pragma once

#include <string>

class Shader {
private:
	std::string m_fragmentPath;
	std::string m_vertexPath;

	unsigned int m_RendererID;

public:
	Shader(std::string vertexPath, std::string fragmentPath);
	~Shader();

	void Bind() const;
	void UnBind() const;

private:
	unsigned int CreateShader();
	unsigned int CompileShader(std::string filepath, unsigned int type);
};

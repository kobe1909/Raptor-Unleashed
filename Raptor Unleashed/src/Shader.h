#pragma once

#include "Renderer.h"

class Shader {
private:
	unsigned int m_RendererID;

	void CreateShader();
	void CompileShader();
	void ParseShader();

public:
	Shader();

	void Bind() const;
	void UnBind() const;
};
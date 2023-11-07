#pragma once

#include "../Renderer.h"

class VertexArrayObject {
private:
	unsigned int m_renderID;

public:
	VertexArrayObject();
	~VertexArrayObject();

	void Bind() const;
	void UnBind() const;
};
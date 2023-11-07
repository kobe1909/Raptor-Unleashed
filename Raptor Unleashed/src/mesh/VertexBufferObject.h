#pragma once

#include "../Renderer.h"

class VertexBufferObject {
private:
	unsigned int m_rendererID;

public:
	VertexBufferObject();
	~VertexBufferObject();

	void Bind() const;
	void UnBind() const;
};
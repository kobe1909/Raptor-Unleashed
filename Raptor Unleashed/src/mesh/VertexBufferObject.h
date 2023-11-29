#pragma once

#include "../Renderer.h"

class VertexBufferObject {
private:
	unsigned int m_rendererID;

public:
	VertexBufferObject() : m_rendererID(0) {}
	VertexBufferObject(const void* data, unsigned int size);
	~VertexBufferObject();

	void Bind() const;
	void UnBind() const;
};
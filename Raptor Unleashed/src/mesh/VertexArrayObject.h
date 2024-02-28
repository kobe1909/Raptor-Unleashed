#pragma once

#include "../Renderer.h"

#include "VertexBufferObject.h"
#include "VertexBufferLayout.h"

class VertexArrayObject {
private:
	unsigned int m_rendererID;

public:
	VertexArrayObject();
	VertexArrayObject(const VertexArrayObject& other);
	~VertexArrayObject();

	void AddBuffer(const VertexBufferObject& vb, const VertexBufferLayout& layout);

	void Bind() const;
	void UnBind() const;
};
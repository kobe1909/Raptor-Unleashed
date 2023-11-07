#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject(const void* data, unsigned int size) : m_rendererID(0) {
	GLCall(glGenBuffers(1, &m_rendererID));
	Bind();
	GLCall(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

VertexBufferObject::~VertexBufferObject() {
	GLCall(glDeleteBuffers(1, &m_rendererID));
}

void VertexBufferObject::Bind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}

void VertexBufferObject::UnBind() const {
	GLCall(glBindBuffer(GL_ARRAY_BUFFER, m_rendererID));
}
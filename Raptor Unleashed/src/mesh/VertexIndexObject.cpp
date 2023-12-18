#include "VertexIndexObject.h"

VertexIndexObject::VertexIndexObject(const unsigned int* data, unsigned int count) : m_rendererID(0), m_count(count) {
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));

	GLCall(glGenBuffers(1, &m_rendererID));
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
	GLCall(glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), data, GL_STATIC_DRAW));
}

VertexIndexObject::~VertexIndexObject() {
	GLCall(glDeleteBuffers(1, &m_rendererID))
}

void VertexIndexObject::Bind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void VertexIndexObject::UnBind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}
#include "VertexIndexObject.h"

VertexIndexObject::VertexIndexObject() : m_rendererID(0) {

}

VertexIndexObject::~VertexIndexObject() {
	GLCall(glDeleteBuffers(1, &m_rendererID))
}

void VertexIndexObject::Bind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}

void VertexIndexObject::UnBind() const {
	GLCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_rendererID));
}
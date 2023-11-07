#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() : m_rendererID(0) {

}

VertexArrayObject::~VertexArrayObject() {
	GLCall(glDeleteVertexArrays(1, &m_rendererID));
}

void VertexArrayObject::Bind() const {
	GLCall(glBindVertexArray(m_rendererID));
}

void VertexArrayObject::UnBind() const{
	GLCall(glBindVertexArray(0));
}
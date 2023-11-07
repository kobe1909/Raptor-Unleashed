#include "VertexBufferObject.h"

VertexBufferObject::VertexBufferObject() {

}

VertexBufferObject::~VertexBufferObject() {

}

void VertexBufferObject::Bind() const {
	glBindVertexBuffer(m_rendererID);
}

void VertexBufferObject::UnBind() const {
	glBindVertexBuffer(0);
}
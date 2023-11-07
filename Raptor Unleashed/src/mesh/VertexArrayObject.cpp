#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() {

}

VertexArrayObject::~VertexArrayObject() {

}

void VertexArrayObject::Bind() const {
	glBindVertexArray(m_renderID);
}

void VertexArrayObject::UnBind() const{
	glBindVertexArray(0);
}
#include "Mesh.h"

Mesh::Mesh(VertexBufferObject& vb, VertexIndexObject& vi, VertexArrayObject& va)
	: m_bufferObject(vb), m_indexObject(vi), m_arrayObject(va) {

}

void Mesh::Bind() const {
	m_arrayObject.Bind();
	m_indexObject.Bind();
}
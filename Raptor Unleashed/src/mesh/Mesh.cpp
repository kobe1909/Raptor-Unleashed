#include "Mesh.h"

Mesh::Mesh(VertexBufferObject& vb, VertexIndexObject& vi, VertexArrayObject& va)
	: m_bufferObject(vb), m_indexObject(vi), m_arrayObject(va) {

}

Mesh::Mesh(const void* vertices, unsigned int verticesSize, VertexBufferLayout& layout, const unsigned int* triangles, unsigned int triangleCount) {
	m_bufferObject = VertexBufferObject(vertices, verticesSize);
	m_indexObject = VertexIndexObject(triangles, triangleCount);
	m_arrayObject = VertexArrayObject();
	m_arrayObject.AddBuffer(m_bufferObject, layout);
}

unsigned int Mesh::GetTriangleCount() {
	return m_indexObject.GetCount();
}

void Mesh::Bind() const {
	m_arrayObject.Bind();
	m_indexObject.Bind();
}

void Mesh::UnBind() const {
	m_arrayObject.UnBind();
	m_indexObject.UnBind();
}
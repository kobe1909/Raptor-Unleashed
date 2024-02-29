#include "Mesh.h"
#include <iostream>

//Mesh::Mesh(VertexBufferObject& vb, VertexIndexObject& vi, VertexArrayObject& va)
//	: m_bufferObject(vb), m_indexObject(vi), m_arrayObject(va) {
//
//}

Mesh::Mesh(const void* vertices, unsigned int verticesSize, VertexBufferLayout& layout, const unsigned int* triangles, unsigned int triangleCount) 
	: m_arrayObject(), m_bufferObject(vertices, verticesSize), m_indexObject(triangles, triangleCount)
{
	m_arrayObject.AddBuffer(m_bufferObject, layout);
}

Mesh::Mesh(const Mesh& other) 
	: m_arrayObject(other.m_arrayObject), m_bufferObject(other.m_bufferObject), m_indexObject(other.m_indexObject)
{}

unsigned int Mesh::GetTriangleCount() {
	return m_indexObject.GetCount();
}

MeshComponent* Mesh::ToMeshComponent() {
	MeshComponent component(*this);
	return &component;
}

void Mesh::Bind() const {
	m_arrayObject.Bind();
	m_indexObject.Bind();
	m_bufferObject.Bind();
}

void Mesh::UnBind() const {
	m_arrayObject.UnBind();
	m_indexObject.UnBind();
	m_bufferObject.UnBind();
}
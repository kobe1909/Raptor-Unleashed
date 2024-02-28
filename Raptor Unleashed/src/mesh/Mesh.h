#pragma once

#include <string>

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexIndexObject.h"
#include "VertexBufferLayout.h"

class Mesh {
private:
	VertexBufferObject m_bufferObject;
	VertexIndexObject m_indexObject;
	VertexArrayObject m_arrayObject;

public:
	//Mesh(VertexBufferObject& vb, VertexIndexObject& vi, VertexArrayObject& va);
	Mesh(const void* vertices, unsigned int verticesSize, VertexBufferLayout& layout, const unsigned int* triangleData, unsigned int triangleCount);
	Mesh(const Mesh& other);

	unsigned int GetTriangleCount();

	void Bind() const;
	void UnBind() const;
};
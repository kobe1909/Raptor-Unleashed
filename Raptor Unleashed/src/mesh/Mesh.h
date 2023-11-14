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
	Mesh(VertexBufferObject vb, VertexIndexObject vi, VertexArrayObject va);
	Mesh(std::string& filePath);

	void Bind() const;
	void UnBind() const;
};
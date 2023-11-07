#pragma once

#include <vector>

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "VertexIndexObject.h"

class Mesh {
private:
	VertexBufferObject m_bufferObject;
	VertexIndexObject m_indexObject;
	VertexArrayObject m_vertexArrayObject;

public:

};
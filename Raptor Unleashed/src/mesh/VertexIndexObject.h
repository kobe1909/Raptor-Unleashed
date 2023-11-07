#pragma once

#include "../Renderer.h"

class VertexIndexObject {
private:
	unsigned int m_renderID;

public:
	VertexIndexObject();
	~VertexIndexObject();

	void Bind() const;
	void UnBind() const;
};
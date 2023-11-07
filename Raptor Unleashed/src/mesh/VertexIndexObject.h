#pragma once

#include "../Renderer.h"

class VertexIndexObject {
private:
	unsigned int m_rendererID;

public:
	VertexIndexObject();
	~VertexIndexObject();

	void Bind() const;
	void UnBind() const;
};
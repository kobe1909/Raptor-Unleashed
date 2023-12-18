#pragma once

#include "../Renderer.h"

class VertexIndexObject {
private:
	unsigned int m_rendererID;
	unsigned int m_count;

public:
	//VertexIndexObject() : m_rendererID(0), m_count(0) {}
	VertexIndexObject(const unsigned int* data, unsigned int count);
	~VertexIndexObject();

	void Bind() const;
	void UnBind() const;

	inline unsigned int GetCount() const { return m_count;  }
};
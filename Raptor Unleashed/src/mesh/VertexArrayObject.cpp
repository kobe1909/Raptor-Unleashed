#include "VertexArrayObject.h"

VertexArrayObject::VertexArrayObject() : m_rendererID(0) {
	GLCall(glGenVertexArrays(1, &m_rendererID));
}

VertexArrayObject::~VertexArrayObject() {
	GLCall(glDeleteVertexArrays(1, &m_rendererID));
}

void VertexArrayObject::AddBuffer(const VertexBufferObject& vb, const VertexBufferLayout& layout) {
	Bind();
	vb.Bind();

	const auto& elements = layout.GetElements();
	unsigned int offset = 0;

	for (unsigned int i = 0; i < elements.size(); i++) {
		const auto& element = elements[i];

		GLCall(glEnableVertexAttribArray(i));
		GLCall(glVertexAttribPointer(i, element.count, element.type, element.normalized, layout.GetStride(), (const void*)offset));
		offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
	}
}

void VertexArrayObject::Bind() const {
	GLCall(glBindVertexArray(m_rendererID));
}

void VertexArrayObject::UnBind() const{
	GLCall(glBindVertexArray(0));
}
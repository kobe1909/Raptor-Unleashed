#include "GameObject.h"
#include <iostream>

GameObject::GameObject(Transform transform, std::map<std::string, BaseComponent*> components)
	: m_Components(components), transform() {

}

GameObject::GameObject() : m_Components(), transform() {

}

GameObject::~GameObject() {
	m_Components.clear();
}

template <typename T>
T GameObject::GetComponent(std::string name) {
	return *static_cast<T*>(m_Components[name]);
}

void GameObject::Render() {
	Mesh mesh = GetComponent<MeshComponent>("Mesh").GetMesh();
	std::cout << "Triangle count: " << mesh.GetTriangleCount() << std::endl;
	mesh.Bind();
	GLCall(glDrawElements(GL_TRIANGLES, mesh.GetTriangleCount(), GL_UNSIGNED_INT, nullptr));
}
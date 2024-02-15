#include "GameObject.h"

GameObject::GameObject(Transform transform, std::map<std::string, BaseComponent*> components)
	: m_Components(components) {

}

GameObject::~GameObject() {
	m_Components.clear();
}

template <typename T>
T GameObject::GetComponent(std::string name) {
	return static_cast<T>(m_Components[name]);
}
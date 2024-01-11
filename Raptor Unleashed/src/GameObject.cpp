#include "GameObject.h"

GameObject::GameObject(Transform transform, std::vector<std::tuple<std::string, BaseComponent>> components) : transform(transform), m_Components(components) {
	
}

GameObject::~GameObject() {

}

BaseComponent* GameObject::GetComponent(std::string name) {
	for (int i = 0; i < m_Components.size(); i++) {
		std::tuple<std::string, BaseComponent> item = m_Components[i];

		BaseComponent component = std::get<1>(item);
		if (std::get<0>(item) == name)
			return &component;
	}

	return NULL;
}
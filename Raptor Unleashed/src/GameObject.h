#pragma once

#include <string>
#include <map>
#include "components/BaseComponent/BaseComponent.h"
#include "Transform.h"
#include "components/MeshComponent/MeshComponent.h"
#include "components/MaterialComponent/MaterialComponent.h"

class GameObject {
private:
	std::map<std::string, BaseComponent*> m_Components;

public:
	Transform transform;
	GameObject(Transform transform, std::map<std::string, BaseComponent*> components);
	~GameObject();

	template <typename T>
	T GetComponent(std::string name);
};


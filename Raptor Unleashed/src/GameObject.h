#pragma once

#include <tuple>
#include <string>
#include <vector>
#include <map>
#include "components/BaseComponent/BaseComponent.h"
#include "Transform.h"
#include "components/MeshComponent/MeshComponent.h"
#include "components/MaterialComponent/MaterialComponent.h"

class GameObject {
private:
	std::vector<std::tuple<std::string, BaseComponent>> m_Components;

	std::map<std::string, BaseComponent*> map;

public:
	Transform transform;
	GameObject(Transform transform, std::vector<std::tuple<std::string, BaseComponent>> components);
	~GameObject();

	template <typename T>
	T GetComponent(std::string name);

	BaseComponent* GetComponent(std::string name);
};


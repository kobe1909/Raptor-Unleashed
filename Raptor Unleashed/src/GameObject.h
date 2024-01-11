#pragma once

#include <tuple>
#include <string>
#include <vector>
#include "components/BaseComponent/BaseComponent.h"
#include "Transform.h"
#include "components/MeshComponent/MeshComponent.h"
#include "components/MaterialComponent/MaterialComponent.h"

class GameObject {
private:
	std::vector<std::tuple<std::string, BaseComponent>> m_Components;

public:
	Transform transform;
	GameObject(Transform transform, std::vector<std::tuple<std::string, BaseComponent>> components);
	~GameObject();

	BaseComponent* GetComponent(std::string name);
};


#pragma once

#include <vector>
#include "components/BaseComponent/BaseComponent.h"
#include "Transform.h"

class GameObject {
public:
	std::vector<BaseComponent> components;

	GameObject(Transform transform);
};


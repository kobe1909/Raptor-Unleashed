#pragma once

#include "components/BaseComponent/BaseComponent.h"
#include "glm/glm.hpp"

class Transform : public BaseComponent {
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	Transform();
	Transform(glm::vec3 n_position, glm::vec3 n_rotation, glm::vec3 scale);
};


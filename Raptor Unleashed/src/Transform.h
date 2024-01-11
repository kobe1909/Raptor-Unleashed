#pragma once

#include "components/BaseComponent/BaseComponent.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

class Transform : public BaseComponent {
public:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;

	glm::mat4 model;

	Transform();
	Transform(glm::vec3 n_position, glm::vec3 n_rotation, glm::vec3 n_scale);
};


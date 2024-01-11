#include "Transform.h"


Transform::Transform() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {

}

Transform::Transform(glm::vec3 n_position, glm::vec3 n_rotation, glm::vec3 n_scale)
	: position(n_position), rotation(n_rotation), scale(n_scale) {
	model = glm::scale(glm::rotate(glm::rotate(glm::rotate(glm::translate(glm::mat4(1.0f), position), glm::radians(rotation.x), glm::vec3(1, 0, 0)), glm::radians(rotation.y), glm::vec3(0, 1, 0)), glm::radians(rotation.z), glm::vec3(0, 0, 1)), scale);
}

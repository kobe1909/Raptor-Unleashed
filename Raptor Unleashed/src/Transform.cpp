#include "Transform.h"

Transform::Transform() : position(0, 0, 0), rotation(0, 0, 0), scale(1, 1, 1) {

}

Transform::Transform(Vector3 n_position, Vector3 n_rotation, Vector3 n_scale)
	: position(n_position), rotation(n_rotation), scale(n_scale) {

}

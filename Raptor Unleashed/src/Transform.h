#pragma once

#include "Math.h"
#include "components/BaseComponent/BaseComponent.h"

class Transform : public BaseComponent {
public:
	Vector3 position;
	Vector3 rotation;
	Vector3 scale;

	Transform();
	Transform(Vector3 n_position, Vector3 n_rotation, Vector3 scale);
};


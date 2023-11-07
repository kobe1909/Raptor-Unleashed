#include "GameObject.h"

GameObject::GameObject(Transform transform) {
	components.push_back(transform);
}
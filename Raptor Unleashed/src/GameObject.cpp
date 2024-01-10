#include "GameObject.h"

GameObject::GameObject(Transform transform, std::vector<BaseComponent> components) : transform(transform), components(components) {
	
}
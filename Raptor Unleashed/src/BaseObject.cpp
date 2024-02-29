#include "BaseObject.h"

void BaseObject::AddToScene(Scene scene) {
	void (BaseObject::*awake)() = &OnAwake;

	scene.onAwake.push_back(awake);
}
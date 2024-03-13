#include "BaseObject.h"

void BaseObject::AddToScene(Scene scene) {
	BaseObject* pointer = this;
	scene.onAwake.push_back(pointer);
	scene.onStart.push_back(pointer);
	scene.onUpdate.push_back(pointer);
	scene.onDraw.push_back(pointer);
	scene.onDestroy.push_back(pointer);
}

class Player : public BaseObject {
	Player(Scene scene) {
		AddToScene(scene);
	}
	void OnAwake  () {}
	void OnStart  () {}
	void OnUpdate () {}
	void OnDraw   () {}
	void OnDestroy() {}
};
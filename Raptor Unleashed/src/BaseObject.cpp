#include "BaseObject.h"

void BaseObject::AddToScene(Scene scene) {
	void (BaseObject::*awake)  () = &OnAwake;
	void (BaseObject::*start)  () = &OnStart;
	void (BaseObject::*update) () = &OnUpdate;
	void (BaseObject::*draw)   () = &OnDraw;
	void (BaseObject::*destroy)() = &OnDestroy;

	scene.onAwake.push_back(awake);
	scene.onStart.push_back(start);
	scene.onUpdate.push_back(update);
	scene.onDraw.push_back(draw);
	scene.onDestroy.push_back(destroy);
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
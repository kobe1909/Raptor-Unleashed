#pragma once
#include "../Scene.h"

class BaseObject {
public:
	void AddToScene(Scene scene);

	void OnAwake  () {}
	void OnStart  () {}
	void OnUpdate () {}
	void OnDraw   () {}
	void OnDestroy() {}
};
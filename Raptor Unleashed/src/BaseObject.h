#pragma once
#include "Scene.h"

class BaseObject {
public:
	void AddToScene(Scene scene);

	virtual void OnAwake  () {}
	virtual void OnStart  () {}
	virtual void OnUpdate () {}
	virtual void OnDraw   () {}
	virtual void OnDestroy() {}
};
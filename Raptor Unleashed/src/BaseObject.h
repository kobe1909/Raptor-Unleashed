#pragma once
#include "../Scene.h"

class BaseObject {
public:
	void AddToScene(Scene scene);

	void OnAwake () {};
	virtual void OnStart () = 0;
	virtual void OnUpdate() = 0;
	virtual void OnDraw  () = 0;
	virtual void OnUpdate() = 0;
};
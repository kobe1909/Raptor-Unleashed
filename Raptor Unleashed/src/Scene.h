#pragma once
#include <vector>
#include "BaseObject.h"

class Scene {
public:
	std::vector<void (BaseObject::*)()> onAwake   = {};
	std::vector<void (BaseObject::*)()> onStart   = {};
	std::vector<void (BaseObject::*)()> onUpdate  = {};
	std::vector<void (BaseObject::*)()> onDraw    = {};
	std::vector<void (BaseObject::*)()> onDestroy = {};

	void Awake  ();
	void Start  ();
	void Update ();
	void Draw   ();
	void Destroy();



private:
	void callVector(std::vector<void (BaseObject::*)()>);
};
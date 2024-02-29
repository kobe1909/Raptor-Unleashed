#pragma once
#include <vector>
#include "BaseObject.h"

class Scene {
public:
	std::vector<void (*)()> onAwake   = {};
	std::vector<void (*)()> onStart   = {};
	std::vector<void (*)()> onUpdate  = {};
	std::vector<void (*)()> onDraw    = {};
	std::vector<void (*)()> onDestroy = {};

	void Awake  ();
	void Start  ();
	void Update ();
	void Draw   ();
	void Destroy();

private:
	void callVector(std::vector<void (*)()>);
};
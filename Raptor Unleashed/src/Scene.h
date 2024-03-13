#pragma once
#include <vector>
#include "BaseObject.h"

typedef std::vector<BaseObject*> funcArray;

class Scene {
public:
	std::vector<BaseObject*> onAwake   = {};
	std::vector<BaseObject*> onStart = {};
	std::vector<BaseObject*> onUpdate = {};
	std::vector<BaseObject*> onDraw = {};
	std::vector<BaseObject*> onDestroy = {};

	void Awake  ();
	void Start  ();
	void Update ();
	void Draw   ();
	void Destroy();
};
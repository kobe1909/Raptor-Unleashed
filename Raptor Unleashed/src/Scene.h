#pragma once
#include <vector>
#include <map>
#include "BaseObject.h"

typedef std::vector<BaseObject*> funcArray;

class Scene {
public:
	funcArray onAwake   = {};
	funcArray onStart   = {};
	funcArray onUpdate  = {};
	funcArray onDraw    = {};
	funcArray onDestroy = {};

	void Awake  ();
	void Start  ();
	void Update ();
	void Draw   ();
	void Destroy();
};
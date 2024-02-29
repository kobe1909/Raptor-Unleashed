#pragma once


#include <map>


// BaseObject Interface
class BaseObject {
};

class Player : public BaseObject {
public:
	int shader;
	int mesh;
public:
	Player(int shader, int mesh) : shader(shader), mesh(mesh) {

	}
	void Awake() {}
	void Start() {}
	void Update() {}
	void Destroy() {}
	void Draw() {}
};


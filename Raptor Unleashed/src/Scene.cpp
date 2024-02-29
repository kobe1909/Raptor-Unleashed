#include "Scene.h"

void Scene::Awake() {
	callVector(onAwake);
}

void Scene::Start() {
	callVector(onStart);
}

void Scene::Update() {
	callVector(onUpdate);
}

void Scene::Draw() {
	callVector(onDraw);
}

void Scene::Destroy() {
	callVector(onDestroy);
}

void Scene::callVector(std::vector<void (*)()> vec) {
	for (auto& element : vec) {
		element();
	}
}

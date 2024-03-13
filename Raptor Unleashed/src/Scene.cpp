#include "Scene.h"

void Scene::Awake() {
	for (auto& element : onAwake) {
		element->OnAwake();
	}
}

void Scene::Start() {
	for (auto& element : onStart) {
		element->OnStart();
	}
}

void Scene::Update() {
	for (auto& element : onUpdate) {
		element->OnUpdate();
	}
}

void Scene::Draw() {
	for (auto& element : onDraw) {
		element->OnDraw();
	}
}

void Scene::Destroy() {
	for (auto& element : onDestroy) {
		element->OnDestroy();
	}
}

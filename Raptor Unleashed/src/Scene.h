#pragma once

#include <map>
#include <tuple>
#include <string>
#include "GameObject.h"

class Scene {
private:
	std::map<std::string, GameObject> m_Objects;

public:
	Scene(std::map<std::string, GameObject> objects);
	~Scene();

	GameObject GetObject(std::string name);
	void AddObject(std::string name, GameObject gameObject);

	void Render();
};
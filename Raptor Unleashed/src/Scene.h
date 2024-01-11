#pragma once

#include <vector>
#include <tuple>
#include <string>
#include "GameObject.h"

class Scene {
private:
	std::vector<std::tuple<std::string, GameObject>> m_Objects;

public:
	Scene(std::vector<std::tuple<std::string, GameObject>> objects);
	~Scene();

	GameObject GetObject(std::string);

	void Render();
};
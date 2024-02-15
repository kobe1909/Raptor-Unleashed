#include "Scene.h"

Scene::Scene(std::map<std::string, GameObject> objects)
 : m_Objects(objects) {

}

Scene::~Scene() {
	m_Objects.clear();
}

GameObject Scene::GetObject(std::string name) {
	return m_Objects[name];
}

void Scene::AddObject(std::string name, GameObject gameObject) {
	m_Objects.insert({ name, gameObject });
}

void Scene::Render() {
	for (auto const& x : m_Objects) {
		std::string name = x.first;
		GameObject gameObject = x.second;
		
		gameObject.Render();
	}
}
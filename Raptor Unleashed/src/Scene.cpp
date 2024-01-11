#include "Scene.h"

Scene::Scene(std::vector<std::tuple<std::string, GameObject>> objects)
 : m_Objects(objects) {

}

Scene::~Scene() {
	m_Objects.clear();
}

GameObject Scene::GetObject(std::string name) {
	for (int i = 0; i < m_Objects.size(); i++) {
		std::tuple<std::string, GameObject> item = m_Objects[i];
		if (std::get<0>(item) == name) {
			return std::get<1>(item);
		}
	}
}

void Scene::Render() {
	for (std::tuple<std::string, GameObject> item : m_Objects) {
		GameObject object = std::get<1>(item);
		MeshComponent meshComponent = *reinterpret_cast<MeshComponent*>(object.GetComponent("Mesh"));
		MaterialComponent materialComponent = *reinterpret_cast<MaterialComponent*>(object.GetComponent("Material"));
	}
}
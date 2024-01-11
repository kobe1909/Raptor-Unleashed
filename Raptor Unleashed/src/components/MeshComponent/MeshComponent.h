#pragma once

#include "../../mesh/Mesh.h"
#include "../BaseComponent/BaseComponent.h"

class MeshComponent : public BaseComponent {
private:
	Mesh m_Mesh;

public:
	MeshComponent(Mesh mesh);

	inline Mesh GetMesh() { return m_Mesh; }
	inline void SetMesh(Mesh mesh) { m_Mesh = mesh; }
};


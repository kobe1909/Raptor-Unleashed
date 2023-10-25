#pragma once

class BaseComponent {
private:

public:
	BaseComponent();

	void Awake();
	void Start();
	void Update();
	void LateUpdate();
	void Destroy();
	void Bind();
};
#include "BaseObject.h"
#include <iostream>

int main() {
	std::map<int, BaseObject*> map{
		{0, &Player(10, 0)}
	};

	Player test = *reinterpret_cast<Player*>(map[0]);
	std::cout << test.shader;

	void (*func)(int, int) = &test;
}
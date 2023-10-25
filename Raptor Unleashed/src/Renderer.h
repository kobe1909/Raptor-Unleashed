#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError();\
	x;\
	ASSERT(GLLogCall(#x, __FILE__, __LINE__))


void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);


class Renderer {
public:
	GLFWwindow* window;

	void CreateWindow(unsigned int width, unsigned int height, const char* name, GLFWmonitor* monitor = NULL, GLFWwindow* share = NULL);
};
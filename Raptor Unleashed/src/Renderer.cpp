# include "Renderer.h"

#include <iostream>

void GLClearError() {
	while (glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = glGetError()) {
		std::cout << "[OpenGl Error] (" << error << "): " << function << " in " << file << " on " << line << std::endl;
		return false;
	}
	return true;
}

void Renderer::CreateWindow(
	unsigned int width, 
	unsigned int height, 
	const char* name, 
	GLFWmonitor *monitor = NULL, 
	GLFWwindow *share = NULL
) {
	window = glfwCreateWindow(width, height, name, monitor, share);
}
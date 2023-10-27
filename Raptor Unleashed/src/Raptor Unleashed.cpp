// Raptor Unleashed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "renderer.h"

int main(void) {
	Renderer renderer;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	renderer.CreateWindow(640, 480, "Raptor Unleashed");

	// Sets the background color (values are normalized)
	glClearColor(.8, 0, .8, 1);
	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(renderer.GetWindow())) {
		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);

		/* Swap front and back buffers */
		glfwSwapBuffers(renderer.GetWindow());

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
// Raptor Unleashed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

#include "mesh/VertexArrayObject.h"
#include "mesh/VertexBufferLayout.h"
#include "mesh/VertexBufferObject.h"
#include "mesh/VertexIndexObject.h"

int main(void) {
	Renderer renderer;

	/* Initialize the library */
	if (!glfwInit())
		return -1;


	renderer.CreateWindow(640, 480, "Raptor Unleashed");

	// Limit the framerate to the vsync
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Sets the background color (values are normalized)
	glClearColor(.8, 0, .8, 1);
	
	float positions[] = {
		-.5f, -.5f,
		 .5f, -.5f,
		   0,  .5f
	};

	unsigned int indices[] = {
		0, 1, 2
	};

	VertexArrayObject va;
	VertexBufferObject vb(positions, 3 * 2 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(2);
	va.AddBuffer(vb, layout);

	VertexIndexObject ib(indices, 3);
	
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
// Raptor Unleashed.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "Renderer.h"

#include "mesh/VertexArrayObject.h"
#include "mesh/VertexBufferLayout.h"
#include "mesh/VertexBufferObject.h"
#include "mesh/VertexIndexObject.h"
#include "mesh/Mesh.h"
#include "Shader.h"
#include "mesh/Mesh.h"

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
	
	// x, y, z, r, g, b
	float vertices[] = {
		0, 0, 0,	1, 1, 1,
		0, 0, 1,	1, 1, 1,
		0, 1, 0,	1, 1, 1,
		0, 1, 1,	1, 1, 1,
		1, 0, 0,	1, 1, 1,
		1, 0, 1,	1, 1, 1,
		1, 1, 0,	1, 1, 1,
		1, 1, 1,	1, 1, 1
	};

	unsigned int indices[] = {
		0, 1, 4,	1, 5, 4,
		0, 2, 4,	2, 6, 4,
		0, 2, 1,	1, 3, 2,
		1, 3, 7,	1, 7, 5,
		4, 6, 5,	5, 6, 7,
		2, 3, 6,	3, 7, 6
	};

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);

	Mesh mesh(vertices, 8 * 6 * sizeof(float), layout, indices, 12);

	Mesh mesh(vb, ib, va);

	Shader shader("res/shaders/Camera.shader"); 

	shader.SetUniform4f("cameraPosition", 0.f, 0.f, 5.f, 0.f);
	shader.SetUniform4f("cameraRotation", 0.f, 0.f, 1.f, 0.f);
	shader.SetUniform4f("displaySurfacePosition", 0.f, 0.f, 1.f, 0.f);

	
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(renderer.GetWindow())) {
		/* Render here */
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.Bind();

		shader.SetUniform4f("cameraPosition", 5.f, 0.f, 0.f, 0.f);
		shader.SetUniform4f("cameraRotation", 0.f, 0.f, 0.f, 0.f);
		shader.SetUniform4f("displaySurfacePosition", 1.f, 0.f, 0.f, 0.f);

		mesh.Bind();

		GLCall(glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, nullptr));

		/* Swap front and back buffers */
		glfwSwapBuffers(renderer.GetWindow());

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}
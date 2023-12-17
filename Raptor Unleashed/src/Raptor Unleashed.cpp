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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

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
	//glClearColor(.8, 0, .8, 1);
	
	// x, y, z, r, g, b
	float vertices[] = {
		0, 0, 0,	1, 0, 1,
		0, 1, 0,	1, 1, 1,
		1, 1, 0,	1, 1, 1,
		1, 0, 0,	1, 1, 1,
		0, 0, 1,	1, 1, 1,
		0, 1, 1,	1, 1, 1,
		1, 1, 1,	1, 1, 1,
		1, 0, 1,	1, 1, 1
	};

	unsigned int indices[] = {
		0, 3, 1,	3, 2, 1,
		0, 1, 4,	4, 1, 5,
		4, 3, 0,	3, 4, 7,
		2, 3, 7,	7, 6, 2,
		4, 5, 7,	7, 5, 6,
		1, 2, 5,	2, 6, 5
	};

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);

	Mesh mesh(vertices, 8 * 6 * sizeof(float), layout, indices, 12*3);

	Shader shader("res/shaders/Camera.shader"); 

	glm::mat4 proj = glm::perspective(45.0f, 4.0f / 3.0f, .1f, 30.0f);
	glm::mat4 view = glm::lookAt(
		glm::vec3(3, 3, 3), // camera position
		glm::vec3(0, 0, 0), // camera target
		glm::vec3(0, 1, 0)  // up direction
	);
	glm::mat4 mvp = proj * view;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(renderer.GetWindow())) {
		/* Render here */
		GLCall(glClear(GL_COLOR_BUFFER_BIT));

		shader.Bind();
		shader.SetUniformMat4f("u_MVP", mvp);

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
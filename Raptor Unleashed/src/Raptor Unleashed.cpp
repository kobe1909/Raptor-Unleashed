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

#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

#include "Scene.h"

#include <tuple>

int main(void) {
	Renderer renderer;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	glm::vec2 windowSize(960, 720);
	renderer.CreateWindow(windowSize.x, windowSize.y, "Raptor Unleashed");

	// Limit the framerate to the vsync
	glfwSwapInterval(1);

	if (glewInit() != GLEW_OK)
		std::cout << "Error" << std::endl;

	std::cout << glGetString(GL_VERSION) << std::endl;

	// Sets the background color (values are normalized)
	//glClearColor(.8, 0, .8, 1);

	//GLCall(glEnable(GL_CULL_FACE));
	//GLCall(glCullFace(GL_FRONT));
	GLCall(glEnable(GL_DEPTH_TEST));
	
	float vertices[] = {
		// positions          // normals           // texture coords
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
		 0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,

		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,  0.0f,  0.0f, 1.0f,   0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f
	};

	unsigned int indices[] = {
		0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35
	};

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(3);
	layout.Push<float>(2);

	Mesh mesh(vertices, 36 * 6 * sizeof(float), layout, indices, 12*3);

	Shader shader("res/shaders/Camera.shader"); 

	shader.Bind();
	shader.SetUniform3f("material.ambient", 0.135f, 0.2225f, 0.2225f);
	shader.SetUniform3f("material.diffuse", 0.54f, 0.89f, 0.63f);
	shader.SetUniform3f("material.specular", 0.316228f, 0.316228f, 0.316228f);
	shader.SetUniform1f("material.shininess", 32.0f);
	shader.SetUniform3f("light.position", 1.2f, 1.0f, 2.0f);
	shader.SetUniform3f("light.ambient", 0.4f, 0.4f, 0.4f);
	shader.SetUniform3f("light.diffuse", 0.6f, 0.6f, 0.6f);
	shader.SetUniform3f("light.specular", 1.0f, 1.0f, 1.0f);
	//shader.SetUniform3f("objectColor", 1.0f, 0.25f, 0.8f);
	shader.SetUniform3f("cameraPos", 2.0f, 2.0f, 2.0f);

	glm::mat4 proj = glm::perspective(45.0f, windowSize.x / windowSize.y, .01f, 50.0f);
	glm::mat4 view = glm::lookAt(
		glm::vec3(2.0f, 2.0f, 2.0f), // camera position
		glm::vec3(0.0f, 0.0f, 0.0f), // camera target
		glm::vec3(0.0f, 1.0f, 0.0f)  // up direction
	);

	float angle = 0.0f;

	double lastTime = 0.0;

	Scene scene;

	scene.Awake();
	scene.Start();

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(renderer.GetWindow())) {
		double deltaTime = lastTime - glfwGetTime();
		lastTime = glfwGetTime();

		/* Render here */
		GLCall(glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT));

		shader.Bind();
		glm::mat4 model = glm::rotate(glm::mat4(1.0f), glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));
		shader.SetUniformMat4f("Model", model);
		shader.SetUniformMat4f("View", view);
		shader.SetUniformMat4f("Proj", proj);

		angle -= 20.0f * deltaTime;
		if (angle > -360.0f)
			angle += 360.0f;

		scene.Update();
		scene.Draw();
 
		mesh.Bind();

		GLCall(glDrawElements(GL_TRIANGLES, mesh.GetTriangleCount(), GL_UNSIGNED_INT, nullptr));

		/* Swap front and back buffers */
		glfwSwapBuffers(renderer.GetWindow());

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
	scene.Destroy();
	return 0;
}
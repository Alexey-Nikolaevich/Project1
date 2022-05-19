#include "Application.h"

const int width = 900;
const int height = 900;
const std::string title = "Project1";


Application::Application()
{
	iwindow.Initialize(width, height, title);
	mesh.Initialize();
}

Application::~Application()
{

}


void Application::Run()
{

	while (!glfwWindowShouldClose(iwindow.window))
	{
		glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(mesh.shaderProgram);
		glBindVertexArray(mesh.VAO);
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);

		glfwSwapBuffers(iwindow.window);
		glfwPollEvents();
	}
}
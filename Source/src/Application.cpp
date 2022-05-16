#include "Application.h"

const int width = 900;
const int height = 900;
const std::string title = "Project1";


Application::Application()
{
	iwindow.Initialize(width, height, title);
}

Application::~Application()
{

}


void Application::Run()
{
	while (!glfwWindowShouldClose(iwindow.window))
	{
		glClearColor(0.1f, 0.2f, 0.2f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(iwindow.window);
		glfwPollEvents();
	}
}
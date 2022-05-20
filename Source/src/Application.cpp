#include "Application.h"


#include <string>
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
	//============FPS============//
	double crntTime = 0.0;
	double prevTime = 0.0;
	int c = 0;
	std::string title;
	//===========================//

	while (!glfwWindowShouldClose(iwindow.window))
	{
		glClearColor(0.2f, 0.1f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		mesh.Draw();

		//===============================FPS=============================//
		crntTime = glfwGetTime();
		c++;
		if (crntTime - prevTime >= 1.0 / 20.0)
		{
			title = "FPS: " + std::to_string(c / (crntTime - prevTime));
			glfwSetWindowTitle(iwindow.window, title.c_str());
			prevTime = crntTime;
			c = 0;
		}
		//===============================================================//

		glfwSwapBuffers(iwindow.window);
		glfwPollEvents();
	}
}
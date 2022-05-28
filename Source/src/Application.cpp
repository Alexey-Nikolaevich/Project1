#include "Application.h"


#include <string>
const int width = 1000;
const int height = 700;
const std::string title = "Project1";


Application::Application()
{
	iwindow.Initialize(width, height, title);
	mesh.Initialize();
}

void Application::Run()
{
	//============FPS============//
	double crntTime = 0.0;
	double prevTime = 0.0;
	int c = 0;
	std::string title;
	//===========================//

	GLFWwindow* window = iwindow.getWindow();

	float rotation = 0.0f; //rotation

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(0.10f, 0.03f, 0.19f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		mesh.shader.Use();

		//==================================Camera========================================//
		glm::mat4 model = glm::mat4(1.0f);
		glm::mat4 view = glm::mat4(1.0f);
		glm::mat4 proj = glm::mat4(1.0f);

		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, -0.5f, -2.0f));
		proj = glm::perspective(glm::radians(45.0f), (float)width / height, 0.1f, 100.0f);

		int modelLoc = glGetUniformLocation(mesh.shader.shaderProgram, "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		int viewLoc = glGetUniformLocation(mesh.shader.shaderProgram, "view");
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		int projLoc = glGetUniformLocation(mesh.shader.shaderProgram, "proj");
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(proj));
		//================================================================================//

		//===============================FPS=============================//
		crntTime = glfwGetTime();
		c++;
		if (crntTime - prevTime >= 1.0 / 60.0)
		{
			title = "FPS: " + std::to_string(c / (crntTime - prevTime));
			glfwSetWindowTitle(window, title.c_str());
			prevTime = crntTime;
			c = 0;
			rotation += 2.0f; //rotation
		}
		//===============================================================//

		mesh.Draw();

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
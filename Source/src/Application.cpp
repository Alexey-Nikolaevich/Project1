#include "Application.h"


#include <string>
//============================Config===============================//
//Window:
int WIDTH = 1200;
int HEIGHT = 800;
std::string TITLE = "Project1";

//Camera:
glm::vec3 CAMERA_START_POS = glm::vec3(0.0f, 0.0f, 2.0f);
glm::vec3 CAMERA_START_ORIENTATION = glm::vec3(0.0f, 0.0f, -1.0f);
float NEAR_RENDER_DISTANCE = 0.1f;
float FAR_RENDER_DISTANCE = 50.0f;
float FIELD_OF_VIEW = 45.0f;

//BackGroundColor:
GLfloat CLEARCOLOR[]{ 0.10f, 0.03f, 0.19f, 1.0f };
//=================================================================//


Application::Application()
{
	iwindow.Initialize(WIDTH, HEIGHT, TITLE);
	meshShader.Initialize();
	mesh.Initialize();
	camera.Initialize(WIDTH, HEIGHT, CAMERA_START_POS, CAMERA_START_ORIENTATION, NEAR_RENDER_DISTANCE, FAR_RENDER_DISTANCE, FIELD_OF_VIEW);
}

void Application::Run()
{
	GLFWwindow* window = iwindow.getWindow();

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(CLEARCOLOR[0], CLEARCOLOR[1], CLEARCOLOR[2], CLEARCOLOR[3]);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSetWindowTitle(window, iwindow.FPS().c_str()); // FPS

		mesh.Draw(meshShader, camera); //(shader, camera)

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
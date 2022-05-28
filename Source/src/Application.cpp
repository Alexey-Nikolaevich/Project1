#include "Application.h"


//============================Config===============================//
//Window:
int WIDTH = 1200;
int HEIGHT = 800;
std::string TITLE = "Project1";
int OPENGL_VERSION = 3;
float SWAP_INTERAVL = 1.0f;

//Camera:
glm::vec3 CAMERA_START_POSITION = glm::vec3(0.0f, 0.0f, 2.0f);
glm::vec3 CAMERA_START_ORIENTATION = glm::vec3(0.0f, 0.0f, -1.0f);
float NEAR_RENDER_DISTANCE = 0.1f;
float FAR_RENDER_DISTANCE = 50.0f;
float FIELD_OF_VIEW = 45.0f;

//Shader
std::string MESH_DEFAULT_VERT_FILE = "Source/Shaders/Mesh_default.vert";
std::string MESH_DEFAULT_FRAG_FILE = "Source/Shaders/Mesh_default.frag";

//BackGroundColor:
GLfloat CLEARCOLOR[]{0.08f, 0.03f, 0.1f, 1.0f};
//=================================================================//


Application::Application()
{
	iwindow.Initialize(WIDTH, HEIGHT, TITLE, OPENGL_VERSION, SWAP_INTERAVL);
	meshShader.Initialize(MESH_DEFAULT_VERT_FILE, MESH_DEFAULT_FRAG_FILE);
	mesh.Initialize();
	camera.Initialize(WIDTH, HEIGHT, CAMERA_START_POSITION, CAMERA_START_ORIENTATION, NEAR_RENDER_DISTANCE, FAR_RENDER_DISTANCE, FIELD_OF_VIEW);
}

void Application::Run()
{
	GLFWwindow* window = iwindow.getWindow();

	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(CLEARCOLOR[0], CLEARCOLOR[1], CLEARCOLOR[2], CLEARCOLOR[3]);
		glClear(GL_COLOR_BUFFER_BIT);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSetWindowTitle(window, iwindow.Info(camera.GetPosition()).c_str()); 

		camera.Controls(window);

		mesh.Draw(meshShader, camera); 

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}
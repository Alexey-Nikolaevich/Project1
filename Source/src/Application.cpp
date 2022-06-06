#include "Application.h"


//============================Config===============================//
//Window:
int WIDTH = 1200;
int HEIGHT = 800;
std::string TITLE = "Project1";
int OPENGL_VERSION = 3;
float SWAP_INTERAVL = 1.0f;

//Camera:
glm::vec3 CAMERA_START_POSITION = glm::vec3(18.0f, 12.0f, 18.0f);
glm::vec3 CAMERA_START_ORIENTATION = glm::vec3(-1.0f, -0.8f, -1.0f);
float NEAR_RENDER_DISTANCE = 2.0f;
float FAR_RENDER_DISTANCE = 50.0f;
float FIELD_OF_VIEW = 45.0f;
float CAMERA_SPEED = 0.05f;
float MOUSE_SENSITIVITY = 50.0f;

//Shader:
std::string MESH_DEFAULT_VERT_FILE =	"Source/Shaders/Mesh_default.vert";
std::string MESH_DEFAULT_FRAG_FILE =	"Source/Shaders/Mesh_default.frag";
std::string SIMPLE_COLOR_FRAG_FILE =	"Source/Shaders/Simple_Color.frag";
std::string ARROW_FILE =				"Source/Shaders/Arrow.frag";

//Function:
float SCALE = 10;
float RESOLUTION = 300;
glm::vec4 BOUNDARIES = glm::vec4(-10.0f, 10.0f, -10.0f, 10.0f); // (x1;x2 : y1;y2)

//BackGroundColor:
GLfloat CLEARCOLOR[]{0.15f, 0.15f, 0.15f, 1.0f};
//=================================================================//


Application::Application()
{
	iwindow.Initialize(WIDTH, HEIGHT, TITLE, OPENGL_VERSION, SWAP_INTERAVL);

	planeShader.Initialize(MESH_DEFAULT_VERT_FILE, MESH_DEFAULT_FRAG_FILE);
	netShader.Initialize(MESH_DEFAULT_VERT_FILE, SIMPLE_COLOR_FRAG_FILE);
	arrowShader.Initialize(MESH_DEFAULT_VERT_FILE, ARROW_FILE);

	camera.Initialize(WIDTH, HEIGHT, CAMERA_START_POSITION, CAMERA_START_ORIENTATION, NEAR_RENDER_DISTANCE, FAR_RENDER_DISTANCE, FIELD_OF_VIEW, CAMERA_SPEED, MOUSE_SENSITIVITY);

	graph.Initialize(iwindow.getWindow(), SCALE, RESOLUTION, BOUNDARIES);
}

void Application::Run()
{
	GLFWwindow* window = iwindow.getWindow();

	glEnable(GL_DEPTH_TEST);

	//TODO: Move this block from here

	int i = 0;

	while (!glfwWindowShouldClose(window))
	{
		glClearColor(CLEARCOLOR[0], CLEARCOLOR[1], CLEARCOLOR[2], CLEARCOLOR[3]);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glfwSetWindowTitle(window, iwindow.Info(camera.GetPosition()).c_str()); 

		camera.Controls(window);

		graph.Draw(planeShader, netShader, camera);

		//TODO: Move this block from here
		if (i < 1000)
		{
			balls.push_back(Ball(SCALE, BOUNDARIES));
			i++;
		}

		for (int i = 0; i < balls.size(); i++)
		{
			balls[i].Move();
		}
		i++;
		
		
		for (int z = 0; z < balls.size(); z++)
		{
			balls[z].Draw(arrowShader, camera);
		}
		i++;
		//==========

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
 }
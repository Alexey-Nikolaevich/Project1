#include "IWindow.h"

IWindow::~IWindow()
{
	// Delete window if IWindow is destroying 
	// Terminate GLFW if IWindow is destroying
	glfwDestroyWindow(window);
	glfwTerminate();
}



void IWindow::Initialize(const int width, const int height, const std::string title, int version, float interval)
{
	// Initialize GLFW
	glfwInit();

	// Tell OpenGL what version we are using
	// We are usign OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, version);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, version);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	// Make window
	// Make window current context
	window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
	glfwMakeContextCurrent(window);

	// Load GLAD
	gladLoadGL();

	// Specify the viewport of OpenGL in the Window
	glViewport(0, 0, width, height);

	// Interval of buffer swaping
	glfwSwapInterval(interval);
}

std::string IWindow::Info(glm::vec3 camPosition)
{
	crntTime = glfwGetTime();
	c++;
	if (crntTime - prevTime >= 1.0 / 20.0)
	{
		FPS = "FPS: " + std::to_string(c / (crntTime - prevTime));
		Position = "Position: (" + std::to_string(camPosition.x) + "; " + std::to_string(camPosition.y) + "; " + std::to_string(camPosition.z) + ")";
		title =  FPS + "|---------|" + Position;
		prevTime = crntTime;
		c = 0;
	}
	return title;
}
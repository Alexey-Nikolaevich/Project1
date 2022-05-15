#include "IWindow.h"

IWindow::IWindow(const int width, const int height, std::string title)
{
	// Initialize GLFW
	glfwInit();

	// Tell OpenGL what version we are using
	// We are usign OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
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
	glfwSwapInterval(0.75f);
}

IWindow::~IWindow()
{
	// Delete window if IWindow is destroying 
	// Terminate GLFW if IWindow is destroying
	glfwDestroyWindow(window);
	glfwTerminate();
}
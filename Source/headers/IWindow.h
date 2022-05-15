//----------------------------------------------------
//	DESCRIPTION: Initializes GLFW and Window, makes Window
//	current context
//----------------------------------------------------

#ifndef IWINDOW_H
#define IWINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class IWindow
{
public:

	GLFWwindow* window;

	IWindow(const int width, const int height, std::string title);
	~IWindow();
};

#endif IWINDOW_H

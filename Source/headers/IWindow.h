//---------------------------------------------------------
//	DESCRIPTION: Initializes GLFW and Window, makes Window
//	current context
//---------------------------------------------------------

#ifndef IWINDOW_H
#define IWINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class IWindow
{
public:

	GLFWwindow* window;

	IWindow();
	~IWindow();

	void Initialize(const int width, const int height, const std::string title);
};

#endif IWINDOW_H

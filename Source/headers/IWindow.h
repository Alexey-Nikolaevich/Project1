//---------------------------------------------------------
//	DESCRIPTION: Initializes GLFW and Window, makes Window
//	current context
//---------------------------------------------------------

#ifndef IWINDOW_H
#define IWINDOW_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string>

class IWindow
{
public:
	IWindow();
	~IWindow();
	void Initialize(const int width, const int height, const std::string title, int version, float interval);

	GLFWwindow* getWindow()
	{
		return window;
	}

	std::string FPS();

private:
	GLFWwindow* window;

	//============FPS============//
	double crntTime = 0.0;
	double prevTime = 0.0;
	int c = 0;
	std::string title;
	//===========================//
};

#endif IWINDOW_H

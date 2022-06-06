//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H


#include "IWindow.h"
#include "Shader.h"
#include "Camera.h"
#include "Graph.h"
#include "Gradient_descent.h"

class Application
{
public:
	Application();

	void Run();

private:
	IWindow iwindow;

	Shader planeShader;
	Shader netShader;
	Shader arrowShader;

	Camera camera;

	Graph graph;

	Gradient_descent gradient_descent;
};

#endif


//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H


#include "IWindow.h"
#include "Shader.h"
#include "Camera.h"
#include "Graph.h"
#include "GradientDescent.h"

class Application
{
public:
	Application();
	~Application();

	void Run();

	void WelcomeInfo();

private:
	IWindow iwindow;

	Shader planeShader;
	Shader netShader;
	Shader arrowShader;

	Camera camera;

	Graph graph;

	GradientDescent gradientDescent;
};

#endif


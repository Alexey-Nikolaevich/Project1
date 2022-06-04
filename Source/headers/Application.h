//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H


#include "IWindow.h"
#include "Shader.h"
#include "Camera.h"
#include "Graph.h"
#include "Ball.h"

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

	std::vector<Ball> balls;
};

#endif


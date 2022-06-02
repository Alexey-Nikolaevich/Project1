//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H


#include "IWindow.h"
#include "Shader.h"
#include "Camera.h"
#include "Graph.h"

class Application
{
public:
	Application();

	void Run();

private:
	Graph graph;

	IWindow iwindow;

	Shader planeShader;
	Shader netShader;

	Camera camera;
};

#endif


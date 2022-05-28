//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H

#include "IWindow.h"
#include "Shader.h"
#include "Function.h"
#include "Mesh.h"
#include "Camera.h"


class Application
{
public:
	Application();

	void Run();

private:
	IWindow iwindow;
	Shader meshShader;
	Function function;
	Mesh mesh;
	Camera camera;
};
#endif


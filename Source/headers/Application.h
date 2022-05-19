//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H

#include "IWindow.h"
#include "Mesh.h"

class Application
{
public:

	IWindow iwindow;
	Mesh mesh;

	Application();
	~Application();

	void Run();
};
#endif


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
	Application();

	void Run();

private:
	IWindow iwindow;
	Mesh mesh;
};
#endif


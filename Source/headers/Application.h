//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H

#include "IWindow.h"

class Application
{
public:

	IWindow iwindow;
	//Camera camera;
	//Inputs inputs;
	//UI ui;
	//

	Application();
	~Application();

	void Run();
};
#endif


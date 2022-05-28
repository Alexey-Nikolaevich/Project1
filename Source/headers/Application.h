//---------------------------------------------------------
//	DESCRIPTION: Compiles whole application
//---------------------------------------------------------

#ifndef APPLICATION_H
#define APPLICATION_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "IWindow.h"
#include "Shader.h"
#include "Mesh.h"

class Application
{
public:
	Application();

	void Run();

private:
	IWindow iwindow;
	Shader meshShader;
	Mesh mesh;
};
#endif


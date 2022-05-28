//---------------------------------------------------------
//	DESCRIPTION: Creates tringle and shaderProgram(for now)
//---------------------------------------------------------

#ifndef MESH_H
#define MESH_H

#include "IWindow.h"
#include "Shader.h"

class Mesh
{
public:
	Mesh();
	void Initialize(Shader *meshShader);

	void Draw();

private:
	GLuint VAO, VBO, EBO;
	Shader meshShader;
};

#endif

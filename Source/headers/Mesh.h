#ifndef MESH_H
#define MESH_H

#include "IWindow.h"

class Mesh
{
public:
	GLuint VAO, VBO, EBO;
	GLuint shaderProgram;

	Mesh();
	~Mesh();

	void Initialize();

};

#endif

//---------------------------------------------------------
//	DESCRIPTION: Creates tringle and shaderProgram(for now)
//---------------------------------------------------------

#ifndef MESH_H
#define MESH_H

#include "Shader.h"
#include "Camera.h"

class Mesh
{
public:
	Mesh();
	void Initialize();

	void Draw(Shader& meshShader, Camera& camera);

private:
	GLuint VAO, VBO, EBO;
};

#endif
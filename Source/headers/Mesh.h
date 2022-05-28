//---------------------------------------------------------
//	DESCRIPTION: Creates tringle and shaderProgram(for now)
//---------------------------------------------------------

#ifndef MESH_H
#define MESH_H

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<glm/gtc/type_ptr.hpp>

#include "IWindow.h"
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

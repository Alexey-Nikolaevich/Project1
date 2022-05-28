//---------------------------------------------------------
//	DESCRIPTION: Creates tringle and shaderProgram(for now)
//---------------------------------------------------------

#ifndef MESH_H
#define MESH_H

#include "Shader.h"
#include <vector>
#include <glm/glm.hpp>
#include "Camera.h"

class Mesh
{
public:
	Mesh();
	void Initialize(std::vector<glm::vec3>& vertices, std::vector<GLuint>& indices);

	void Draw(Shader& meshShader, Camera& camera);

private:
	GLuint VAO, VBO, EBO;
};

#endif
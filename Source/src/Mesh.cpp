#include "Mesh.h"


Mesh::Mesh()
{

}

void Mesh::Initialize()
{
	GLfloat vertices[] =
	{
		-0.3f,  0.0f,  0.0f, //Front left	0
		 0.3f,  0.0f,  0.0f, //Front right	1 
		-0.3f,  0.6f, -0.0f, //Back left	2
		 0.3f,  0.6f, -0.0f, //Back right	3
	};

	GLuint indices[] =
	{
		0, 1, 2,
		//2, 3, 1
	};

	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	glBindVertexArray(VAO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::Draw(Shader& meshShader, Camera& camera)
{
	meshShader.Use();
	camera.UniformMatrix(meshShader.GetShaderProgram(), "camMatrix");

	glBindVertexArray(VAO);
	glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0); //TODO: fix "9"
}




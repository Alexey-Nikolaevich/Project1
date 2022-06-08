//--------------------------------------------------------------
//	DESCRIPTION: Visualize gradient descent
//--------------------------------------------------------------

#ifndef ARROW_H
#define ARROW_H

#include "Mesh.h"
#include "Function.h"

class Arrow
{
public:
	Arrow(float scale, glm::vec4 boundaries, float min_grad_vector, float arrow_step, int numberOfIterations);

	~Arrow();
	void Delete();

	void Draw(Shader& meshShader, Camera& camera);

	void Move();

private:
	float scale;
	glm::vec4 boundaries;

	float min_grad_vector;
	float arrow_step;
	int numberOfIterations;

	std::vector<glm::vec3> vertices;
	std::vector<GLuint> indices;

	Mesh mesh; 

	glm::vec2 position;

	float x;
	float y;
	float z;

	int iteration = 0;
};

#endif
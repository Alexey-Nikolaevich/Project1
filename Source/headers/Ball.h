//--------------------------------------------------------------
//	DESCRIPTION: Visualize gradient descent
//--------------------------------------------------------------

#ifndef BALL_H
#define BALL_H

#include "Mesh.h"
#include "Function.h"

class Ball
{
public:
	Ball(float scale, glm::vec4 boundaries);

	void Draw(Shader& meshShader, Camera& camera);

	void Move();

private:
	float scale;
	float resolution;
	glm::vec4 boundaries;

	std::vector<glm::vec3> vertices;
	std::vector<GLuint> indices;

	Mesh sphere; //TODO: Its not a sphere

	glm::vec2 position;

	float x;
	float y;
	float z;
};

#endif
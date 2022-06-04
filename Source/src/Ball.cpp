#include "Ball.h"

Ball::Ball(float scale, glm::vec4 boundaries)
{
	Ball::scale = scale;
	Ball::boundaries = boundaries;

	position = glm::vec2(-10 + std::rand() % 20,-10 + std::rand() % 20); //TODO: Fix generation
	
	//TODO: Fix scaling
	float x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
	float z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
	float y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
	
	vertices =
	{ 
		glm::vec3(-0.1f + x, y,  0.1f + z), //Buttom Front left  0
		glm::vec3(0.1f + x , y,  0.1f + z),  //Buttom Front right 1
		glm::vec3(-0.1f + x,  y, -0.1f + z), //Buttom Back left   2
		glm::vec3(0.1f + x, y, -0.1f + z),  //Buttom Back right  3
	};

	indices =
	{
		0, 1, 2, 
		2, 3, 1
	};

	sphere.Initialize(vertices, indices);
}

void Ball::Draw(Shader& meshShader, Camera& camera)
{
	sphere.DrawTriangle(meshShader, camera, vertices);
}

void Ball::Move()
{
	//TODO: Fix this somehow
	int i = 0;
	if (abs(DescentVector(position[0], position[1])[0]) + abs(DescentVector(position[0], position[1])[1]) > 0.01f && i < 10)
	{
		position += DescentVector(position[0], position[1]);

		float x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
		float z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
		float y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));

		vertices =
		{  
			glm::vec3(-0.1f + x, y,  0.1f + z), //Buttom Front left  0
			glm::vec3(0.1f + x , y,  0.1f + z),  //Buttom Front right 1
			glm::vec3(-0.1f + x,  y, -0.1f + z), //Buttom Back left   2
			glm::vec3(0.1f + x, y, -0.1f + z),  //Buttom Back right  3
		};
		i++;
	}
}
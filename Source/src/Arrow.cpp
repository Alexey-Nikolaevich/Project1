#include "Arrow.h"

Arrow::Arrow(float scale, glm::vec4 boundaries, float min_grad_vector, float arrow_step, int numberOfIterations)
{
	//===============================//
	//std::cout << "Arrow constructed\n";
	//===============================//

	Arrow::scale = scale;
	Arrow::boundaries = boundaries;
	Arrow::min_grad_vector = min_grad_vector;
	Arrow::arrow_step = arrow_step;
	Arrow::numberOfIterations = numberOfIterations;

	position = glm::vec2(-scale + std::rand() % (int)(scale * 2), -scale + std::rand() % (int)(scale * 2)); //TODO: Fix generation
	
	//TODO: Fix scaling
	float x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
	float z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
	float y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
	
	vertices =
	{ 
	};

	indices =
	{
		0, 1, 2,
		3, 2, 1,

		4, 5, 6,
		7, 6, 5,

		0, 1, 4,
		4, 5, 1,
		5, 1, 2,
		5, 6, 2,
		2, 3, 6,
		6, 7, 3,
		3, 0, 7,
		4, 7, 0
	};


	mesh.Initialize(vertices, indices);
}

Arrow::~Arrow()
{
	//===============================//
	//std::cout << "Arrow destructed\n";
	//===============================//
}


void Arrow::Draw(Shader& meshShader, Camera& camera)
{
	mesh.DrawTriangle(meshShader, camera, vertices);

}

void Arrow::Move()
{
	if ((iteration > numberOfIterations))
	{
		return;
	}
	if (glm::length(DescentVector(position[0], position[1])) < 0.0005f)
	{
		return;
	}

	position += glm::normalize(DescentVector(position[0], position[1])) * arrow_step;

	x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
	z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
	y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));

	vertices =
	{
		glm::vec3(-0.1f + x, y,  0.1f + z), //Buttom Front left  0
		glm::vec3(0.1f + x , y,  0.1f + z),  //Buttom Front right 1
		glm::vec3(-0.1f + x,  y, -0.1f + z), //Buttom Back left   2
		glm::vec3(0.1f + x, y, -0.1f + z),  //Buttom Back right  3

		glm::vec3(-0.1f + x, 0.2 + y,  0.1f + z), //Buttom Front left  4
		glm::vec3(0.1f + x , 0.2 + y,  0.1f + z),  //Buttom Front right 5
		glm::vec3(-0.1f + x, 0.2 + y, -0.1f + z), //Buttom Back left   6
		glm::vec3(0.1f + x, 0.2 + y, -0.1f + z),  //Buttom Back right  7
	};

	iteration++;
}

float Arrow::GetHeight()
{
	y = round(Function(round(ToGraphScale_X(x) * 1000) / 1000, round(ToGraphScale_Z(z) * 1000) / 1000) * 1000) / 1000;
	//return (y - abs(boundaries[1])) * abs(boundaries[0]) / scale;
	return y;
}

#include "Arrow.h"

Arrow::Arrow(float scale, glm::vec4 boundaries, float min_grad_vector, float arrow_step, int numberOfIterations)
{
	Arrow::scale = scale;
	Arrow::boundaries = boundaries;
	Arrow::min_grad_vector = min_grad_vector;
	Arrow::arrow_step = arrow_step;
	Arrow::numberOfIterations = numberOfIterations;

	float scal = 12;
	position = glm::vec2((-scal + std::rand() % (int)(scal * 2))/1, (-scal + std::rand() % (int)(scal * 2)) / 1);
	
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
	mesh.~Mesh();
	vertices.clear();
	indices.clear();
	vertices.shrink_to_fit();
	indices.shrink_to_fit();
}


void Arrow::Draw(Shader& meshShader, Camera& camera)
{
	mesh.DrawTriangle(meshShader, camera, vertices);
}

void Arrow::Move()
{
	FillVertices(x, y, z);
	if ((iteration > numberOfIterations))
	{
		return;
	}
	if (glm::length(DescentVector(position[0], position[1])) < 0.0005f)
	{
		return;
	}

	float crntTime = glfwGetTime();
	if (crntTime - prevTime >= 1.0f / 2.0f)
	{
		deltaTime = crntTime - prevTime;
		prevTime = crntTime;
		if (deltaTime > 1.0f / 2.0f)
		{
			deltaTime = 1.0f / 2.0f;
		}
	}

	Aciliration = DescentVector(position[0], position[1]);
	if (glm::length(Aciliration) > 0.2f)
	{
		Aciliration = glm::normalize(Aciliration);
		Aciliration[0] = Aciliration[0] * 0.2f;
		Aciliration[1] = Aciliration[1] * 0.2f;
	}

	Velocity = Aciliration * deltaTime;
	position = position + Velocity * deltaTime + Aciliration * deltaTime * deltaTime / 2.0f;

	x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
	z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
	y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));

	FillVertices(x, y, z);

	iteration++;
}

void Arrow::FillVertices(float x, float y, float z)
{
	vertices =
	{
		glm::vec3(-0.1f + x, y,  0.1f + z), //Buttom Front left  0
		glm::vec3(0.1f + x , y,  0.1f + z),  //Buttom Front right 1
		glm::vec3(-0.1f + x,  y, -0.1f + z), //Buttom Back left   2
		glm::vec3(0.1f + x, y, -0.1f + z),  //Buttom Back right  3

		glm::vec3(-0.1f + x, 0.2 + y,  0.1f + z), //Up Front left  4
		glm::vec3(0.1f + x , 0.2 + y,  0.1f + z),  //Up Front right 5
		glm::vec3(-0.1f + x, 0.2 + y, -0.1f + z), //Up Back left   6
		glm::vec3(0.1f + x, 0.2 + y, -0.1f + z),  //Up Back right  7
	};
}

glm::vec2 Arrow::GetPosition()
{
	return position;
}

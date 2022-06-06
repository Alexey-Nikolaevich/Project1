#include "Gradient_descent.h"

void Gradient_descent::Initialize(float& scale, glm::vec4& boundaries, int& numberOfArrows, int& numberOfIterations)
{
	Gradient_descent::scale = scale;
	Gradient_descent::boundaries = boundaries;
	Gradient_descent::numberOfArrows = numberOfArrows;
	Gradient_descent::numberOfIterations = numberOfIterations;
}

//void Gradient_descent::GenerateArrow()
//{
//	for (int i = 0; i < numberOfArrows; i++)
//	{
//		arrows.push_back(Arrow(scale, boundaries));
//	}
//}
//
//void Gradient_descent::Draw(Shader& meshShader, Camera& camera)
//{
//	for (int i = 0; i < arrows.size(); i++)
//	{
//		arrows[i].Draw(meshShader, camera);
//	}
//}


//
////=========================================ARROW========================================//
//Arrow::Arrow(float& scale, glm::vec4& boundaries)
//{
//	position = glm::vec2(-10 + std::rand() % 20, -10 + std::rand() % 20); //TODO: Fix generation
//
//	//TODO: Fix scaling
//	float x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
//	float z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
//	float y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
//
//	vertices =
//	{
//		glm::vec3(-0.1f + x, y,  0.1f + z), //Buttom Front left  0
//		glm::vec3(0.1f + x , y,  0.1f + z),  //Buttom Front right 1
//		glm::vec3(-0.1f + x,  y, -0.1f + z), //Buttom Back left   2
//		glm::vec3(0.1f + x, y, -0.1f + z),  //Buttom Back right  3
//	};
//
//	indices =
//	{
//		0, 1, 2,
//		2, 3, 1
//	};
//
//	mesh.Initialize(vertices, indices);
//}
//
//void Arrow::Draw(Shader& meshShader, Camera& camera)
//{
//	mesh.DrawTriangle(meshShader, camera, vertices);
//}
//
//void Arrow::Move()
//{
//	//TODO: Fix this somehow
//	if (abs(DescentVector(position[0], position[1])[0]) + abs(DescentVector(position[0], position[1])[1]) > 0.001f)
//	{	
//		position += glm::normalize(DescentVector(position[0], position[1])) * 0.03f;
//
//		x = (position[0] - boundaries[0]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
//		z = (position[1] - boundaries[2]) * scale / (abs(boundaries[2]) + abs(boundaries[3]));
//		y = Function(position[0], position[1]) * scale / (abs(boundaries[0]) + abs(boundaries[1]));
//
//		vertices =
//		{  
//			glm::vec3(-0.1f + x, y,  0.1f + z), //Buttom Front left  0
//			glm::vec3(0.1f + x , y,  0.1f + z),  //Buttom Front right 1
//			glm::vec3(-0.1f + x,  y, -0.1f + z), //Buttom Back left   2
//			glm::vec3(0.1f + x, y, -0.1f + z),  //Buttom Back right  3
//		};
//	}
//}
//
////======================================================================================//
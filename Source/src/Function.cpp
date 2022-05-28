#include "Function.h"

Function::Function()
{

}

void Function::Initialize(int scale)
{
	Function::scale = scale;
}

std::vector<glm::vec3>& Function::GetVertices()
{
	float y;
	int i = 0;

	for (float z = 0; z < scale; z++)
	{
		for (float x = 0; x < scale; x++)
		{
			y = (sin(x/10) + cos(z/10))*5; //TODO: should be inputable
			vertices.push_back(glm::vec3(x, y, z));
			i++;
		}
	}
	return vertices;
}


std::vector<GLuint>& Function::GetIndices()
{
	for (int z = 0; z < scale * (scale - 1);)
	{
		for (int x = 0; x < scale - 1; x++)
		{
			indices.push_back(x + z);
			indices.push_back(x + z + 1);
			indices.push_back(x + z + scale);
			indices.push_back(x + z + 1);
			indices.push_back(x + z + scale);
			indices.push_back(x + z + scale + 1);
		}
		z += scale;
	}
	return indices;
}
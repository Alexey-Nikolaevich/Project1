#include "Function.h"

///
/// TODO: fix entire function Class, I dont like it
/// 

Function::Function()
{

}

void Function::Initialize(float scale, float resolution, glm::vec4 boundaries)
{
	Function::scale = scale;
	Function::resolution = resolution;
	Function::boundaries = boundaries;
}

std::vector<glm::vec3>& Function::GetVertices()
{
	//TODO: make it scalable
	float y;
	int i = 0;
	float step = 1.0f / resolution * scale;

	for (float z = -scale/2; z < scale/2; z+= step)
	{
		for (float x = -scale/2; x < scale/2; x+= step)
		{
			y = (0.05*sin(5*x*log10(z)) + 2*sin(0.5 * z* log10(x))) + cos(0.9*z); //TODO: should be inputable
			vertices.push_back(glm::vec3(x, y, z));
			i++;
		}
	}
	return vertices;
}

//TODO: add indices for triangles, and lines
std::vector<GLuint>& Function::GetIndices()
{
	float step = resolution;

	for (int z = 0; z < step * (step - 1);)
	{
		for (int x = 0; x < step - 1; x++)
		{
			/*indices.push_back(x + z);
			indices.push_back(x + z + 1);
			indices.push_back(x + z + scale);
			indices.push_back(x + z + 1);
			indices.push_back(x + z + scale);
			indices.push_back(x + z + scale + 1);*/

			indices.push_back(x + z);
			indices.push_back(x + z + 1);

			indices.push_back(x + z + step);
			indices.push_back(x + z + 1);

			indices.push_back(x + z);
			indices.push_back(x + z + step);
			//===================================//
			indices.push_back(x + z + step);
			indices.push_back(x + z + 1);

			indices.push_back(x + z + step);
			indices.push_back(x + z + step + 1);

			indices.push_back(x + z + step + 1);
			indices.push_back(x + z + 1);
		}
		z += step;
	}
	return indices;
}
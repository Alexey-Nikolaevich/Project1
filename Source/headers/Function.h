#ifndef FUNCTION_H
#define FUNCTION_H

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <vector> 

class Function
{
public:
	Function();
	void Initialize(float scale, float resolution, glm::vec4 boundaries);

	std::vector<glm::vec3>& GetVertices();
	std::vector<GLuint>& GetIndices();

private:
	std::vector<glm::vec3> vertices;
	std::vector<GLuint> indices;

	float scale;
	float resolution;
	glm::vec4 boundaries;
};


#endif 

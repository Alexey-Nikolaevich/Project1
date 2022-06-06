//--------------------------------------------------------------
//	DESCRIPTION: Visualize gradient descent
//--------------------------------------------------------------

#ifndef GRADIENT_DESCENT
#define GRADIENT_DESCENT

#include "Mesh.h"
#include "Function.h"

class Gradient_descent
{
public:
	void Initialize(float& scale, glm::vec4& boundaries, int& numberOfArrows, int& numberOfIterations);

	void GenerateArrow();
	void Draw(Shader& meshShader, Camera& camera);

protected:
	friend class Arrow;

	float scale;
	glm::vec4 boundaries;

	int numberOfArrows;
	int numberOfIterations;

	/*std::vector<Arrow> arrows;*/
};



//class Arrow
//{
//public:
//	Arrow(float& scale, glm::vec4& boundaries);
//	void Draw(Shader& meshShader, Camera& camera);
//
//	void Move();
//private:
//	Mesh mesh;
//
//	std::vector<glm::vec3> vertices;
//	std::vector<GLuint> indices;
//
//	glm::vec2 position;
//
//	float scale;
//	glm::vec4 boundaries;
//
//	float x = 0;
//	float y = 0;
//	float z = 0;
//};
//
#endif
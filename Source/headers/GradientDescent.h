#ifndef GRADIENT_DESCENT_H
#define GRADIENT_DESCENT_H

#include "Arrow.h"

class GradientDescent
{
public:
	void Initialize(float& scale, glm::vec4& boundaries, int& numberOfArrows, int& numberOfIterations, float& min_grad_vector, float& arrow_step);

	void GenerateArrows();
	void Draw(Shader& meshShader, Camera& camera);
	void UpdateArrows();

private:
	float scale;
	glm::vec4 boundaries;

	int numberOfArrows;
	int numberOfIterations;

	float min_grad_vector;
	float arrow_step;

	std::vector<Arrow> arrows;

	int arrowCounter = 0;
};

#endif
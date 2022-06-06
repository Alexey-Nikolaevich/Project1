#include "GradientDescent.h"

void GradientDescent::Initialize(float& scale, glm::vec4& boundaries, int& numberOfArrows, int& numberOfIterations, float& min_grad_vector, float& arrow_step)
{
	GradientDescent::scale = scale;
	GradientDescent::boundaries = boundaries;
	GradientDescent::numberOfArrows = numberOfArrows;
	GradientDescent::numberOfIterations = numberOfIterations;
	GradientDescent::min_grad_vector = min_grad_vector;
	GradientDescent::arrow_step = arrow_step;

	GenerateArrows();
}

void GradientDescent::GenerateArrows()
{
	if (arrowCounter < numberOfArrows)
	{
		arrows.push_back(Arrow(scale, boundaries, min_grad_vector, arrow_step, numberOfArrows));
		arrowCounter++;
	}
}

void GradientDescent::Draw(Shader& meshShader, Camera& camera)
{
	for (int i = 0; i < arrows.size(); i++)
	{
		arrows[i].Draw(meshShader, camera);
	}
	UpdateArrows();
}

void GradientDescent::UpdateArrows()
{
	for (int i = 0; i < arrows.size(); i++)
	{
		arrows[i].Move();
	}
}
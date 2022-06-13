#include "GradientDescent.h"

GradientDescent::GradientDescent()
{
	//==========================================//
	//std::cout << "GradientDescent constructed\n";
	//==========================================//
}

GradientDescent::~GradientDescent()
{
	//==========================================//
	//std::cout << "GradientDescent destructed\n";
	//==========================================//
}

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
		arrows.push_back(Arrow(scale, boundaries, min_grad_vector, arrow_step, numberOfIterations));
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

void GradientDescent::DeleteArrow()
{
	for (int i = 0; i < arrows.size(); i++)
	{
		arrows[i].~Arrow();
	}
	arrows.clear();
}

void GradientDescent::FindMinimum()
{
	std::cout << "Minimum:\n";

	heights.clear();

	heights.clear();
	for (int i = 0; i < arrows.size(); i++)
	{
		heights.push_back(arrows[i].GetHeight());
	}

	auto min = std::min_element(std::begin(heights), std::end(heights));

	std::cout << "\n\nMinimum: " << *min;
}
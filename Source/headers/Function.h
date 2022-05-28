#ifndef FUNCTION_H
#define FUNCTION_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

class Function
{
	Function();

	void Input();
	void GenerateVertices();
	void GenerateIndices();

private:
	int x_scale;
	int y_scale;
	int z_scale;
};

#endif

#include "Function.h"

float Function(float x, float z)
{
	float a = 0.08f;
	float b = 0.08f;
	float r = sqrt(a * x * x + b * z * z);
	return  sin(x * x + 0.1 * z * z) / (0.1 + r * r) + (x * x + 1.9 * z * z) * exp(1 - r * r) / 4.0;
	//return x * x/10 + z * z/10;
}

//===================GRADIENT_DESCENT==================//
glm::vec2 DescentVector(float x, float z)
{
	glm::vec2 descentVector;

	float x_vector;
	float z_vector;

	x_vector = Differentiate_X(x, z)/10;
	z_vector = Differentiate_Z(x, z)/10;

	descentVector = -glm::vec2(x_vector, z_vector);

	return descentVector;
}
//=====================================================//



//======================Differentiate=========================//
float Differentiate_X(float x, float z)
{
	float dx = 0.001; //TODO: Fix magic number

	return (Function(x + dx, z) - Function(x, z)) / dx;
}

float Differentiate_Z(float x, float z)
{
	float dz = 0.001; //TODO: Fix magic number

	return (Function(x, z + dz) - Function(x, z)) / dz;
}
//============================================================//



//=========================TRANSFORM_COORDINATES==========================//
float ToGraphScale_X(float variable)
{
	//TODO: FIX THIS ->
	float SCALE = 10;
	float RESOLUTION = 100;
	glm::vec4 BOUNDARIES = glm::vec4(-10.0f, 10.0f, -10.0f, 10.0f); // (x1;x2 : y1;y2)
	//================
	return (variable) * (abs(BOUNDARIES[0]) + abs(BOUNDARIES[1])) / SCALE + BOUNDARIES[0];
}

float ToGraphScale_Z(float variable)
{
	//TODO: FIX THIS ->
	float SCALE = 10;
	float RESOLUTION = 100;
	glm::vec4 BOUNDARIES = glm::vec4(-10.0f, 10.0f, -10.0f, 10.0f); // (x1;x2 : y1;y2)
	//================
	return (variable) * (abs(BOUNDARIES[2]) + abs(BOUNDARIES[3])) / SCALE + BOUNDARIES[2];
}
//========================================================================//
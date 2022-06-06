#ifndef FUNCTION_H
#define FUNCTION_H

#include "Graph.h"


float Function(float x, float z);

glm::vec2 DescentVector(float x, float z);
float Differentiate_X(float x, float z);
float Differentiate_Z(float x, float z);

float ToGraphScale_X(float variable);
float ToGraphScale_Z(float variable);


#endif FUNCTION_H
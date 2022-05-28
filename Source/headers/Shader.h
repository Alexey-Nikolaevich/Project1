//---------------------------------------------------------
//	DESCRIPTION: Compiles vertex and fragment shaders
//---------------------------------------------------------

#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>

std::string getFileContent(const char* filePath);

class Shader
{
public:
	Shader();
	~Shader();
	void Initialize();

	void Use();

	GLuint shaderProgram; //TODO:: make private field
private:
};

#endif


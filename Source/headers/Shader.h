//---------------------------------------------------------
//	DESCRIPTION: Compiles vertex and fragment shaders
//---------------------------------------------------------

#ifndef SHADER_H
#define SHADER_H


#include <glad/glad.h>
#include <iostream>
#include <string>
#include <fstream>

std::string GetFileContent(const char* filePath);

class Shader
{
public:
	~Shader();
	void Initialize(std::string vertexFile, std::string fragmentFile);

	void Use();

	GLuint& GetShaderProgram();

private:
	GLuint shaderProgram; 
};

#endif
//---------------------------------------------------------
//	DESCRIPTION: Compiles vertex and fragment shaders
//---------------------------------------------------------

#ifndef SHADER_H
#define SHADER_H

#include<glad/glad.h>
#include<string>

class Shader
{
public:
	Shader();
	~Shader();
	void Initialize();

	void Use();

private:
	GLuint shaderProgram;
};

#endif


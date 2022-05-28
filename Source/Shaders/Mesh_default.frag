#version 330 core

out vec4 FragColor;

in vec3 position;

void main()
{
	//TODO: fix Shader
	FragColor = vec4(0.0, position.y/10*position.y/10, 0.4 - position.y/15*position.y/15, 1.0f);
};
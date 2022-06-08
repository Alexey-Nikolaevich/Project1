#version 330 core

out vec4 FragColor;

in vec3 position;

void main()
{
	FragColor = vec4(-10 + position.x/1, position.y/1, -10 + position.z/1, 1.0f);
};
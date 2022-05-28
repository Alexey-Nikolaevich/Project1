#version 330 core

out vec4 FragColor;

in vec3 position;

void main()
{
	FragColor = vec4(0.85f, position.y, 0.10f, 1.0f);
};
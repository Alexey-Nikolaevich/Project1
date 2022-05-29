#version 330 core

out vec4 FragColor;

in vec3 position;

void main()
{
	//TODO: made reasonable coloring
	FragColor = vec4(0.8f, 0.3f + position.y, 0.2f, 1.0f);
};
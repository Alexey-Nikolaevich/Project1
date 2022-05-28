#include "Camera.h"

Camera::Camera()
{

}

void Camera::Initialize(int width, int height, glm::vec3 Position, glm::vec3 Orientation, float nearRenderDistance, float farRenderDistance, float FOV)
{
	Camera::width = width;
	Camera::height = height;
	Camera::Position = Position;
	Camera::Orientation = Orientation;
	Camera::nearRenderDistance = nearRenderDistance;
	Camera::nearRenderDistance = farRenderDistance;
	Camera::FOV = FOV;
}

void Camera::UniformMatrix(GLuint& shaderProgram, const char* uniform)
{
	view = glm::lookAt(Position, Position + Orientation, Up);

	proj = glm::perspective(glm::radians(FOV), (float)width / height, nearRenderDistance, farRenderDistance);

	glUniformMatrix4fv(glGetUniformLocation(shaderProgram, uniform), 1, GL_FALSE, glm::value_ptr(proj * view));
}

void Camera::Controls()
{

}
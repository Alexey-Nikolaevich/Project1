#ifndef CAMERA_H
#define CAMERA_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtx/vector_angle.hpp>

class Camera
{
public: 
	Camera();
	void Initialize(int width, int height, glm::vec3 Position, glm::vec3 Orientation, float nearRenderDistance, float farRenderDistance, float FOV, float speed, float sensitivity);

	void UniformMatrix(GLuint& shaderProgram, const char* uniform);
	void Controls(GLFWwindow* window);

	glm::vec3 GetPosition();

private:
	//To many variables
	glm::vec3 StartPosition;
	glm::vec3 Position;
	glm::vec3 StartOrientation;
	glm::vec3 Orientation;
	glm::vec3 Up = glm::vec3(0.0f, 1.0f, 0.0f);

	glm::mat4 view = glm::mat4(1.0f);
	glm::mat4 proj = glm::mat4(1.0f);

	float nearRenderDistance;
	float farRenderDistance;

	float FOV;

	bool catchMouse = false;
	bool firstClick = true;

	int width;
	int height;

	float speed;
	float sensitivity;
};

#endif
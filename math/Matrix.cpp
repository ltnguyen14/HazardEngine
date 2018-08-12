#include "Matrix.h"
#include "../graphics/entities/camera.h"
#include "../graphics/entities/Entity.h"
#include "../app/window.h"

#define GLM_ENABLE_EXPERIMENTAL
#include "gtx/string_cast.hpp"

glm::mat4 makeModelMatrix(const Entity & entity)
{
	glm::mat4 matrix = glm::mat4(1);

	matrix = glm::rotate(matrix, glm::radians(entity.rotation.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(entity.rotation.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(entity.rotation.z), { 0, 0, 1 });

	matrix = glm::translate(matrix, entity.position);

	return matrix;
}

glm::mat4 makeViewMatrix(const Camera & camera, Window* window)
{
	glm::mat4 matrix = glm::mat4(1);

	matrix = glm::rotate(matrix, glm::radians(camera.rotation.x), { 1, 0, 0 });
	matrix = glm::rotate(matrix, glm::radians(camera.rotation.y), { 0, 1, 0 });
	matrix = glm::rotate(matrix, glm::radians(camera.rotation.z), { 0, 0, 1 });

	matrix = glm::translate(matrix, -camera.position);
	matrix = glm::translate(matrix, { window->getWidth() / 2 - camera.size.x / 2, window->getHeight() / 2 - camera.size.y / 2, 0 });

	return matrix;
}

glm::mat4 makeProjectionMatrix(float fov, Window* window)
{
	return glm::perspective(glm::radians(fov), (float) window->getWidth() / (float) window->getHeight(), 0.1f, 1000.0f);
}

glm::mat4 makeOrthoMatrix(Window * window)
{
	return glm::ortho(0.0f, (float)window->getWidth(), (float)window->getHeight(), 0.0f, -100.0f, 100.0f);
}

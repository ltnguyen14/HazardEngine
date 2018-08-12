#pragma once

#include <glm.hpp>
#include <gtc/matrix_transform.hpp>

class Camera;
struct Entity;
class Window;

glm::mat4 makeModelMatrix(const Entity& entity);
glm::mat4 makeViewMatrix(const Camera& camera, Window* window);
glm::mat4 makeProjectionMatrix(float fov, Window* window);
glm::mat4 makeOrthoMatrix(Window* window);


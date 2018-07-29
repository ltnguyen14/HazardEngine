#pragma once
#include "Entity.h"
#include "../math/Matrix.h"
#include <glm.hpp>

class Camera : public Entity{
public:
	Camera(Window* window);
	Camera() {};

	void update();
	void hookEntity(const Entity& entity);

	const glm::mat4& getViewMatrix() const;
	const glm::mat4& getProjMatrix() const;
	const glm::mat4& getProjectionViewMatrix() const;

private:
	const Entity* m_Entity;
	glm::mat4 m_projectionMatrix;
	glm::mat4 m_viewMatrix;
	glm::mat4 m_projViewMatrx;
};
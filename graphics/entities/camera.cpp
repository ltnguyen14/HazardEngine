#include "camera.h"

Camera::Camera(Window* window)
	:m_window(window)
{
	m_projectionMatrix = makeOrthoMatrix(window);
	position = { 0, 0, 0 };
}

void Camera::update()
{
	position = m_Entity->position;
	rotation = m_Entity->rotation;
	size = m_Entity->size;

	m_viewMatrix = makeViewMatrix(*this, m_window);
	m_projViewMatrx = m_projectionMatrix * m_viewMatrix;
}

void Camera::hookEntity(const Entity & entity)
{
	m_Entity = &entity;
}

const glm::mat4 & Camera::getViewMatrix() const
{
	return m_viewMatrix;
}

const glm::mat4 & Camera::getProjMatrix() const
{
	return m_projectionMatrix;
}

const glm::mat4 & Camera::getProjectionViewMatrix() const
{
	return m_projViewMatrx;
}


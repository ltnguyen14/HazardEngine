#include "Player.h"

Player::Player(glm::vec3 position, glm::vec3 rotation, Window * window)
	:m_window(window)
{
	this->position = position;
	this->rotation = rotation;

	m_window->SetMousePos(m_window->getWidth()/2, m_window->getHeight()/2);
	m_xLastPos = m_window->getWidth() / 2;
	m_yLastPos = m_window->getHeight() / 2;
}

void Player::KeyboardInput()
{
	glm::vec3 displacement = { 0, 0, 0 };
	if (m_window->GetKey(GLFW_KEY_W)) {
		displacement.x = glm::cos(glm::radians(rotation.y + 90)) * m_speed;
		displacement.z = glm::sin(glm::radians(rotation.y + 90)) * m_speed;
	}
	else if (m_window->GetKey(GLFW_KEY_S)) {
		displacement.x = -glm::cos(glm::radians(rotation.y + 90)) * m_speed;
		displacement.z = -glm::sin(glm::radians(rotation.y + 90)) * m_speed;
	}

	if (m_window->GetKey(GLFW_KEY_A)) {
		displacement.x = glm::cos(glm::radians(rotation.y)) * m_speed;
		displacement.z = glm::sin(glm::radians(rotation.y)) * m_speed;
	}
	else if (m_window->GetKey(GLFW_KEY_D)) {
		displacement.x = -glm::cos(glm::radians(rotation.y)) * m_speed;
		displacement.z = -glm::sin(glm::radians(rotation.y)) * m_speed;
	}

	if (m_window->GetKey(GLFW_KEY_Q))
		displacement.y += m_speed;
	else if (m_window->GetKey(GLFW_KEY_E))
		displacement.y -= m_speed;

	position += displacement;
}

void Player::MouseInput()
{
	static auto const BOUND = 80;

	double xPos, yPos;
	m_window->GetMousePos(&xPos, &yPos);
	auto xDisplacement = xPos - m_xLastPos;
	auto yDisplacement = yPos - m_yLastPos;

	rotation.y += xDisplacement * 0.05f;
	rotation.x += yDisplacement * 0.05f;

	if (rotation.x >  BOUND) rotation.x = BOUND;
	else if (rotation.x < -BOUND) rotation.x = -BOUND;

	if (rotation.y >  360) rotation.y = 0;
	else if (rotation.y < 0)    rotation.y = 360;

	m_xLastPos = m_window->getWidth() / 2;
	m_yLastPos = m_window->getHeight() / 2;
}

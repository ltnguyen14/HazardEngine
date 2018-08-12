#include "Player.h"

Player::Player(glm::vec3 position, glm::vec3 rotation, Window * window)
	:m_window(window)
{
	this->position = position;
	this->rotation = rotation;

	//m_window->SetMousePos(m_window->getWidth()/2, m_window->getHeight()/2);
	m_xLastPos = m_window->getWidth() / 2;
	m_yLastPos = m_window->getHeight() / 2;
}

void Player::SetSprite(Sprite2D * sprite)
{
	m_sprite = sprite;
}

void Player::KeyboardInput()
{
	glm::vec3 displacement = { 0, 0, 0 };
	if (m_window->GetKey(GLFW_KEY_W)) {
		displacement.y -= m_speed;
	}
	else if (m_window->GetKey(GLFW_KEY_S)) {
		displacement.y += m_speed;
	}

	if (m_window->GetKey(GLFW_KEY_A)) {
		displacement.x -= m_speed;
	}
	else if (m_window->GetKey(GLFW_KEY_D)) {
		displacement.x += m_speed;
	}

	float displacement_length = sqrt(displacement.x * displacement.x + displacement.y * displacement.y);
	if (displacement_length != 0) {
		displacement = glm::vec3((float)displacement.x / displacement_length, (float)displacement.y / displacement_length, 0) * m_speed;
		position += displacement;
	}
	if (m_sprite != nullptr) m_sprite->position = this->position;
}

void Player::MouseInput()
{
	/*static auto const BOUND = 80;

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
	m_yLastPos = m_window->getHeight() / 2;*/
}

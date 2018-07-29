#pragma once
#include "../app/window.h"
#include "Entity.h"
#include <glm.hpp>

class Player : public Entity{
public:
	Player(glm::vec3 position, glm::vec3 rotation, Window* window);
	Player() {};

	void KeyboardInput();
	void MouseInput();

private:
	Window * m_window;
	float m_speed = 0.05f;
	double m_xLastPos, m_yLastPos;
};
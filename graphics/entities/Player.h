#pragma once
#include "../app/window.h"
#include "../2D_graphics/sprite2D.h"
#include "Entity.h"
#include <glm.hpp>

class Player : public Entity{
public:
	Player(glm::vec3 position, glm::vec3 rotation, Window* window);
	Player() { };

	void SetSprite(Sprite2D* sprite);

	void KeyboardInput();
	void MouseInput();

private:
	Window * m_window;
	float m_speed = 5.0f;
	double m_xLastPos, m_yLastPos;
	Sprite2D* m_sprite = nullptr;
};
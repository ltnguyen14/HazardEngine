#pragma once
#include "../2D_graphics/sprite2D.h"
#include "../../app/window.h"
#include "../entities/camera.h"
#include "../shaders/shader.h"
#include "../graphics/texture/textureAtlas.h"

class SpriteRenderer {
public:
	SpriteRenderer(const std::string & shaderPath);

	void AddSprite(Sprite2D * sprite);
	void Render(Window* window, const Camera& camera);

private:
	std::vector<Sprite2D*> m_sprites;
	Shader m_shader;
};
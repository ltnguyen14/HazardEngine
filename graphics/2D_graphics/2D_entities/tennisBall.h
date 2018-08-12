#pragma once
#include "../../entities/Entity.h"
#include "../sprite2D.h"
#include "../../renderers/spriteRenderer.h"

class TennisBall : public Entity {
public:
	TennisBall(SpriteRenderer* spriteRenderer, TextureAtlas* textureAtlas);
	TennisBall() {};

	~TennisBall();

	void Update();

private:
	Sprite2D m_sprite;
	SpriteRenderer* m_spriteRenderer;
};
#include "tennisBall.h"

TennisBall::TennisBall(SpriteRenderer* spriteRenderer, TextureAtlas* textureAtlas)
	:m_spriteRenderer(spriteRenderer), m_sprite({ 50, 50, 0 }, textureAtlas, { { 0, 0 },{ 1, 1 } }, { 16, 16, 0 })
{
}

TennisBall::~TennisBall()
{
}

void TennisBall::Update()
{
	m_spriteRenderer->AddSprite(&m_sprite);
}

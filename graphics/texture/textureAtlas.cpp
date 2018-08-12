#include "textureAtlas.h"
#include "../2D_graphics/sprite2D.h"

TextureAtlas::TextureAtlas(const std::string & filePath)
	:m_textureAtlas(filePath)
{
	m_width = m_textureAtlas.getWidth();
	m_height = m_textureAtlas.getHeight();
}

std::vector<float> TextureAtlas::getTexture(const glm::vec2 & coords)
{
	static const float TEX_PER_ROW = (float)m_width / (float)BLOCK_SIZE;
	static const float BLOCK_SIZE = 1.0f / TEX_PER_ROW;

	float xMin = (coords.x * BLOCK_SIZE);
	float yMax = (coords.y * BLOCK_SIZE) / m_width * (-1) + 1;

	float xMax = (xMin + BLOCK_SIZE);
	float yMin = (yMax - BLOCK_SIZE);

	return { xMin, xMax, yMin, yMax };
}

std::vector<float> TextureAtlas::get2DTexture(const SpriteTextureData & textureData)
{
	const float TEX_PER_ROW = (float)m_width / (float)SPRITE_SIZE;
	const float SPRITE_SIZE_WIDTH = 1.0f / TEX_PER_ROW;
	const float SPRITE_SIZE_HEIGHT = 1.0f / ((float)m_height / (float)SPRITE_SIZE);

	float xMin = (textureData.coordinate.x * (float)SPRITE_SIZE_WIDTH);
	float yMax = (textureData.coordinate.y * (float)SPRITE_SIZE_HEIGHT) / (float)m_width * (-1) + 1;

	float xMax = (xMin + SPRITE_SIZE_WIDTH * textureData.textureSize.x);
	float yMin = (yMax - SPRITE_SIZE_HEIGHT * textureData.textureSize.y);

	return { xMin, xMax, yMax, yMin };
}

void TextureAtlas::Bind() const
{
	m_textureAtlas.Bind();
}

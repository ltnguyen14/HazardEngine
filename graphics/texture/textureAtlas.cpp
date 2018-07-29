#include "textureAtlas.h"
#include "../2D_graphics/sprite2D.h"

TextureAtlas::TextureAtlas(const std::string & filePath)
	:m_textureAtlas(filePath)
{
	m_size = m_textureAtlas.getWidth();
}

std::vector<float> TextureAtlas::getTexture(const glm::vec2 & coords)
{
	static const float TEX_PER_ROW = (float)m_size / (float)BLOCK_SIZE;
	static const float BLOCK_SIZE = 1.0f / TEX_PER_ROW;

	float xMin = (coords.x * BLOCK_SIZE);
	float yMax = (coords.y * BLOCK_SIZE) / m_size * (-1) + 1;

	float xMax = (xMin + BLOCK_SIZE);
	float yMin = (yMax - BLOCK_SIZE);

	return { xMin, xMax, yMin, yMax };
}

std::vector<float> TextureAtlas::get2DTexture(const SpriteTextureData & textureData)
{
	static const float TEX_PER_ROW = (float)m_size / (float)SPRITE_SIZE;
	static const float SPRITE_SIZE = 1.0f / TEX_PER_ROW;

	float xMin = (textureData.coordinate.x * SPRITE_SIZE);
	float yMax = (textureData.coordinate.y * SPRITE_SIZE) / m_size * (-1) + 1;

	float xMax = (xMin + textureData.textureSize.x);
	float yMin = (yMax - textureData.textureSize.y);

	return { xMin, xMax, yMin, yMax };
}

void TextureAtlas::Bind() const
{
	m_textureAtlas.Bind();
}

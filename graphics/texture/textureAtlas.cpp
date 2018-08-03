#include "textureAtlas.h"
#include "../2D_graphics/sprite2D.h"

TextureAtlas::TextureAtlas(const std::string & filePath)
	:m_textureAtlas(filePath)
{
	m_width = m_textureAtlas.getWidth();
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
	static const float TEX_PER_ROW = (float)m_width / (float)SPRITE_SIZE;
	static const float SPRITE_SIZE = 1.0f / TEX_PER_ROW;

	std::cout << TEX_PER_ROW << std::endl;

	float xMin = (textureData.coordinate.x * SPRITE_SIZE);
	float yMax = (textureData.coordinate.y * SPRITE_SIZE) / m_width * (-1) + 1;

	float xMax = (xMin + 1.0f / textureData.textureSize.x);
	float yMin = (yMax - 1.0f / textureData.textureSize.y);

	std::cout << xMin << " " << yMax << " " << xMax << " " << yMin << std::endl;

	return { xMin, xMax, yMax, yMin };
}

void TextureAtlas::Bind() const
{
	m_textureAtlas.Bind();
}

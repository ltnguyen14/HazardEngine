#pragma once
#include "texture.h"
#include "../app/config.h"
#include <glm.hpp>
#include <vector>

class SpriteTextureData;

class TextureAtlas {
public:
	TextureAtlas(const std::string& filePath);

	std::vector<float> getTexture(const glm::vec2& coords);
	std::vector<float> get2DTexture(const SpriteTextureData& textureData);

	void Bind() const;
private:
	Texture m_textureAtlas;
	int m_width, m_height;
};

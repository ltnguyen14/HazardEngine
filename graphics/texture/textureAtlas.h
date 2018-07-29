#pragma once
#include "texture.h"
#include "../app/config.h"
#include <glm.hpp>
#include <vector>

class TextureAtlas {
public:
	TextureAtlas(const std::string& filePath);

	std::vector<float> getTexture(const glm::vec2& coords);

	void Bind() const;
private:
	Texture m_textureAtlas;
	int m_size;
};

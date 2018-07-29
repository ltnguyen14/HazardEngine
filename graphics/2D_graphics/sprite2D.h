#pragma once
#include "../entities/Entity.h"
#include "../texture/textureAtlas.h"
#include "glm.hpp"

struct SpriteTextureData {
	glm::vec2 coordinate;
	glm::vec2 textureSize;
};

class Sprite2D : public Entity{
public:
	Sprite2D(glm::vec3 worldPosition, TextureAtlas* textureAtlas, SpriteTextureData textureData);
	~Sprite2D();

	void Bind();

	inline unsigned int getIndiciesCount() { return m_ibo->getCount(); };

private:
	VertexArray m_vao;
	VertexBuffer* m_vbo;
	IndexBuffer* m_ibo;
	std::string m_cubeName;
	TextureAtlas* m_textureAtlas;
	SpriteTextureData m_textureData;
};
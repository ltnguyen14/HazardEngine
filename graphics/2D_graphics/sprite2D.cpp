#include "sprite2D.h"

Sprite2D::Sprite2D(glm::vec3 worldPosition, TextureAtlas * textureAtlas, SpriteTextureData textureData, glm::vec3 size)
	: m_vao(), m_ibo(), m_vbo(), m_textureAtlas(textureAtlas), m_textureData(textureData)
{
	position = worldPosition;
	std::vector<float> textureCoords = m_textureAtlas->get2DTexture(m_textureData);
	float positions[] = {
		0.0f,   0.0f,   0.0f, textureCoords[0], textureCoords[2],
		size.x, 0.0f,   0.0f, textureCoords[1], textureCoords[2],
		size.x, size.y, 0.0f, textureCoords[1], textureCoords[3],
		0.0f,   size.y, 0.0f, textureCoords[0], textureCoords[3],
	};

	unsigned int indicies[] = {
		0, 1, 2,
		2, 3, 0,
	};

	m_vbo = new VertexBuffer(positions, 5 * 4 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	m_vao.AddBuffer(*m_vbo, layout);

	m_ibo = new IndexBuffer(indicies, 6);
}

Sprite2D::~Sprite2D()
{
	delete(m_vbo);
	delete(m_ibo);
}

void Sprite2D::Bind()
{
	m_vao.Bind();
	m_ibo->Bind();
}

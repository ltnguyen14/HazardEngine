#pragma once
#include "Entity.h"
#include "../texture/textureAtlas.h"
#include <glm.hpp>

class Cube : public Entity {
public:
	Cube(glm::vec3 worldPosition, const std::string& cubeName, TextureAtlas* textureAtlas);
	~Cube();

	void Bind();
	void GetCubeInfos(const std::string& filePath);

	inline unsigned int getIndiciesCount() { return m_ibo->getCount(); };

private:
	VertexArray m_vao;
	VertexBuffer* m_vbo;
	IndexBuffer* m_ibo;
	std::string m_cubeName;
	TextureAtlas* m_textureAtlas;
	glm::vec2 m_texturesCoords[3];
};
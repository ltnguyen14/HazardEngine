#include "Cube.h"
#include <typeinfo>
#include <fstream>
#include <sstream>

glm::vec2 split(const std::string& s, char delimiter)
{
	glm::vec2 tokens = glm::vec2();
	std::string token;
	std::istringstream tokenStream(s);
	int i = 0;
	while (std::getline(tokenStream, token, delimiter))
	{
		tokens[i] = (float) std::stoi(token);
		i++;
	}
	return tokens;
}

Cube::Cube(glm::vec3 worldPosition, const std::string& cubeName, TextureAtlas* textureAtlas)
	: m_vao(), m_ibo(), m_vbo(), m_cubeName(cubeName), m_textureAtlas(textureAtlas)
{
	GetCubeInfos("res/blockInfos/" + cubeName + ".txt");
	position = worldPosition;
	std::vector<float> topCoords = m_textureAtlas->getTexture(m_texturesCoords[0]);
	std::vector<float> bottomCoords = m_textureAtlas->getTexture(m_texturesCoords[1]);
	std::vector<float> sideCoords = m_textureAtlas->getTexture(m_texturesCoords[2]);

	float positions[] = {
		//Back	 
		1, 0, 0, sideCoords[1], sideCoords[2],
		0, 0, 0, sideCoords[0], sideCoords[2],
		0, 1, 0, sideCoords[0], sideCoords[3],
		1, 1, 0, sideCoords[1], sideCoords[3],
				 
		//Front
		0, 0, 1, sideCoords[1], sideCoords[2],
		1, 0, 1, sideCoords[0], sideCoords[2],
		1, 1, 1, sideCoords[0], sideCoords[3],
		0, 1, 1, sideCoords[1], sideCoords[3],

		//Right
		1, 0, 1, sideCoords[1], sideCoords[2],
		1, 0, 0, sideCoords[0], sideCoords[2],
		1, 1, 0, sideCoords[0], sideCoords[3],
		1, 1, 1, sideCoords[1], sideCoords[3],

		//Left
		0, 0, 0, sideCoords[1], sideCoords[2],
		0, 0, 1, sideCoords[0], sideCoords[2],
		0, 1, 1, sideCoords[0], sideCoords[3],
		0, 1, 0, sideCoords[1], sideCoords[3],

		//Top
		0, 1, 1, topCoords[1], topCoords[2],
		1, 1, 1, topCoords[0], topCoords[2],
		1, 1, 0, topCoords[0], topCoords[3],
		0, 1, 0, topCoords[1], topCoords[3],

		//Bottom
		0, 0, 0, bottomCoords[1], bottomCoords[2],
		1, 0, 0, bottomCoords[0], bottomCoords[2],
		1, 0, 1, bottomCoords[0], bottomCoords[3],
		0, 0, 1, bottomCoords[1], bottomCoords[3],
	};

	unsigned int indicies[] = {
		0, 1, 2,
		2, 3, 0,

		4, 5, 6,
		6, 7, 4,

		8, 9, 10,
		10, 11, 8,

		12, 13, 14,
		14, 15, 12,

		16, 17, 18,
		18, 19, 16,

		20, 21, 22,
		22, 23, 20
	};

	m_vbo = new VertexBuffer(positions, 5 * 4 * 6 * sizeof(float));

	VertexBufferLayout layout;
	layout.Push<float>(3);
	layout.Push<float>(2);
	m_vao.AddBuffer(*m_vbo, layout);

	m_ibo = new IndexBuffer(indicies, 6 * 6);
}

Cube::~Cube()
{
	delete(m_vbo);
	delete(m_ibo);
}

void Cube::Bind()
{
	m_vao.Bind();
	m_ibo->Bind();
}

void Cube::GetCubeInfos(const std::string & filePath)
{
	enum class TextureSides {
		NONE = -1, TOP = 0, BOTTOM = 1, SIDE = 2
	};
	std::ifstream stream(filePath);
	std::string line;
	std::stringstream ss[2];
	TextureSides type = TextureSides::NONE;

	while (getline(stream, line)) {
		if (line.find("TEX TOP") != std::string::npos) {
			type = TextureSides::TOP;
		} else if (line.find("TEX BOTTOM") != std::string::npos) {
			type = TextureSides::BOTTOM;
		}
		else if (line.find("TEX SIDE") != std::string::npos) {
			type = TextureSides::SIDE;
		}
		else if (!line.empty()){
			m_texturesCoords[(int)type] = split(line, ' ');
		}
	}
}

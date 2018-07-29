#pragma once
#include "../entities/Cube.h"
#include "../../app/window.h"
#include "../entities/camera.h"
#include "../shaders/shader.h"
#include "../graphics/texture/textureAtlas.h"


class CubeRenderer {
public:
	CubeRenderer(const std::string & shaderPath, TextureAtlas* textureAtlas);

	void addCube(Cube * cube);
	void Render(Window* window, const Camera& camera);

private:
	std::vector<Cube*> m_cubes;
	Shader m_shader;
	TextureAtlas* m_textureAtlas;
};
#include "cubeRenderer.h"
#include <glm.hpp>
#include "gtc/matrix_transform.hpp"


CubeRenderer::CubeRenderer(const std::string & shaderPath, TextureAtlas* textureAtlas)
	: m_shader(shaderPath), m_textureAtlas(textureAtlas)
{
}

void CubeRenderer::AddCube(Cube * cube)
{
	m_cubes.push_back(cube);
}

void CubeRenderer::Render(Window* window, const Camera& camera)
{
	m_shader.BindShader();

	m_shader.SetUniformInt1("u_Texture", 0);
	m_textureAtlas->Bind();

	glm::mat4 projViewMatrix = camera.getProjectionViewMatrix();
	m_shader.SetUniformMat4("u_VP", projViewMatrix);

	GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCALL(glEnable(GL_BLEND));

	for (unsigned int i = 0; i < m_cubes.size(); i++) {
		m_cubes[i]->Bind();

		glm::mat4 modelMatrix = makeModelMatrix({ m_cubes[i]->position, { 0, 0, 0 } });
		m_shader.SetUniformMat4("u_M", modelMatrix);

		GLCALL(glDrawElements(GL_TRIANGLES, m_cubes[i]->getIndiciesCount(), GL_UNSIGNED_INT, nullptr));
	}

	for (unsigned int i = 0; i < m_cubes.size(); i++) {
		delete(m_cubes[i]);
	}
	m_cubes.clear();

	//m_cubes.erase(m_cubes.begin(), m_cubes.end());
}

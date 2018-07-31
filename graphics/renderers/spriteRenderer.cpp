#include "spriteRenderer.h"

SpriteRenderer::SpriteRenderer(const std::string & shaderPath, TextureAtlas * textureAtlas)
	: m_shader(shaderPath), m_textureAtlas(textureAtlas)
{
}

void SpriteRenderer::AddSprite(Sprite2D * sprite)
{
	m_sprites.push_back(sprite);
}

void SpriteRenderer::Render(Window * window, const Camera & camera)
{
	m_shader.BindShader();

	m_shader.SetUniformInt1("u_Texture", 0);
	m_textureAtlas->Bind();

	glm::mat4 projViewMatrix = camera.getProjectionViewMatrix();
	m_shader.SetUniformMat4("u_VP", projViewMatrix);

	GLCALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));
	GLCALL(glEnable(GL_BLEND));

	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		m_sprites[i]->Bind();

		glm::mat4 modelMatrix = makeModelMatrix({ m_sprites[i]->position, { 0, 0, 0 } });
		m_shader.SetUniformMat4("u_M", modelMatrix);

		GLCALL(glDrawElements(GL_TRIANGLES, m_sprites[i]->getIndiciesCount(), GL_UNSIGNED_INT, nullptr));
	} 

	GLCALL(glDisable(GL_BLEND));
	for (unsigned int i = 0; i < m_sprites.size(); i++) {
		delete(m_sprites[i]);
	}
	m_sprites.clear();
}

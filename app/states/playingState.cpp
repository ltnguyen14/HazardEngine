#include "playingState.h"

void PlayingState::Init(Window* window)
{
	m_window = window;
	m_textureAtlas =  new TextureAtlas("res/textures/player.png");
	m_camera = Camera(window);
	m_player = Player({ { 0, 0, -2 }, { 0, 0, 0 }, m_window });
	m_camera.hookEntity(m_player);

	m_spriteRenderer = new SpriteRenderer("res/shaders/BasicShader.shader", m_textureAtlas);
}

void PlayingState::Cleanup()
{
	delete(m_spriteRenderer);
	delete(m_textureAtlas);
}

void PlayingState::Pause()
{
}

void PlayingState::Resume()
{
}

void PlayingState::HandleEvents(GameEngine * game)
{
	//m_player.KeyboardInput();
	//m_player.MouseInput();
}

void PlayingState::Update(GameEngine * game)
{
	Sprite2D* sprite = new Sprite2D({ 10, 10, 0 }, m_textureAtlas, { { 0.5f, 0 }, { 32, 32 } }, { 32, 32, 0 });
	m_spriteRenderer->AddSprite(sprite);
	m_camera.update();
}

void PlayingState::Draw(GameEngine * game)
{
	m_window->Clear();
	m_spriteRenderer->Render(m_window, m_camera);
	m_window->Update();
}

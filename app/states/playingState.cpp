#include "playingState.h"

void PlayingState::Init(Window* window)
{
	m_window = window;
	m_spriteRenderer = new SpriteRenderer("res/shaders/BasicShader.shader");
	m_textureAtlas =  new TextureAtlas("res/textures/player.png");
	m_utilTextureAtlas = new TextureAtlas("res/textures/util.png");

	m_camera = Camera(window);
	m_camera.hookEntity(m_player);

	m_player = Player({ { 0, 0, -2 }, { 0, 0, 0 }, m_window });
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
	m_player.KeyboardInput();
	m_player.MouseInput();
}

void PlayingState::Update(GameEngine * game)
{
	Sprite2D* sprite = new Sprite2D({ 0, 0, 0 }, m_textureAtlas, { { 0, 0 }, { 1, 1 } }, { 64, 64, 0 });

	m_camera.hookEntity(*sprite);
	m_player.SetSprite(sprite);
	
	m_spriteRenderer->AddSprite(sprite);

	m_camera.update();
}

void PlayingState::Draw(GameEngine * game)
{
	m_window->Clear();
	m_spriteRenderer->Render(m_window, m_camera);
	m_window->Update();
}

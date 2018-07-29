#include "playingState.h"

void PlayingState::Init(Window* window)
{
	m_window = window;
	m_textureAtlas =  new TextureAtlas("res/textures/TexturePack.png");
	m_camera = Camera(window);
	m_player = Player({ { 0, 0, -3 }, { 0, 0, 0 }, m_window });
	m_camera.hookEntity(m_player);

	m_cubeRenderer = new CubeRenderer("res/shaders/BasicShader.shader", m_textureAtlas);
	m_window->HideMouse();
}

void PlayingState::Cleanup()
{
	delete(m_cubeRenderer);
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
	for (int i = 0; i < 100; i++) {
		Cube* cube = new Cube({ i, 0, 0 }, "stone", m_textureAtlas);
		m_cubeRenderer->addCube(cube);
	}

	m_camera.update();
}

void PlayingState::Draw(GameEngine * game)
{
	m_window->Clear();
	m_cubeRenderer->Render(m_window, m_camera);
	m_window->Update();
}

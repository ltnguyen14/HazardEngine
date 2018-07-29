#include "gameEngine.h"
#include "gameState.h"

GameEngine::GameEngine(int width, int height, std::string title, float fps)
	:m_window(width, height, title), m_fps(fps)
{
	MS_PER_UPDATE = 1000 / fps;
}

void GameEngine::Cleanup()
{
}

void GameEngine::ChangeState(GameState * state)
{
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	states.push_back(state);
	states.back()->Init(&m_window);
}

void GameEngine::PushState(GameState * state)
{
	// pause current state
	if (!states.empty()) {
		states.back()->Pause();
	}

	// store and init the new state
	states.push_back(state);
	states.back()->Init(&m_window);
}

void GameEngine::PopState()
{
	// cleanup the current state
	if (!states.empty()) {
		states.back()->Cleanup();
		states.pop_back();
	}

	// resume previous state
	if (!states.empty()) {
		states.back()->Resume();
	}
}

void GameEngine::HandleEvents()
{
	states.back()->HandleEvents(this);
	if (m_window.GetKey(GLFW_KEY_ESCAPE))
		m_running = false;
}

void GameEngine::Update()
{
	if (m_window.Closed()) m_running = false;
	states.back()->Update(this);
}

void GameEngine::Draw()
{
	states.back()->Draw(this);
}

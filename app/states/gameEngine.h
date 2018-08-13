#pragma once
#include <vector>
#include "../window.h"

class GameState;

class GameEngine {
public:
	GameEngine(int width, int height, std::string title, float fps = 60);
	void Cleanup();

	void ChangeState(GameState* state);
	void PushState(GameState* state);
	void PopState();

	void InitEntities();
	void HandleEvents();
	void Update();
	void Draw();

	bool Running() { return m_running; };
	void Quit() { m_running = false; };

private:
	std::vector<GameState*> states;
	bool m_running = true;
	Window m_window;
	float m_fps;
	float MS_PER_UPDATE;
};
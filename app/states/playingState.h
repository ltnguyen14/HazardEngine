#pragma once
#include "gameState.h"
#include "../window.h"
#include "../graphics/renderers/spriteRenderer.h"
#include "../graphics/entities/Player.h"

class PlayingState : public GameState {
public:
	void Init(Window* window);
	void Cleanup();

	void Pause();
	void Resume();

	void HandleEvents(GameEngine* game);
	void Update(GameEngine* game);
	void Draw(GameEngine* game);

	static PlayingState* Instance() {
		static PlayingState instance;
		return &instance;
	}

protected:
	PlayingState() { }

private:
	Window* m_window = nullptr;
	Camera m_camera;
	Player m_player;
	SpriteRenderer* m_spriteRenderer;
	TextureAtlas* m_textureAtlas;
};
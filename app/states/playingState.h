#pragma once
#include "gameState.h"
#include "../window.h"
#include "../graphics/renderers/spriteRenderer.h"
#include "../graphics/entities/Player.h"
#include "../graphics/2D_graphics/2D_entities/tennisBall.h"

class PlayingState : public GameState {
public:
	void Init(Window* window);
	void Cleanup();

	void Pause();
	void Resume();

	void InitEntities(GameEngine* game);
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
	TennisBall m_tennisBall;
	SpriteRenderer* m_spriteRenderer;
	TextureAtlas *m_textureAtlas, *m_utilTextureAtlas;
};
#include "app/states/gameEngine.h"
#include "app/states/playingState.h"

int main(void) {
	GameEngine game(1080, 720, "Test game", 60);

	game.ChangeState(PlayingState::Instance());

	while (game.Running()) {
		game.InitEntities();
		game.HandleEvents();
		game.Update();
		game.Draw();
	}

	game.Cleanup();
	return 0;
}
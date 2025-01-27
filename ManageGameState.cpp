# include <Siv3D.hpp>
# include "ManageGameState.h"

ManageGameState::ManageGameState()
	:gamestate(GameState::BeforePlaying) { };

enum class GameState {
	BeforePlaying,
	Playing,
	GameOver
};

GameState ManageGameState::getGameState()
{
	return gamestate;
}

void ManageGameState::setGameState(GameState updated_gamestate)
{
	gamestate = updated_gamestate;
}

GameState ManageGameState::switchGameMode()
{
	// when recieve enterkey press, turn GameState to Playing

	// when recieve collide info, turn GameState to GameOver

	// when recieve retry button press, turn GameState to Playing

	// when recieve title button press, turn GameState to BeforePlaying
}


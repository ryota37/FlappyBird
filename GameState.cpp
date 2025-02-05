#include "GameState.h"
#include <Siv3D.hpp>

void BeforePlaying::exec()
{
	// The title screen shown before playing the game.
	Print << U"Title Screen";
}

Playing::Playing(const std::shared_ptr<Bird>& bird, const std::shared_ptr<ClayPipe>& clayPipe)
	: bird(bird), clayPipe(clayPipe)
{
}

void Playing::exec()
{
	// Rendering of the claypipe
	clayPipe->update();
	clayPipe->draw();
	// Rendering of the bird
	bird->update();
	bird->draw();

	// temporary code
	Print << U"Playing";
}

void GameOver::exec()
{
	// The title screen shown before playing the game.
	Print << U"GameOver";
}

GameContext::GameContext()
	: currentState(std::make_shared<BeforePlaying>())
{
}

void GameContext::setState(std::shared_ptr<GameState> state)
{
	currentState = state;
}

void GameContext::startGame()
{
	bird = std::make_shared<Bird>(Scene::CenterF().x, Scene::CenterF().y, 20.0);
	clayPipe = std::make_shared<ClayPipe>(Rect(800, 0, 70, 300), Palette::Green);
	setState(std::make_shared<Playing>(bird, clayPipe));
}

void GameContext::gameOver()
{
	setState(std::make_shared<GameOver>());
	bird.reset();
	clayPipe.reset();
}

void GameContext::BackToTitle()
{
	setState(std::make_shared<BeforePlaying>());
	bird.reset();
	clayPipe.reset();
}

void GameContext::exec()
{
	currentState->exec();
}

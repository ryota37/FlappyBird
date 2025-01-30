# include <Siv3D.hpp>
# include <memory>
# include "Bird.h"
# include "GameState.cpp"
# include "ClayPipe.cpp"

void Main()
{
	// Window setting
	Window::Resize(800, 600);

	// Instantiation
	Bird bird{ Scene::CenterF().x, Scene::CenterF().y, 20.0 };
	ClayPipe clayPipe;

	GameContext game;

	// MainLoop
	while (System::Update())
	{
		if (KeySpace.down())
		{
			game.startGame();
		}
		if (bird.collide())
		{
			game.gameOver();
		}

		game.exec();

		// Rendering of the claypipe
		clayPipe.update();
		clayPipe.draw();
		// Rendering of the bird
		bird.update();
		bird.draw();
		// Send collide info to ManageGameState::switchGameState()

		// Send the information that the bird passes the claypipe to not-yet desined class(DisplayCount?)

		// The game over screen shown when the bird died

	}
}

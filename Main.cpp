# include <Siv3D.hpp>
# include <memory>
# include "Bird.h"
# include "GameState.cpp"
# include "ClayPipe.cpp"

void Main()
{
	// Window setting
	Window::Resize(800, 600);

	// Instaniaton of context class
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

	}
}

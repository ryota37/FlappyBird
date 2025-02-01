# include <Siv3D.hpp>
# include <memory>
# include "Bird.h"
# include "GameState.cpp"
# include "ClayPipe.h"

void Main()
{
	// Instaniaton of context class
	GameContext game;

	// MainLoop
	while (System::Update())
	{
		if (KeySpace.down())
		{
			game.startGame();
		}
		if (game.bird && game.bird->collide())
		{
			game.gameOver();
		}

		game.exec();

	}
}

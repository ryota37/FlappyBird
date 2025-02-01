# include <Siv3D.hpp>
# include <memory>
# include "Bird.h"
# include "ClayPipe.h"

// Instantiation

class GameState
{
public:
	virtual void exec() = 0;
	virtual ~GameState() = default;
};

class BeforePlaying : public GameState
{
public:
	void exec() override
	{
		// The title screen shown before playing the game.

		// temporary code
		Print << U"Title Screen";
	}
};

class Playing : public GameState
{
private:
	Bird& bird;
	ClayPipe& clayPipe;

public:
	Playing(Bird& bird, ClayPipe& clayPipe) : bird(bird), clayPipe(clayPipe) {};

	void exec() override
	{
		// Rendering of the claypipe
		clayPipe.update();
		clayPipe.draw();
		// Rendering of the bird
		bird.update();
		bird.draw();

		// temporary code
		Print << U"Playing";
	}
};

class GameOver : public GameState
{
public:
	void exec() override
	{
		// The title screen shown before playing the game.

		// temporary code
		Print << U"GameOver";
	}
};

class GameContext
{
private:
	std::shared_ptr<GameState> currentState;

	void setState(std::shared_ptr<GameState> state)
	{
		currentState = state;
	}

public:
	std::unique_ptr<Bird> bird;
	std::unique_ptr<ClayPipe> clayPipe;

	// Initial state is BeforePlaying
	GameContext() : currentState(std::make_shared<BeforePlaying>()) {}

	// Functions to switch game state
	void startGame()
	{
		bird = std::make_unique<Bird>(Scene::CenterF().x, Scene::CenterF().y, 20.0);
		clayPipe = std::make_unique<ClayPipe>(Rect(800, 0, 70, 300), Palette::Green);
		setState(std::make_shared<Playing>(*bird, *clayPipe));
	}
	void gameOver()
	{
		setState(std::make_shared<GameOver>());
		bird.reset();
		clayPipe.reset();
	}
	void BackToTitle()
	{
		setState(std::make_shared<BeforePlaying>());
		bird.reset();
		clayPipe.reset();
	}

	// The code in exec() is executed in the main loop
	void exec()
	{
		currentState->exec();
	}
};

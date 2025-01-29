# include <Siv3D.hpp>
# include <memory>

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
public:
	void exec() override
	{
		// The title screen shown before playing the game.

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

	// Initial state is BeforePlaying
	GameContext() : currentState(std::make_shared<BeforePlaying>()) {}

	// Functions to switch game state
	void startGame()
	{
		setState(std::make_shared<Playing>());
	}
	void gameOver()
	{
		setState(std::make_shared<GameOver>());
	}
	void BackToTitle()
	{
		setState(std::make_shared<BeforePlaying>());
	}

	// The code in exec() is executed in the main loop
	void exec()
	{
		currentState->exec();
	}
};

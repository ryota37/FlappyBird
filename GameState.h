#pragma once
#include <Siv3D.hpp>
#include <memory>
#include "Bird.h"
#include "ClayPipe.h"

class GameState {
public:
	virtual void exec() = 0;
	virtual ~GameState() = default;
};

class BeforePlaying : public GameState {
public:
	void exec() override;
};

class Playing : public GameState {
private:
	std::shared_ptr<Bird> bird;
	std::shared_ptr<ClayPipe> clayPipe;
public:
	Playing(const std::shared_ptr<Bird>& bird, const std::shared_ptr<ClayPipe>& clayPipe);
	void exec() override;
};

class GameOver : public GameState {
public:
	void exec() override;
};

class GameContext {
private:
	std::shared_ptr<GameState> currentState;
	void setState(std::shared_ptr<GameState> state);

public:
	std::shared_ptr<Bird> bird;
	std::shared_ptr<ClayPipe> clayPipe;

	GameContext();
	void startGame();
	void gameOver();
	void BackToTitle();
	void exec();
};

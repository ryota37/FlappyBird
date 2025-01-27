# include <Siv3D.hpp>

class ManageGameState
{
private:
	enum class GameState gamestate;
public:
	GameState getGameState();
	void setGameState(GameState gamestate);
	GameState switchGameMode();
};

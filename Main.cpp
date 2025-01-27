# include <Siv3D.hpp>
# include "Bird.h"

void Main()
{
	// Window setting
	Window::Resize(800, 600);

	// Define colored rect
	struct ColoredRect
	{
		Rect rect;
		ColorF color;

		void draw() const
		{
			rect.draw(color);
		}
	};

	// Instaniate the claypipe
	ColoredRect clayPipe{Rect(800,0,70,300), Palette::Green };

	// Instantiate the bird
	Bird bird{ Scene::CenterF().x, Scene::CenterF().y, 20.0 };

	// MainLoop
	while (System::Update())
	{

		// Update position of the claypipe
		// The code below should be extracted to Claypipe class.
		clayPipe.rect.x -= (Scene::DeltaTime() * 20);
		if (clayPipe.rect.x == 0)
		{
			clayPipe.rect.x = 800;
		}


		// Switch the code to execute depending on the GameState.
		// NOTE: wanna implement with the strategy pattern


		// The title screen shown before playing the game.

		// The process that carried out during the game play

			// Rendering of the claypipe
			clayPipe.draw();
			// Rendering of the bird
			bird.update();
			bird.draw();
			// Send collide info to ManageGameState::switchGameState()

			// Send the information that the bird passes the claypipe to not-yet desined class(DisplayCount?)


		// The game over screen shown when the bird died

	}
}

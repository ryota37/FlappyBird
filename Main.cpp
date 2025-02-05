# include <Siv3D.hpp>
# include "Bird.h"

void Main()
{
	// Font information
	const Font minifont{ FontMethod::MSDF, 24, Typeface::Bold };

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

	// ManageGameOver
	bool isGameOver = false;

	// MainLoop
	while (System::Update())
	{

		if (!isGameOver)
		{
			// Update position of the claypipe
			clayPipe.rect.x -= (Scene::DeltaTime() * 20);
			if (clayPipe.rect.x == 0)
			{
				clayPipe.rect.x = 800;
			}

			// Rendering of the claypipe
			clayPipe.draw();
			// Rendering of the bird
			bird.update();
			bird.draw();

			// The game over screen shown when the bird died
			if (bird.collide())
			{
				isGameOver = true;
			}
			if (bird.intersects(clayPipe.rect))
			{
				isGameOver = true;
			}
		}
		else
		{
			minifont(U"GameOver!").drawAt(Scene::Center());
			if (KeyEnter.pressed())
			{
				clayPipe = { Rect(800,0,70,300), Palette::Green };
				bird = { Scene::CenterF().x, Scene::CenterF().y, 20.0 };
				isGameOver = false;
			}
		}
	}
}

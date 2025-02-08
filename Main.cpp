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
	ColoredRect clayPipe1{ Rect(800,0,70,300), Palette::Green };
	ColoredRect clayPipe2{ Rect(500,300,70,300), Palette::Green };
	ColoredRect clayPipe3{ Rect(1100,400,70,200), Palette::Green };
	ColoredRect clayPipe4{ Rect(1100,0,70,200), Palette::Green };

	// Instantiate the bird
	Bird bird{ 200, Scene::CenterF().y, 20.0 };

	// ManageGameOver
	bool isGameOver = false;

	// MainLoop
	while (System::Update())
	{

		if (!isGameOver)
		{
			// Update position of the claypipe
			clayPipe1.rect.x -= (Scene::DeltaTime() * 20);
			if (clayPipe1.rect.x == 0)
			{
				clayPipe1.rect.x = 1100;
			}
			clayPipe2.rect.x -= (Scene::DeltaTime() * 20);
			if (clayPipe2.rect.x == 0)
			{
				clayPipe2.rect.x = 1100;
			}
			clayPipe3.rect.x -= (Scene::DeltaTime() * 20);
			if (clayPipe3.rect.x == 0)
			{
				clayPipe3.rect.x = 1100;
			}
			clayPipe4.rect.x -= (Scene::DeltaTime() * 20);
			if (clayPipe4.rect.x == 0)
			{
				clayPipe4.rect.x = 1100;
			}

			// Rendering of the claypipe
			clayPipe1.draw();
			clayPipe2.draw();
			clayPipe3.draw();
			clayPipe4.draw();
			// Rendering of the bird
			bird.update();
			bird.draw();

			// The game over screen shown when the bird died
			if (bird.collide())
			{
				isGameOver = true;
			}
			if (bird.intersects(clayPipe1.rect) || bird.intersects(clayPipe2.rect) || bird.intersects(clayPipe3.rect) || bird.intersects(clayPipe4.rect))
			{
				isGameOver = true;
			}
		}
		else
		{
			minifont(U"GameOver!").drawAt(Scene::Center());
			if (KeyEnter.pressed())
			{
				clayPipe1 = { Rect(800,0,70,300), Palette::Green };
				clayPipe2 = { Rect(500,300,70,300), Palette::Green };
				clayPipe3 = { Rect(1100,400,70,200), Palette::Green };
				clayPipe4 = { Rect(1100,0,70,200), Palette::Green };
				bird = { 200, Scene::CenterF().y, 20.0 };
				isGameOver = false;
			}
		}
	}
}

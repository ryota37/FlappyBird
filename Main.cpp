# include <Siv3D.hpp>
# include "Bird.h"

void Main()
{
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

	}
}

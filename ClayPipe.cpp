# include <Siv3D.hpp>

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

class ClayPipe : public ColoredRect
{
private:

public:
	ClayPipe(Rect rect = Rect(800, 0, 70, 300), ColorF color = Palette::Green) : ColoredRect{rect,color} {};

	void update()
	{
		// Update position of the claypipe
		rect.x -= (Scene::DeltaTime() * 20);
		if (rect.x == 0)
		{
			rect.x = 800;
		}
	}
};

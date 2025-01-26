# include <Siv3D.hpp>
# include "Bird.h"

Bird::Bird(double x, double y, double r)
	:Circle(x, y, r), gravity(100.0), velocity(3000.0), isHit(false) {}


void Bird::update()
{
	y += gravity * Scene::DeltaTime();

	if (KeySpace.down())
	{
		y -= velocity * Scene::DeltaTime();
	}
}

# include <Siv3D.hpp>
# include "ClayPipe.h"

ClayPipe::ClayPipe(s3d::Rect rect, s3d::ColorF color)
	: ColoredRect{ rect, color } {}

void ClayPipe::update()
{
	// Update position of the claypipe
	rect.x -= (Scene::DeltaTime() * 20);
	if (rect.x <= 0) rect.x = 800;
}

void ClayPipe::draw()
{
	rect.draw(color);
}

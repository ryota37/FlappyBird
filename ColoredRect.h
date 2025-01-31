#pragma once

# include <Siv3D.hpp>

struct ColoredRect
{
	Rect rect;
	ColorF color;

	void draw() const
	{
		rect.draw(color);
	}
};

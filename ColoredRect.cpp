# include "ColoredRect.h"

ColoredRect::ColoredRect(s3d::Rect rect, s3d::ColorF color)
	: rect(rect), color(color)
{
}

void ColoredRect::draw()
{
	rect.draw(color);
}

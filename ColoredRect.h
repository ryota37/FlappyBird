#pragma once
# include <Siv3D.hpp>

class ColoredRect
{
protected:
	s3d::Rect rect;
	s3d::ColorF color;

public:
	ColoredRect(s3d::Rect rect, s3d::ColorF color);
	virtual void draw();
};

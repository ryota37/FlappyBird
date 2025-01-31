# pragma once

# include <Siv3D.hpp>
# include "ColoredRect.h"

class ClayPipe : public ColoredRect
{
private:

public:
	ClayPipe(Rect rect, ColorF color);
	void update();
};

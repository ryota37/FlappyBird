#ifndef CLAYPIPE_H
#define CLAYPIPE_H

# include <Siv3D.hpp>
# include "ColoredRect.h"

class ClayPipe : public ColoredRect
{
private:

public:
	ClayPipe(s3d::Rect rect, s3d::ColorF color);
	void update();
	void draw();
};

#endif // CLAYPIPE_H

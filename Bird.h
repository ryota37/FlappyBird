# include <Siv3D.hpp>

class Bird : public Circle
{
private:
	double gravity;
	double velocity;

public:
	Bird(double x, double y, double r);
	void update();
	bool collide();
	void beyond();
};

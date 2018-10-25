#include "Point.h"
void Point::setx(float x)
{
	x_ = x;
}
void Point::sety(float y)
{
	y_ = y;
}
void Point::setxy(float x, float y)
{
	x_ = x;
	y_ = y;
}
const float Point::getx()
{
	return x_;
}
const float Point::gety()
{
	return y_;
}
const void Point::show()
{
	cout << "x=" << x_;
	cout << "y=" << y_;
}
Point::Point() : x_(0), y_(0) {}
Point::Point(const Point &ob)
{
	x_ = ob.x_;
	y_ = ob.y_;
}
float Point::radius(Point ob)
{

	return sqrt((x_ - ob.x_)*(x_ - ob.x_) + (y_ - ob.y_)*(y_ - ob.y_));
}


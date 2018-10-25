#include "Rectangle.h"
Rectangle::Rectangle(Point &point, float len, float wid) // :a_(point), len_(len)
{
	a_ = Point(point);
	len_ = len;
	wid_ = wid;
}
Rectangle::Rectangle()
{
	a_ = Point();
	len_ = 0;
	wid_ = 0;
}
float Rectangle::pRectangle()
{
	return 2 * (len_ + wid_);
}
float Rectangle::sRectangle()
{
	return len_*wid_;
}

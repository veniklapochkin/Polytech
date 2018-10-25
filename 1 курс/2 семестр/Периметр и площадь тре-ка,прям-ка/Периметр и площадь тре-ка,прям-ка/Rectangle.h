#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "Triangle.h"

class Rectangle
{
	Point a_;
	float len_, wid_;
	friend int comparisonTR(Triangle ob1, Rectangle ob2);
public:
	Rectangle(Point &point, float len, float wid);
	Rectangle();
	float pRectangle();
	float sRectangle();
};
#endif
#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Point.h"
class Triangle
{
	Point a_, b_, c_;
	float lab = a_.radius(b_),
		lbc = b_.radius(c_),
		lac = a_.radius(c_);
	friend int comparisonTR(Triangle ob1, Rectangle ob2);
public:
	bool isTrianglef();
	bool isTriangle;
	Triangle();
	Triangle(Point a, Point b, Point c);
	float pTriangle();
	float sTriangle();
	const void show();
};
#endif
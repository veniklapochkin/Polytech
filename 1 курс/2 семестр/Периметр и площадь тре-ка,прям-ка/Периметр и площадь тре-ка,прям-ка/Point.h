#ifndef POINT_H
#define POINT_H
#include <iostream>
#include <cmath>
using namespace std;
class Point
{
	float x_, y_;
	friend class Triangle;
	friend class Rectangle;
public:
	void setx(float x);
	void sety(float y);
	void setxy(float x, float y);
	const float getx();
	const float gety();
	const void show();
	Point();
	Point(const Point &ob);
	float radius(Point ob);
};
#endif
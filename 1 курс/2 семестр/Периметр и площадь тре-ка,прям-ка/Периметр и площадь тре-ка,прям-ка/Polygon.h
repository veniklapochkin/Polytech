#ifndef POLYGON_H
#define POLYGON_H
#include "arrayofTriangle.h"
class Polygon
{
	int size_;
	Point *arr_ = new Point[size_]; //;
public:
	Polygon(int size, Point *point);
	Polygon();
	float pPolygon(); //
	~Polygon();
};
#endif
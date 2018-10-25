#ifndef ARRAYOFTRIANGLE_H
#define ARRAYOFTRIANGLE_H
#include "Rectangle.h"
class ArrayofTriangle
{
	int size_;
	Triangle *arr_ = new Triangle[size_];

public:
	ArrayofTriangle(int size, Triangle *triangle);
	ArrayofTriangle();
	~ArrayofTriangle();
	int minTriangle();
};
#endif
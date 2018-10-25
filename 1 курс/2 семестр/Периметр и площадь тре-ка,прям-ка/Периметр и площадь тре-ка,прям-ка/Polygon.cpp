#include "polygon.h"
Polygon::Polygon(int size, Point *point)
{
	size_ = size; //
	arr_ = point;
	for (int i = 0; i < size; i++)
		arr_[i] = point[i];
}
Polygon::Polygon()
{
	size_ = 0;
	arr_ = 0;
}
float Polygon::pPolygon()
{
	float ans;
	ans = arr_[0].radius(arr_[size_ - 1]);
	for (int i = 1; i < size_; i++)
		ans += arr_[i - 1].radius(arr_[i]);
	return ans;
}
Polygon::~Polygon()
{
	delete[] arr_;
}
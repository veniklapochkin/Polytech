#include "ArrayofTriangle.h"
ArrayofTriangle::ArrayofTriangle(int size, Triangle *triangle)
{
	size_ = size;
	arr_ = triangle;
	for (int i = 0; i < size; i++)
		arr_[i] = triangle[i];
}
ArrayofTriangle::ArrayofTriangle()
{
	size_ = 0;
	arr_ = 0;
}
int ArrayofTriangle::minTriangle()
{
	int ans = 0, i;
	float min;
	for (i = 0; (i < size_) && (arr_[i].isTriangle == false); i++)
	if (i == size_) return -1;
	min = arr_[i].sTriangle();
	for (int i = 1; i < size_; i++)
	{
		if (arr_[i].isTriangle)
		{
			float sNow = arr_[i].sTriangle();
			if (sNow < min)
			{
				min = sNow;
				ans = i;
			}
		}
	}
	return ans;
}
ArrayofTriangle::~ArrayofTriangle()
{
	delete[] arr_;
}

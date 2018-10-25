#include <iostream>
using namespace std;
class Point
{
	float x_, y_;
public:
	Point(float x, float y);
	Point();
	void setx(float x);
	void sety(float y);
	void setxy(float x, float y);
	float getx() const;
	float gety() const;
	void show() const;
};
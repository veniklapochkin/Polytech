#include <iostream>
#include "Point.h"
using namespace std;
Point::Point(float x, float y){
	x_ = x;
	y_ = y;
}
Point::Point(){
	x_ = 0;
	y_ = 0;
}
void Point::setx(float x){
	x_ = x;
}
void Point::sety(float y){
	y_ = y;
}
void Point::setxy(float x, float y){
	x_ = x;
	y_ = y;
}
float Point::getx()const{
	return x_;
}
float Point::gety()const{
	return y_;
}
void Point::show()const{
	setlocale(0, "");
	cout << "Вывод точки: x_  " << x_ << ", y_ " << y_ << endl;
}
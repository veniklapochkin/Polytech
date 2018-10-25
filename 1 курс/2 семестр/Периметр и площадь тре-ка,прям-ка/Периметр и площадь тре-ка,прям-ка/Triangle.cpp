#include "Triangle.h"
bool Triangle::isTrianglef()
{
	return sqrt((lab + lac > lbc) && (lab + lbc > lac) && (lbc + lac > lab));
}
Triangle::Triangle(Point a, Point b, Point c)
{
	a_ = a;
	b_ = b;
	c_ = c;
	lab = a_.radius(b_),
		lbc = b_.radius(c_),
		lac = a_.radius(c_);
	isTriangle = isTrianglef();
}
Triangle::Triangle()
{
	a_ = Point();
	b_ = Point();
	c_ = Point();
	lab = a_.radius(b_),
		lbc = b_.radius(c_),
		lac = a_.radius(c_);
	isTriangle = isTrianglef();
}
float Triangle::pTriangle()
{
	return lab + lbc + lac;
}
float Triangle::sTriangle()
{
	float d = (lab + lbc + lac) / 2;
	return sqrt(d*(d - lab)*(d - lbc)*(d - lac));
}
const void Triangle::show()
{
	cout << "lab=" << lab << "\n";
	cout << "lbc=" << lbc << "\n";
	cout << "lac=" << lac << "\n";
}
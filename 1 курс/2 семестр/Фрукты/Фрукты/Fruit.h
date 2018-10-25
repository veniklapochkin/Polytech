#include <iostream>
#include <string.h>
#include <sstream>
using namespace std;
class Fruit
{
protected:
	double weight_;
	int calory_;
	string color_;
public:
	Fruit();
	Fruit(double weight, int calory, string color);
	Fruit(Fruit &ob);
	Fruit copy(const Fruit ob);
	virtual void show();
};
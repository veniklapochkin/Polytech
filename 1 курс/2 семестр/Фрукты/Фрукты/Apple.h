#ifndef Header
#include "Fruit.h"
#define Header
#endif
class Apple : public Fruit
{
protected:
	double v_;
public:
	Apple();
	Apple(Fruit fruit, double v);
	Apple(Apple &ob);
	void show();
};
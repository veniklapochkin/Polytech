#ifndef Header
#include "Fruit.h"
#define Header
#endif
class Banana : public Fruit
{
protected:
	double len_;
public:
	Banana();
	Banana(Fruit fruit, double len);
	Banana(Banana &ob);
	void show();
};
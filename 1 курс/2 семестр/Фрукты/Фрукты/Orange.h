#ifndef Header
#include "Fruit.h"
#define Header
#endif
class Orange : public Fruit
{
protected:
	int colPart_;
public:
	Orange();
	Orange(Fruit fruit, int colPart);
	Orange(Orange &ob);
	void show();
};
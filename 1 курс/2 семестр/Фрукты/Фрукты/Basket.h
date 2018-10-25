#include "Banana.h"
#include "Orange.h"
#include "Apple.h"
class Basket
{
	int size_;
	Fruit **fruit_;
public:
	Basket(int size);
	void setFruit(Fruit *fruit, int i);
	void showBasket();
};

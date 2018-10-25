#include "Basket.h"
Basket::Basket(int size)
{
	size_ = size;
	fruit_ = new Fruit *[size_];
};
void Basket::setFruit(Fruit *fruit, int i)
{
	fruit_[i] = fruit;
};
void Basket::showBasket()
{
	for (int i = 0; i < size_; i++)
	{
		fruit_[i]->show();
	}
};
#include "Basket.h"
const int Size = 3;
int main()
{
	setlocale(0, "");
	Fruit fruitBanana(12, 12, "желтый"),
		fruitApple(10, 10, "зеленый"),
		fruitOrange(9, 9, "оранжевый");
	Banana banana(fruitBanana, 10);
	Apple apple(fruitApple, 3);
	Orange orange(fruitOrange, 21);
	Basket basket(3);
	Fruit *p;
	p = &banana;
	basket.setFruit(p, 0);
	p = &apple;
	basket.setFruit(p, 1);
	p = &orange;
	basket.setFruit(p, 2);
	basket.showBasket();
	system ("pause");
}








#include "Banana.h"
Banana::Banana() : Fruit(), len_(0){};
Banana::Banana(Fruit fruit, double len) : Fruit(fruit), len_(len){};
Banana::Banana(Banana &ob) : Fruit(ob), len_(ob.len_){};
void Banana::show()
{
	cout << "Банан" << "\n";
	this->Fruit::show();
	cout << "Длина " << len_ << "\n";
};
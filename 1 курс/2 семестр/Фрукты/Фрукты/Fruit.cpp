#include "fruit.h"
Fruit::Fruit() : weight_(5), calory_(5), color_("white"){};
Fruit::Fruit(double weight, int calory, string color) : weight_(weight), calory_(calory), color_(color){};
Fruit::Fruit(Fruit &ob) : weight_(ob.weight_), calory_(ob.calory_), color_(ob.color_){};
void Fruit::show()
{
	cout << "Вес " << weight_ << "\n";
	cout << "Калории " << calory_ << "\n";
	cout << "Цвет " << color_ << "\n";
};
Fruit Fruit::copy(const Fruit ob)
{
	weight_ = ob.weight_;
	calory_ = ob.calory_;
	color_ = ob.color_;
	return *this;
};

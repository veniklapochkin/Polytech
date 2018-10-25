#include "apple.h"
Apple::Apple() : Fruit(), v_(0){};
Apple::Apple(Fruit fruit, double v) : Fruit(fruit), v_(v){};
Apple::Apple(Apple &ob) : Fruit(ob), v_(ob.v_){};
void Apple::show()
{
	cout << "ßáëîêî" << "\n";
	this->Fruit::show();
	cout << "Îáú¸ì " << v_ << "\n";
};
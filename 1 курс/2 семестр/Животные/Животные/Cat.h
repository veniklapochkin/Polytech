#ifndef Header
#include "Animal.h"
#define Header
class Cat : virtual public Animal
{
	int age_;
public:
	Cat(string name, int age) : Animal(name), age_(age){};
	void say(){ cout << "Ìÿó \n"; }
};
#endif
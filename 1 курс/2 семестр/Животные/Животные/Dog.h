#ifndef Header
#include "Animal.h"
#define Header
#endif
class Dog : virtual public Animal
{
	float weight_;
public:
	Dog(string name, float weight) : Animal(name), weight_(weight){};
	void say(){ cout << "Ãàâ \n"; }
};

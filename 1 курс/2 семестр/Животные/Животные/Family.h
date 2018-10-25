#include "Cat.h"
#include "Dog.h"
class Family
{
	int size_;
	Animal **animal_;
public:
	Family(int size);
	void setAnimal(Animal *animal, int i);
	void say();
};
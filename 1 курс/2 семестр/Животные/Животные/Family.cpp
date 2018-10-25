#include "Family.h"
Family::Family(int size)
{
	size_ = size;
	animal_ = new Animal *[size_];
};
void Family::setAnimal(Animal *animal, int i)
{
	animal_[i] = animal;
};
void Family::say()
{
	for (int i = 0; i < size_; i++)
		animal_[i]->say();
};
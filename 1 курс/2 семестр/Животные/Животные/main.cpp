#include "Family.h"
int main()
{
	setlocale(0, "");
	Animal *p;
	Cat cat("Мурзик", 3);
	Dog dog("Шарик", 4);
	Family family(2);
	p = &cat;
	family.setAnimal(p, 0);
	p = &dog;
	family.setAnimal(p, 1);
	family.say();
	system("pause");
}
//Функция определения длинны строки
#include "header.h"
int length(const char *c)
{
	int i;
	for (i=0; c[i]!=0; i++);
	return i;
}
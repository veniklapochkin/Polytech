//Функция копирования строки
#include "header.h"
void copy(char *c, char *c1, int l, int r)
{
	int i;
	for (i=l; i<=r; i++)
		c1[i-l]=c[i];
	c1[i-l]=0;
}
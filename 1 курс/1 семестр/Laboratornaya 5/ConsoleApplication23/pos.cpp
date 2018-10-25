//Функция поиска элемента в строке
#include "header.h"
int pos(char s, char *c)
{
	int i;
	for (i=0; c[i]!=0; i++)
		if (c[i]==s) return i;
	return -1;
}
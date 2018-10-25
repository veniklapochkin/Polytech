//Определение вещественного числа
#include "header.h"
bool real(char *c, char *c2)
{
	int q=pos('E', c);
	if (q==-1) return mantissa(c, c2);
	char c1[N];
	int i;
	i=length(c);
	int j=i-1;
	i=0;
	if (sign(c[i])==1) i++;
	copy(c, c1, i, q-1);
	if (mantissa(c1, c2)==1) 
	{
		copy(c, c1, q, j);
		return order(c1, c2);
	}
	return 0;
}
//Определение порядка
#include "header.h"
bool order(char *c, char *c2)
{
	int i=0, 
		j;
	char c1[N];
	if (c[i]!='E') return 0;
	i++;
	int q=length(c2);
	c2[q]='E'; q++;
	if (sign(c[i])==1) {c2[q]=c[i]; q++; i++;}
	c2[q]='M'; c2[q+1]=0;
	j=length(c);
	copy(c, c1, i, j-1);
	return unSignInt(c1);
}
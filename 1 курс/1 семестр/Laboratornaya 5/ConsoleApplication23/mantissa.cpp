//Определение мантиссы
#include "header.h"
bool mantissa(char *c, char *c2)
{
	int q=pos('.', c),
		i;
	if (q==-1) {c2[0]='M'; c2[1]=0; return unSignInt(c);}
	i=length(c);
	char c1[N];
	copy(c, c1, 1, i-1);
	if (q==0) 
		{c2[0]='.'; c2[1]='M'; c2[2]=0; return unSignInt(c1);}
	{
		copy(c, c1, 0, q-1);
		if (unSignInt(c1)==1)
		{
			copy(c, c1, q+1, i-1);
			c2[0]='M'; c2[1]='.'; c2[2]='M'; c2[3]=0;
			return (unSignInt(c1));
		}
		return 0;
	}
}
		
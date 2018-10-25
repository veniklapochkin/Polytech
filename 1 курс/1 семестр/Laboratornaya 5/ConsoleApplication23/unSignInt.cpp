//Определение целого без знака
#include"header.h"
bool unSignInt(char *c)
{
	int i;
	i=length(c);
	if (digital(c[0])==1)
	{
		if (c[1]==0) return 1;
		char c1[N];
		copy(c, c1, 1, i-1);
		return(unSignInt(c1));
	}
	else return 0;
}

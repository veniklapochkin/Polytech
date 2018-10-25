//Сравнение строк
#include "header.h"
int comString(char *s1, char *s2, const int n)
{
	int f=-2, 
		i=0;
	while ((f==-2) && (i<TARIF)) 
	{
			if (s1[i]==s2[i])
				if (s1[i]==0) f=0;
				else i++;
			else
				if (s1[i]<s2[i])
					f=-1;
				else
					f=1;
	}
	return f;
}
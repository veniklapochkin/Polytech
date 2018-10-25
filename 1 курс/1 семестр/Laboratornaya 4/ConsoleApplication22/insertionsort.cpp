//Сортировка вставками
#include "header.h"
int comString(char *s1, char *s2, const int n);
void insertionSort(Abonent *a, const int n)
{
	for (int i=1; i<n; i++) 
	{
		int f=0;
		for (int j=i-1; (f==0) && (j>=0); j--)
		{
			if (comString(a[j+1].tarif, a[j].tarif,n)<0)
			{
				Abonent x=a[j+1]; a[j+1]=a[j]; a[j]=x; 
			}
			else f=1;
		}
	}
}
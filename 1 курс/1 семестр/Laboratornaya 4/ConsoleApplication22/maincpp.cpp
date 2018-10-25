#include "header.h"
void inputf(Abonent *a, const int n);
void insertionSort(Abonent *a, const int n);
int comString(char *s1, char *s2, const int n);
void outputf(Abonent *a, const int n);
void de(Abonent *a, const int n);
int main()
{
	const int n = 10;
	Abonent abonent[n];
	inputf(abonent,n);
	insertionSort(abonent,n);
	outputf(abonent,n);
	de(abonent,n);
	return 0;	 
}
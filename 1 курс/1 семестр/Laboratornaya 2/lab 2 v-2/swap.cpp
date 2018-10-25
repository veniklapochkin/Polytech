#include <iostream>
using namespace std;
void swap(int *a, int n)
{
	int i = 0, j = n-1, k;
	goto cycle;
	while (i < j)
	{
		k = (a)[j];
		(a)[j] = (a)[i];
		(a)[i] = k;
		cycle:
		while ((a)[i] < 0)
			i++;
		while ((a)[j] >= 0)
			j--;
	}
	return;
}
#include <iostream>
using namespace std;
int PrimeNumbers(int *a, int n)
{
	int k = 0; //k - кол-во простых чисел
	bool b;
	for (int i = 0; i < n; i++)
		if ((a)[i] > 1)
		{
			b = false; 
			int sqi = sqrt((a)[i]);
			for (int j = 2; j <= sqi; j++)
				if ((a)[i] % j == 0)
				{
					b = true;
					break;
				}
			if (b == false)	
				k++;
		}
	return k;
}
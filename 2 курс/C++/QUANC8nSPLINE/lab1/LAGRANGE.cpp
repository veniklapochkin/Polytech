#include "LAGRANGE.h"

double lagrange(int n,double* x, double* y, double _x)
{
	double result = 0.0;

	for (int i = 0; i < n; i++)
	{
		double P = 1.0;

		for (int j = 0; j < n; j++)
		if (j != i)
			P *= (_x - x[j]) / (x[i] - x[j]);

		result += P * y[i];
	}

	return result;
}
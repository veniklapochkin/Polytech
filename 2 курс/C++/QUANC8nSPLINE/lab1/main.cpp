#include <math.h>
#include "cmath.h"
#include <iostream>
#define ndim 9
#define size 8
double x;
double Quanc8[ndim] = { 0 };
double Xk[ndim] = { 1 };
double ResultLagrange[size] = { 0 };
double Seval[ndim];
// Полином Лагранжа
double Lagrange(double x){
	double Qm = 0, wkx[ndim] = {1, 1, 1, 1, 1, 1, 1, 1, 1}, wkk[ndim] = { 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	int i, j;
	for (i = 0; i<ndim; i++)
	for (j = 0; j<ndim; j++)
	if (i != j)
		wkx[i] *= (x - Xk[j]);

	for (i = 0; i<ndim; i++)
	for (j = 0; j<ndim; j++)
	if (i != j)
		wkk[i] *= Xk[i] - Xk[j];

	for (i = 0; i<ndim; i++)
	if (wkk[i] != 0)
		Qm += (wkx[i] / wkk[i])*Quanc8[i];
	return Qm;
}
// Результат Лагранжа 8-й степени для xk = 1,125 + 0,25k.
void ResultLagrangeInit(){
	x = 1.125;
	for (int i = 0; i<size; i++){
		ResultLagrange[i] = Lagrange(x + i*0.25);

	}
}


// Вычисление интеграла с помощью QUANC8 с шагом 0,25
void QUANC8(double xx, int k)
{

	double f(double z);
	double a, b, abserr, relerr, result, errest, posn;
	int    nfe, flag, i;
	x = xx;
	a = 0.0;
	b = 1;
	relerr = 1.0e-10;
	abserr = 0.0;


	for (int i = 0; i<k; i++){
		quanc8(f, a, b, abserr, relerr, &result, &errest,
			&nfe, &posn, &flag);
		Quanc8[i] = result;
		Xk[i] = x;
		x = x + 0.25;
	}
}

// Функция
double f(double z)

{
	return 1 / (exp(pow(z, 2)) + pow(x, 2));
}
// Функция Spline для xk = 1,125 + 0,25k вычисления с шагом 0,25
void Spline(){
	double b[ndim], c[ndim], d[ndim];
	int    n, i, last, flag;
	n = 9;
	spline(n, 1, 1, 1.0, exp(1.0), Xk, Quanc8, b, c, d, &flag);
	if (flag == 0)
	{
		last = 0;
		x = 1.125;
		for (i = 0; i<size; i++){
			Seval[i] = seval(n, x + i*0.25, Xk, Quanc8, b, c, d, &last);

		}
	}
}

int main(){
	QUANC8(1, 9);
	ResultLagrangeInit();
	Spline();
	QUANC8(1.125, 8);
	x = 1.125;
	printf("\n     x           Seval      Lagrange   Quanc8\n");
	printf("_________________________________________________\n");
	for (int i = 0; i<size; i++)
	printf("%10.5f  %10.5f   %10.5f %10.5f\n\n", x + i*0.25, Seval[i], ResultLagrange[i], Quanc8[i]);
	printf("_________________________________________________\n");
	system("pause");
}

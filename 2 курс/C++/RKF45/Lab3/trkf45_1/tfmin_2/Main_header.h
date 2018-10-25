// Main_header.h
/*		�����-������������� ��������������� ��������������� �����������
						��������� ����������� �����������
					������� ���������� � �������������� �������


		�������� ������ �� ����� "�������������� ����������" �� 4 �������.
									������� � 38

		�����: ������� ����. ������ 2081/2

	����� ������ ��� ����������� �������, ������������ � �������. �������� ������������
	������� �������.

*/
#ifndef Main_header_h
#define Main_header_h
#define _USE_MATH_DEFINES


//#include "cmath\cmath.h"
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <iostream>
#include <fstream>
//#include "Forsythe_files\Forsythe.h"

using namespace std;

#define INDX(i, j)  (i) * n + (j)
#define mdim 10

// �������, ������������ ��� ������ �������� ��������� C
double FMINfunc(double C2);

// ��������� ��� ������� ��������� � ����������� ��������� 
double Lfunc(double x);

// �������, �������� ��� ����������� ��������� E2 ����
double E1func(double x);

// �������, ���������� ��� RKF45
void RKFfunc(double n, double t, double *y, double *yp);

// ������� ��� ������ ����� �������� �������� ������� �� ����� ����������
double fmin(double beg, double end,double (*f) (double x), double Tol,double& Error, int& flag);


#endif
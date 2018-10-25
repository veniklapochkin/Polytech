// Main_header.h
/*		Санкт-Петербургский Государственный Политехнический Университет
						Факультет технической Кибернетики
					Кафедра Автоматики и Вычислительной Техники


		Курсовой проект по курсу "Вычислительная математика" за 4 семестр.
									Вариант № 38

		Автор: Ненашев Олег. Группа 2081/2

	Хидер служит для подключения хидеров, используемых в проекте. Содержит определители
	функций проекта.

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

// Функция, используемая при оценке значения параметра C
double FMINfunc(double C2);

// Уравнение для решения уравнения и определения параметра 
double Lfunc(double x);

// Функция, заданная для определения параметра E2 цепи
double E1func(double x);

// Функция, задаваемая для RKF45
void RKFfunc(double n, double t, double *y, double *yp);

// Функция для поиска точки минимума заданной функции от одной переменной
double fmin(double beg, double end,double (*f) (double x), double Tol,double& Error, int& flag);


#endif
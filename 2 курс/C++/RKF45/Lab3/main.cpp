#include <iostream>
#include <math.h>
#include "trkf45_1/rkf45.h"
using namespace std;

//Функция, в которую записана система диффуров
void func (float t1,  float *y1, float *dy1) {
    dy1[0]= -45*y1[0] + 60*y1[1] + sin(t1 + 1);
	dy1[1]= 70*y1[0] - 110*y1[1] + cos(1-t1) + t1 + 1;
	return;
}

int main() {
	//решение через rkf45
	cout << "------------------------------------"<< endl;
	cout << "rkf45" << endl;
	int N = 2; //кол-во уравнений
	int iwork[30]; //рабочий массив
	float work[15]; //рабочий массив
	float Y0[2] = {5, -1};	//вектор решений
    float T0 = 0; //начальная точка входа
    float RE = 0.0001; //погрешность
	float AE = 0.0001; //погрешность
	int iflag = 1; //проверка корректности ответа
	float tout = 0; // точка входа
	float h = 0.05; // шаг 
	for ( int i = 0; i < 20; i++ ) {
		RKF45(func, N, Y0, &T0, &tout, &RE, &AE, &iflag, work, iwork);
		cout << "\tt="<<T0<<"\tY0[0]="  << Y0[0] <<"\t\t" <<"Y0[1]="<< Y0[1] <<"\t\t" << "iflag="<< iflag << endl;		           
		tout += h;
	}	 
	cout << "------------------------------------"<< endl;
	cout << "Runge-Kutta, h = 0.025"<< endl;
	//решение Рунге-Куттой с шагом 0.025
	float z[2] = {5, -1};
	float t = 0, tTemp;
	h = 0.025;
	float k1[2], k2[2], k3[2], k4[2], dy[2], zTemp[2];
	for ( int i = 0; i < 40; i++ ) {
		//Нахождение k1
		func(t, z, dy);
		k1[0] = h*dy[0];
		k1[1] = h*dy[1];
		//Нахождение k2
		tTemp = t + h/2;
		zTemp[0] = z[0] + k1[0]/2;
		zTemp[1] = z[1] + k1[1]/2;
		func(tTemp, zTemp, dy);
		k2[0] = h*dy[0];
		k2[1] = h*dy[1];
		//Нахождение k3
		tTemp = t + h/2;
		zTemp[0] = z[0] + k1[0]/4 + k2[0]/4;
		zTemp[1] = z[1] + k1[1]/4 + k2[1]/4;
		func(tTemp, zTemp, dy);
		k3[0] = h*dy[0];
		k3[1] = h*dy[1];
		//Нахождение k4
		tTemp = t + h;
		zTemp[0] = z[0] - k2[0] + 2*k3[0];
		zTemp[1] = z[1] - k2[1] + 2*k3[1];
		func(tTemp, zTemp, dy);
		k4[0] = h*dy[0];
		k4[1] = h*dy[1];
		//Нахождение решения на i-ом шаге
		t += h;
		z[0] += (k1[0] + 4*k3[0] + k4[0])/6;
		z[1] += (k1[1] + 4*k3[1] + k4[1])/6;
		if (i % 2 == 0)
		  cout <<"\tt="<<t<< "\tz[0]="  << z[0] <<"\t\t" <<"\tz[1]="<< z[1] <<"\t\t" << endl;		           
	}
	//решение Рунге-Куттой с шагом 0.01
	cout << "------------------------------"<< endl;
	cout << "Runge-Kutta, h = 0.01"<< endl;
	z[0] = 5; z[1] = -1;
	t = 0;
	h = 0.01;
	for ( int i = 0; i < 100; i++ ) {
		//Нахождение k1
		func(t, z, dy);
		k1[0] = h*dy[0];
		k1[1] = h*dy[1];
		//Нахождение k2
		tTemp = t + h/2;
		zTemp[0] = z[0] + k1[0]/2;
		zTemp[1] = z[1] + k1[1]/2;
		func(tTemp, zTemp, dy);
		k2[0] = h*dy[0];
		k2[1] = h*dy[1];
		//Нахождение k3
		tTemp = t + h/2;
		zTemp[0] = z[0] + k1[0]/4 + k2[0]/4;
		zTemp[1] = z[1] + k1[1]/4 + k2[1]/4;
		func(tTemp, zTemp, dy);
		k3[0] = h*dy[0];
		k3[1] = h*dy[1];
		//Нахождение k4
		tTemp = t + h;
		zTemp[0] = z[0] - k2[0] + 2*k3[0];
		zTemp[1] = z[1] - k2[1] + 2*k3[1];
		func(tTemp, zTemp, dy);
		k4[0] = h*dy[0];
		k4[1] = h*dy[1];
		//Нахождение решения на i-ом шаге
		t += h;
		z[0] += (k1[0] + 4*k3[0] + k4[0])/6;
		z[1] += (k1[1] + 4*k3[1] + k4[1])/6;
		if (i % 4 == 0)
		  cout << "\tt="<<t<<"\tz[0]="  << z[0] <<"\t\t" <<"\tz[1]="<< z[1] <<"\t\t" << endl;		           
	}
	system("pause");
}
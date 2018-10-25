// тестовая программа trkf45_1
//интегрирование сду, описывающей две интегрирующие цепочки,  
//включенные последовательно с постоянными Т=1сек
// вход - единичный перепад,переменые состояния - напряжения на
//конденсаторах
#include "rkf45.h"
#include <math.h>
#include <iostream>
using namespace std;

void MyFunc(float t,  float *y, float *dy)
{
	
	//dy[0]=y[1];
	//dy[1]=((t+1)*y[1])/t+(2*(t-1)*y[0])/t;
    dy[0]=998.0*y[0]+1998*y[1];
	dy[1]=-999.0*y[0]-1999.0*y[1];
	return;
}


void main()
{
	int Negn = 2;
	int iwork[ 30 ];
	float work[ 15 ];
	float Y0[ ]={1.0,1.0};	
    float T0 = 0.0;
    float RE = 1e-8;
	float AE = 1e-10;
	int iflag = 1;
	float tout = 0.0;
	float h=0.004
;
	
	for (  int i = 0; i <= 500; i++ )
	{
	//int iflag = 1;
		RKF45(MyFunc, Negn, Y0, &T0, &tout, &RE, &AE, &iflag, work, iwork);
	
		//cout << "\tY0[0]\t" << "\t" <<"\tY0[1]\t" << endl;
		//cout << "\t" << Y0[0] << "\t\t\t" << Y0[1]<< endl;
		cout << "\tY0[0]="  << Y0[0] <<"\t\t" <<"Y0[1]="<< Y0[1] <<"\t\t" << "iflag="<< iflag << endl;
		           
		tout += h;
	}	        
	     }


